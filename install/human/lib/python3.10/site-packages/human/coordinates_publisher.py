'''
整合了client和server的功能
'''

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from geometry_msgs.msg import Point
from myinterfaces.srv import Humancoordinates
from myinterfaces.msg import DetectCoordinates
import torch
import pandas as np
import random
from .utils.torch_utils import select_device, load_classifier, time_sync
from .utils.general import (
    check_img_size, non_max_suppression, apply_classifier, scale_coords,
    xyxy2xywh, strip_optimizer, set_logging)
from .utils.datasets import LoadStreams, LoadImages, letterbox
from .models.experimental import attempt_load
import torch.backends.cudnn as cudnn
import math
from ament_index_python.packages import get_package_share_directory
import yaml
import argparse
import os
import time
import numpy as np
import cv2
from cv_bridge import CvBridge
from message_filters import ApproximateTimeSynchronizer,Subscriber

# 配置
package_share_directory = get_package_share_directory('human')
class_name  =[ 'person', 'bicycle', 'car', 'motorcycle', 'airplane', 'bus', 'train', 'truck', 'boat', 'traffic light',
         'fire hydrant', 'stop sign', 'parking meter', 'bench', 'bird', 'cat', 'dog', 'horse', 'sheep', 'cow',
         'elephant', 'bear', 'zebra', 'giraffe', 'backpack', 'umbrella', 'handbag', 'tie', 'suitcase', 'frisbee',
         'skis', 'snowboard', 'sports ball', 'kite', 'baseball bat', 'baseball glove', 'skateboard', 'surfboard',
         'tennis racket', 'bottle', 'wine glass', 'cup', 'fork', 'knife', 'spoon', 'bowl', 'banana', 'apple',
         'sandwich', 'orange', 'broccoli', 'carrot', 'hot dog', 'pizza', 'donut', 'cake', 'chair', 'couch',
         'potted plant', 'bed', 'dining table', 'toilet', 'tv', 'laptop', 'mouse', 'remote', 'keyboard', 'cell phone',
         'microwave', 'oven', 'toaster', 'sink', 'refrigerator', 'book', 'clock', 'vase', 'scissors', 'teddy bear',
         'hair drier', 'toothbrush' ]

class YoloV5:
    def __init__(self, yolov5_yaml_path,model_path):
        '''初始化'''
        # 载入配置文件
        with open(yolov5_yaml_path, 'r', encoding='utf-8') as f:
            self.yolov5 = yaml.load(f.read(), Loader=yaml.SafeLoader)
        # 随机生成每个类别的颜色
        self.colors = [[np.random.randint(0, 255) for _ in range(
            3)] for class_id in range(self.yolov5['class_num'])]
        # 模型初始化
        self.model_path = model_path
        self.init_model()

    @torch.no_grad()
    def init_model(self):
        '''模型初始化'''
        # 设置日志输出
        set_logging()
        # 选择计算设备
        device = select_device(self.yolov5['device'])
        # 如果是GPU则使用半精度浮点数 F16
        is_half = device.type != 'cpu'
        # 载入模型
        model = attempt_load(
            self.model_path, map_location=device)  # 载入全精度浮点数的模型
        print(f"Loading model from:{self.yolov5['weight']}")
        input_size = check_img_size(
            self.yolov5['input_size'], s=model.stride.max())  # 检查模型的尺寸
        if is_half:
            model.half()  # 将模型转换为半精度
        # 设置BenchMark，加速固定图像的尺寸的推理
        cudnn.benchmark = True  # set True to speed up constant image size inference
        # 图像缓冲区初始化
        img_torch = torch.zeros(
            (1, 3, self.yolov5['input_size'], self.yolov5['input_size']), device=device)  # init img
        # 创建模型
        # run once
        _ = model(img_torch.half()
                  if is_half else img) if device.type != 'cpu' else None
        self.is_half = is_half  # 是否开启半精度
        self.device = device  # 计算设备
        self.model = model  # Yolov5模型
        self.img_torch = img_torch  # 图像缓冲区

    def preprocessing(self, img):
        '''图像预处理'''
        # 图像缩放
        # 注: auto一定要设置为False -> 图像的宽高不同
        img_resize = letterbox(img, new_shape=(
            self.yolov5['input_size'], self.yolov5['input_size']), auto=False)[0]
        # print("img resize shape: {}".format(img_resize.shape))
        # 增加一个维度
        img_arr = np.stack([img_resize], 0)
        # 图像转换 (Convert) BGR格式转换为RGB
        # 转换为 bs x 3 x 416 x
        # 0(图像i), 1(row行), 2(列), 3(RGB三通道)
        # ---> 0, 3, 1, 2
        # BGR to RGB, to bsx3x416x416
        img_arr = img_arr[:, :, :, ::-1].transpose(0, 3, 1, 2)
        # 数值归一化
        # img_arr =  img_arr.astype(np.float32) / 255.0
        # 将数组在内存的存放地址变成连续的(一维)， 行优先
        # 将一个内存不连续存储的数组转换为内存连续存储的数组，使得运行速度更快
        # https://zhuanlan.zhihu.com/p/59767914
        img_arr = np.ascontiguousarray(img_arr)
        return img_arr

    @torch.no_grad()
    def detect(self, img, canvas=None, view_img=True):
        '''模型预测'''
        # 图像预处理
        img_resize = self.preprocessing(img)  # 图像缩放
        self.img_torch = torch.from_numpy(img_resize).to(self.device)  # 图像格式转换
        self.img_torch = self.img_torch.half(
        ) if self.is_half else self.img_torch.float()  # 格式转换 uint8-> 浮点数
        self.img_torch /= 255.0  # 图像归一化
        if self.img_torch.ndimension() == 3:
            self.img_torch = self.img_torch.unsqueeze(0)
        # 模型推理
        t1 = time_sync()
        pred = self.model(self.img_torch, augment=False)[0]
        # pred = self.model_trt(self.img_torch, augment=False)[0]
        # NMS 非极大值抑制
        pred = non_max_suppression(pred, self.yolov5['threshold']['confidence'],
                                   self.yolov5['threshold']['iou'], classes=None, agnostic=False)
        t2 = time_sync()
        # print("推理时间: inference period = {}".format(t2 - t1))
        # 获取检测结果
        det = pred[0]
        gain_whwh = torch.tensor(img.shape)[[1, 0, 1, 0]]  # [w, h, w, h]

        if view_img and canvas is None:
            canvas = np.copy(img)
        xyxy_list = []
        conf_list = []
        class_id_list = []
        if det is not None and len(det):
            # 画面中存在目标对象
            # 将坐标信息恢复到原始图像的尺寸
            det[:, :4] = scale_coords(
                img_resize.shape[2:], det[:, :4], img.shape).round()
            for *xyxy, conf, class_id in reversed(det):
                class_id = int(class_id)
                xyxy_list.append(xyxy)
                conf_list.append(conf)
                class_id_list.append(class_id)
                if view_img:
                    # 绘制矩形框与标签
                    label = '%s %.2f' % (
                        self.yolov5['class_name'][class_id], conf)
                    self.plot_one_box(
                        xyxy, canvas, label=label, color=self.colors[class_id], line_thickness=3)
        return canvas, class_id_list, xyxy_list, conf_list

    def plot_one_box(self, x, img, color=None, label=None, line_thickness=None):
        ''''绘制矩形框+标签'''
        tl = line_thickness or round(
            0.002 * (img.shape[0] + img.shape[1]) / 2) + 1  # line/font thickness
        color = color or [random.randint(0, 255) for _ in range(3)]
        c1, c2 = (int(x[0]), int(x[1])), (int(x[2]), int(x[3]))
        cv2.rectangle(img, c1, c2, color, thickness=tl, lineType=cv2.LINE_AA)
        if label:
            tf = max(tl - 1, 1)  # font thickness
            t_size = cv2.getTextSize(
                label, 0, fontScale=tl / 3, thickness=tf)[0]
            c2 = c1[0] + t_size[0], c1[1] - t_size[1] - 3
            cv2.rectangle(img, c1, c2, color, -1, cv2.LINE_AA)  # filled
            cv2.putText(img, label, (c1[0], c1[1] - 2), 0, tl / 3,
                        [225, 255, 255], thickness=tf, lineType=cv2.LINE_AA)

class Coordinates(Node):
    def __init__(self):
        super().__init__('coordinates_publisher')
        print("[INFO] YoloV5目标检测-程序启动")
        print("[INFO] 开始YoloV5模型加载")
        print(os.listdir())
        # self.model = YOLOv5(model_path='weights/yolov5s.pt',device='cuda:0')
        yolov5_yaml_path = package_share_directory + '/config/yolov5s.yaml'
        weights_path = package_share_directory+'weights/yolov5s.pt'
        self.model = YoloV5(yolov5_yaml_path="config/yolov5s.yaml",model_path=weights_path)
        self.bridge = CvBridge()
        print("[INFO] 完成YoloV5模型加载")
        self.fx = 605.9514770507812
        self.fy = 606.014892578125
        self.cx = 327.2686462402344
        self.cy = 246.6658935546875

        self.image_sub = Subscriber(self,
            Image,
            '/realsense_camera_node/sn036222070655/color/bgr/image_raw')
        self.depth_sub = Subscriber(self,
            Image,
            '/realsense_camera_node/sn036222070655/depth/u16/image_raw')
        self.ts = ApproximateTimeSynchronizer([self.image_sub,self.depth_sub],10,0.1)
        self.ts.registerCallback(self.sync_callback)
        self.image = None
        self.depth_image = None
        # self.coordinates_publisher = self.create_publisher(DetectCoordinates,"/coordinates",10)
        self.humancoordinate_publisher = self.create_publisher(Point,'/human_coordinate',10)
        self.pixel_coordinate_publisher = self.create_publisher(Point, '/human_pixel_coordinate', 10)

    def sync_callback(self,color_msg,depth_msg):

        self.image = color_msg
        self.depth_image = depth_msg
        self.handle_request()
    def handle_request(self):
        # YoloV5 目标检测
        msg = DetectCoordinates()
        print(type(msg))
        human_msg = Point()
        msg.detection = False
        color_image = self.image
        depth_frame = self.depth_image

        img_data = np.frombuffer(color_image.data, dtype = np.uint8)
        cv_image = img_data.reshape((480, 640, 3))

        img_data = np.frombuffer(depth_frame.data,dtype=np.uint16)
        depth_image = img_data.reshape((480,640))
        

        depth_frame = np.array(depth_image,dtype=np.float32)*0.001


        canvas, class_id_list, xyxy_list, conf_list = self.model.detect(
            cv_image)
        
        if xyxy_list:
            msg.detection = True
            for i in range(len(xyxy_list)):
                
                temp_point = Point()
                temp_name = class_name[class_id_list[i]]
                ux = int((xyxy_list[i][0]+xyxy_list[i][2])/2)  # 计算像素坐标系的x
                uy = int((xyxy_list[i][1]+xyxy_list[i][3])/2)  # 计算像素坐标系的y
                z = depth_frame[uy][ux]
                x = (ux-self.cx)*z/self.fx
                y = (uy-self.cy)*z/self.fy
                camera_xyz = np.round(np.array([x,y,z]), 3)  # 转成3位小数
                camera_xyz = camera_xyz.tolist()
                temp_point.x = camera_xyz[0]
                temp_point.y = camera_xyz[1]
                temp_point.z = camera_xyz[2]
                if temp_name == 'person':
                    human_msg.x = camera_xyz[0]
                    human_msg.y = camera_xyz[1]
                    human_msg.z = camera_xyz[2]
                    self.humancoordinate_publisher.publish(human_msg)
                    
                    # 新增代码：发布像素坐标
                    pixel_msg = Point()
                    pixel_msg.x = float(ux)
                    pixel_msg.y = float(uy)
                    pixel_msg.z = 0.0  # z轴在像素坐标系中通常不使用
                    self.pixel_coordinate_publisher.publish(pixel_msg)
                    # self.get_logger().info('Publishing human pixel coordinates!')
                cv2.circle(canvas, (ux,uy), 4, (255, 255, 255), 5)#标出中心点
                cv2.putText(canvas, str(camera_xyz), (ux+20, uy+10), 0, 1,
                            [225, 255, 255], thickness=2, lineType=cv2.LINE_AA)#标出坐标
                # msg.coordinates.append(temp_point)
                # msg.name.append(temp_name)

        # cv2.namedWindow('detection', flags=cv2.WINDOW_NORMAL |
        #                 cv2.WINDOW_KEEPRATIO | cv2.WINDOW_GUI_EXPANDED)
        
        # cv2.imshow('detection', canvas)
        # self.get_logger().info("finsihed processing3")
        # cv2.waitKey(1)
        # self.coordinates_publisher.publish(msg)
        # self.get_logger().info('publishing coordinates!')
        

def main(args=None):
    rclpy.init(args=args)
    server = Coordinates()
    print("Start publishing coordinates!")
    rclpy.spin(server)
    server.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()