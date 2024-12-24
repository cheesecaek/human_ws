import sys
sys.path.insert(0, "/home/robot/miniconda3/envs/face/lib/python3.10/site-packages")
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import cv2
import numpy as np
import socket
import pickle
import struct

class image_subscription(Node):
	def __init__(self, name):
		super().__init__(name)
		self.get_logger().info("image receive start")
		self.bridge = CvBridge()

		self.image_receive = self.create_subscription(Image, '/realsense_camera_node/sn036222070655/color/bgr/image_raw', self.color_callback, 10)

		self.robot2windows = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
		self.windows2robot = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
		self.windows2robot.bind(('192.168.1.10', 35616))
		self.target_ip = '192.168.0.101'
		self.target_port = 35613

	def color_callback(self, msg):
		self.get_logger().info('image received')
		print(msg.encoding)
		print(msg.width, msg.height, msg.step)
		img_data = np.frombuffer(msg.data, dtype = np.uint8)
		frame = img_data.reshape((480, 640, 3))
		_, buffer = cv2.imencode('.jpg', frame, [int(cv2.IMWRITE_JPEG_QUALITY), 90])
		data = buffer.tobytes()
		print(len(data))
		self.robot2windows.sendto(data, (self.target_ip, self.target_port))
		# name, _ = self.windows2robot.recvfrom(50)
		# cv2.imshow('frame', frame)
		# if cv2.waitKey(1) == ord('q'):
		# 	cv2.destroyAllWindows()

def main(args = None):
    rclpy.init(args = args)
    node = image_subscription('hello')
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
