import rclpy
from rclpy.node import Node
from myinterfaces.srv import Action
import time
from geometry_msgs.msg import Twist

class Move(Node):
    def __init__(self):
        super().__init__('move_node')
        self.move_robot_server = self.create_service(Action, "move_robot", self.move_handle)
        self.vel_pub = self.create_publisher(Twist, "vel_cmd", 10)
        self.now = 0

    def move_handle(self, request, response):
        now = time.time()
        vel_msg = Twist()
        vel_msg.linear.x = request.linear_x
        vel_msg.linear.y = request.linear_y
        vel_msg.linear.z = request.linear_z
        vel_msg.angular.x = request.angular_x
        vel_msg.angular.y = request.angular_y
        vel_msg.angular.z = request.angular_z
        total_time = request.duration
        while time.time() - now < total_time:
            self.vel_pub.publish(vel_msg)
            time.sleep(0.05)
        response.success = 1
        return response

def main(args = None):
    rclpy.init(args=args)
    service = Move()
    rclpy.spin(service)
    service.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
