import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Point
from rclpy.qos import qos_profile_sensor_data
import time
import random

class HumanCoordinatePublisherNode(Node):
    def __init__(self):
        super().__init__('human_coordinate_publisher_node')
        self.publisher_ = self.create_publisher(Point, '/human_coordinate', 10)
        self.timer = self.create_timer(1.0, self.timer_callback)  # 每秒发布一次

    def timer_callback(self):
        msg = Point()
        # 随机生成人类位置的三维坐标
        msg.x = random.uniform(-4, 4)
        msg.y = random.uniform(-1, 1)
        msg.z = random.uniform(0, 10) 

        # 发布消息
        self.publisher_.publish(msg)
        self.get_logger().info('Publishing human coordinate: x=%f, y=%f, z=%f' % (msg.x, msg.y, msg.z))

def main(args=None):
    rclpy.init(args=args)
    human_coordinate_publisher_node = HumanCoordinatePublisherNode()
    rclpy.spin(human_coordinate_publisher_node)
    human_coordinate_publisher_node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()