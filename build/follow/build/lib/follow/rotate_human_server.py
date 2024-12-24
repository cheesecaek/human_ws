import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist, Point
from std_srvs.srv import Trigger
import numpy as np
import math
import threading
from rclpy.executors import MultiThreadedExecutor
import time

class RotationDetectorNode(Node):
    def __init__(self):
        super().__init__('rotation_detector_node')
        self.cmd_vel_pub = self.create_publisher(Twist, 'vel_cmd', 10)
        self.create_service(Trigger, 'start_rotation', self.handle_rotation)
        self.image_sub = self.create_subscription(Point, '/human_coordinate', self.image_callback, 10)
        self.person_detected = False
        self.distance = 0.0
    def handle_rotation(self, request, response):
        self.get_logger().info("Rotation service called!")
        self.person_detected = False
        def rotate():
            while not self.person_detected and rclpy.ok():
            # Publish rotation command
                twist = Twist()
                twist.angular.z = 0.25  # Rotate at a constant speed
                self.cmd_vel_pub.publish(twist)
                # rclpy.spin_once(self,timeout_sec = 0.5)
        # Stop the robot
            while abs(self.distance) > 0.3 and rclpy.ok():
                print('people')
                twist = Twist()
                twist.angular.z = 0.25
                self.cmd_vel_pub.publish(twist)
                # rclpy.spin_once(self,timeout_sec = 0.5)
            self.stop_robot()

            
        threading.Thread(target = rotate).start()
        while not self.person_detected:
            rclpy.spin_once(self,timeout_sec = 0.5)
        response.success = True
        response.message = "Rotation stopped due to person detection"
        return response
        
        

    def stop_robot(self):
        twist = Twist()
        self.cmd_vel_pub.publish(twist)  # Publish zero velocities to stop
        self.get_logger().info("Robot stopped.")

    def image_callback(self, msg):
        def image():
            print("111")
        if msg:
            self.distance = msg.x #x zuo biao
            self.person_detected = True
        threading.Thread(target = image).start()


def main(args=None):
    rclpy.init(args=args)
    node = RotationDetectorNode()
    executor = MultiThreadedExecutor()
    executor.add_node(node)
    executor.spin()
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()