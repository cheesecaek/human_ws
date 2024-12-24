import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Point
from sensor_msgs.msg import Joy
from rclpy.qos import qos_profile_sensor_data
import time
import random
import copy

class HumanCoordinatePublisherNode(Node):
    def __init__(self):
        super().__init__('joy_publisher')
        self.publisher = self.create_publisher(Joy, '/joy', 10)

        self.timer = self.create_timer(0.5, self.timer_callback)  # 每秒发布一次
        self.axes = [ -0.0, -0.0 ,1.0, -0.0, -0.0, 1.0, 0.0, 0.0]
        self.buttons = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
        self.press_start = False
        self.is_actions = True
    def timer_callback(self):
        msg = Joy()
        # 随机生成人类位置的三维坐标
        # 发布消息
        axes_temp = copy.deepcopy(self.axes)
        buttons_temp  = copy.deepcopy(self.buttons)   
        if self.press_start:
            self.buttons_temp[7] == 1
            self.press_start = False
            msg.axes = axes_temp
            msg.buttons = buttons_temp
            print(msg)
            self.publisher.publish(msg)
        elif self.is_actions:
            for i in range(5):
                axes_temp[3] = 1.0
                axes_temp[4] = 0.0
                msg.axes = axes_temp
                msg.buttons = buttons_temp
                for i in range(10):
                    time.sleep(0.01)  # 0.01s 发布一次
                    self.publisher.publish(msg)
                
        else:
            msg.axes = axes_temp
            msg.buttons = buttons_temp
            print(msg)
            self.publisher.publish(msg)

def main(args=None):
    rclpy.init(args=args)
    human_coordinate_publisher_node = HumanCoordinatePublisherNode()
    rclpy.spin(human_coordinate_publisher_node)
    human_coordinate_publisher_node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()