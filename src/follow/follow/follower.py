import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist,Point
from rclpy.qos import qos_profile_sensor_data
import numpy as np
import math

class FollowHumanNode(Node):
    def __init__(self):
        super().__init__('follower')
        self.subscription = self.create_subscription(
            Point,
            '/human_coordinate',
            self.listener_callback,
            qos_profile_sensor_data)
        self.subscription  # prevent unused variable warning
        self.publisher = self.create_publisher(Twist, '/vel_cmd', 10)
        self.human_coordinates = None

        # set the maximum velocity
        self.max_linear_velocity = 0.8
        self.max_angular_velocity = 0.8

        self.distance_threshold = 0.5
        
        self.last_linear_velocity = 0.0
        self.last_angular_velocity = 0.0
    def listener_callback(self, msg):
        self.human_coordinates = msg

        # Publish the velocity command based on human coordinates
        self.publish_velocity()

    def publish_velocity(self):
        # Calculate the velocity based on the human pose
        # This is a placeholder, you need to implement the logic based on your robot's kinematics
        velocity_msg = Twist()
        angular = math.atan(self.human_coordinates.x/self.human_coordinates.z)
        distance = math.sqrt(self.human_coordinates.x**2+self.human_coordinates.z**2)
        # Linear velocity calculation
        if self.human_coordinates.z>=self.distance_threshold:
            linear_velocity = self.max_linear_velocity * (1 - math.exp(-distance))
        else:
            linear_velocity = 0.0

        linear_velocity = min(linear_velocity, self.max_linear_velocity)

        self.last_linear_velocity = 0.5 * self.last_linear_velocity + 0.5 * linear_velocity
        linear_velocity = self.last_linear_velocity

        angular_velocity = -angular/2
        
        if angular_velocity >= 0:
            angular_velocity = min(self.max_angular_velocity,angular_velocity)
        else:
            angular_velocity = max(-self.max_angular_velocity,angular_velocity)

        self.last_angular_velocity = 0.5 * self.last_angular_velocity + 0.5 * angular_velocity
        angular_velocity = self.last_angular_velocity

        velocity_msg.linear.x = linear_velocity
        velocity_msg.linear.y = 0.0
        velocity_msg.angular.z = angular_velocity
        # Publish the velocity message
        print(f"publishing:{velocity_msg}")
        self.publisher.publish(velocity_msg)
        self.get_logger().info('Publishing velocity command')

def main(args=None):
    rclpy.init(args=args)
    follow_human_node = FollowHumanNode()
    rclpy.spin(follow_human_node)
    follow_human_node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()