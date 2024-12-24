import rclpy
from rclpy.node import Node
from sensor_msgs.msg import CameraInfo,Image


class CameraInfoPublisher(Node):
    def __init__(self):
        super().__init__('camerainfo')
        self.img_sub = self.create_subscription(Image,'/realsense_camera_node/sn036222070655/color/bgr/image_raw',self.img_callback,10)
        self.info_publisher = self.create_publisher(CameraInfo, '/sychornized/camera_info', 10)
        self.img_publisher = self.create_publisher(Image, '/sychornized/image_raw', 10)
        self.get_logger().info('CameraInfo Publisher started!')


    def img_callback(self,img_msg):
        msg = CameraInfo()

        # 动态时间戳
        now = self.get_clock().now().to_msg()
        msg.header.stamp = now
        msg.header.frame_id = 'sn036222070655_color_frame'

        # 图像分辨率
        msg.height = 480
        msg.width = 640

        # 相机参数
        msg.distortion_model = 'plumb_bob'
        msg.d = [0.0, 0.0, 0.0, 0.0, 0.0]
        msg.k = [
            605.9514770507812, 0.0, 327.2686462402344,
            0.0, 606.014892578125, 246.6658935546875,
            0.0, 0.0, 1.0
        ]
        msg.r = [
            1.0, 0.0, 0.0,
            0.0, 1.0, 0.0,
            0.0, 0.0, 1.0
        ]
        msg.p = [
            605.9514770507812, 0.0, 327.2686462402344, 0.0,
            0.0, 606.014892578125, 246.6658935546875, 0.0,
            0.0, 0.0, 1.0, 0.0
        ]

        # binning 和 ROI
        msg.binning_x = 0
        msg.binning_y = 0
        msg.roi.x_offset = 0
        msg.roi.y_offset = 0
        msg.roi.height = 0
        msg.roi.width = 0
        msg.roi.do_rectify = False

        print()
        img_msg.header.stamp = now
        img_msg.step = msg.width*3

        self.info_publisher.publish(msg)
        self.img_publisher.publish(img_msg)
        self.get_logger().info('Published CameraInfo with timestamp: %s' % str(now))

    # def publish_camera_info(self):
    #     msg = CameraInfo()

    #     # 动态时间戳
    #     now = self.get_clock().now().to_msg()
    #     msg.header.stamp = now
    #     msg.header.frame_id = 'sn036222070655_color_frame'

    #     # 图像分辨率
    #     msg.height = 480
    #     msg.width = 640

    #     # 相机参数
    #     msg.distortion_model = 'plumb_bob'
    #     msg.d = [0.0, 0.0, 0.0, 0.0, 0.0]
    #     msg.k = [
    #         605.9514770507812, 0.0, 327.2686462402344,
    #         0.0, 606.014892578125, 246.6658935546875,
    #         0.0, 0.0, 1.0
    #     ]
    #     msg.r = [
    #         1.0, 0.0, 0.0,
    #         0.0, 1.0, 0.0,
    #         0.0, 0.0, 1.0def publish_camera_info(self):
    #     msg = CameraInfo()

    #     # 动态时间戳
    #     now = self.get_clock().now().to_msg()
    #     msg.header.stamp = now
    #     msg.header.frame_id = 'sn036222070655_color_frame'

    #     # 图像分辨率
    #     msg.height = 480
    #     msg.width = 640

    #     # 相机参数
    #     msg.distortion_model = 'plumb_bob'
    #     msg.d = [0.0, 0.0, 0.0, 0.0, 0.0]
    #     msg.k = [
    #         605.9514770507812, 0.0, 327.2686462402344,
    #         0.0, 606.014892578125, 246.6658935546875,
    #         0.0, 0.0, 1.0
    #     ]
    #     msg.r = [
    #         1.0, 0.0, 0.0,
    #         0.0, 1.0, 0.0,
    #         0.0, 0.0, 1.0
    #     ]
    #     msg.p = [
    #         605.9514770507812, 0.0, 327.2686462402344, 0.0,
    #         0.0, 606.014892578125, 246.6658935546875, 0.0,
    #         0.0, 0.0, 1.0, 0.0
    #     ]

    #     # binning 和 ROI
    #     msg.binning_x = 0
    #     msg.binning_y = 0
    #     msg.roi.x_offset = 0
    #     msg.roi.y_offset = 0
    #     msg.roi.height = 0
    #     msg.roi.width = 0
    #     msg.roi.do_rectify = False

    #     # 发布消息
    #     self.publisher_.publish(msg)
    #     self.get_logger().info('Published CameraInfo with timestamp: %s' % str(now))
    #     ]

    #     # binning 和 ROI
    #     msg.binning_x = 0
    #     msg.binning_y = 0
    #     msg.roi.x_offset = 0
    #     msg.roi.y_offset = 0
    #     msg.roi.height = 0
    #     msg.roi.width = 0
    #     msg.roi.do_rectify = False

    #     # 发布消息
    #     self.publisher_.publish(msg)
    #     self.get_logger().info('Published CameraInfo with timestamp: %s' % str(now))

    
def main(args=None):
    rclpy.init(args=args)
    node = CameraInfoPublisher()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info('Shutting down CameraInfo Publisher...')
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()