import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist,Point
from rclpy.qos import qos_profile_sensor_data
import numpy as np
import math
from message_filters import ApproximateTimeSynchronizer,Subscriber
from tf2_msgs.msg import TFMessage
from apriltag_msgs.msg import AprilTagDetectionArray
from custom_msg.msg import RobotCommand
from std_msgs.msg import Int8
import time
from myinterfaces.srv import Tag

class FollowtagStaticNode(Node):
    def __init__(self):
        super().__init__('control_test')
        self.publisher = self.create_publisher(Twist, '/vel_cmd', 10)
        self.linear_velocity = 0.3
        self.angular_velocity = -np.pi/16
        self.publish_velocity()
    def publish_velocity(self):
        # Calculate the velocity based on the tag pose
        # This is a placeholder, you need to implement the logic based on your robot's kinematics
        velocity_msg = Twist()
        initial_time = self.get_clock().now()
        current_time = self.get_clock().now()

        while initial_time+rclpy.duration.Duration(seconds=4.0)>current_time:
            velocity_msg.linear.x = 0.0
            velocity_msg.linear.y = 0.0
            velocity_msg.angular.z = -np.pi/16
            current_time = self.get_clock().now()
            self.publisher.publish(velocity_msg)

        initial_time = self.get_clock().now()
        current_time = self.get_clock().now()

        while initial_time+rclpy.duration.Duration(seconds=5.0)>current_time:
            velocity_msg.linear.x = self.linear_velocity
            velocity_msg.linear.y = 0.0
            velocity_msg.angular.z = 0.0
            # Publish the velocity message
            # print(f"Walking to tag, publishing:{velocity_msg}")
            current_time = self.get_clock().now()
            self.publisher.publish(velocity_msg)
        # decrease = 1
        # initial_time = self.get_clock().now()
        # current_time = self.get_clock().now()
        # while initial_time+rclpy.duration.Duration(seconds=1.0)>current_time:
        #     decrease += 1
        #     velocity_msg.linear.x = self.linear_velocity/(decrease*2)
        #     velocity_msg.linear.y = 0.0
        #     velocity_msg.angular.z = 0.0
        #     # Publish the velocity message
        #     # print(f"Walking to tag, publishing:{velocity_msg}")
        #     current_time = self.get_clock().now()
        #     if self.is_real:
        #         self.publisher.publish(velocity_msg)

        # 执行到这里时已经运动到目标位置
        self.is_finished = True
        self.translation = []
        self.rotation = []
def main(args=None):
    rclpy.init(args=args)
    follow_tag_node = FollowtagStaticNode()
    rclpy.spin(follow_tag_node)
    follow_tag_node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
