import rclpy
from rclpy.node import Node
from myinterfaces.srv import Action
import time
from geometry_msgs.msg import Twist, Point

class Move(Node):
    def __init__(self):
        super().__init__('move_server')
        self.move_robot_server = self.create_service(Action, "move_robot", self.execute_callback)
        self.vel_pub = self.create_publisher(Twist, "vel_cmd", 10)
        self.human_sub = self.create_subscription(Point, "human_coordinates", self.human_callback, 10)
        self.human = 0
        self.ensure = 0

    def execute_callback(self, request, response):
        try:
            self.get_logger().info("Move request received")
            now = time.time()
            vel_msg = Twist()
            vel_msg.linear.x = request.linear_x
            vel_msg.linear.y = request.linear_y
            vel_msg.linear.z = request.linear_z
            vel_msg.angular.x = request.angular_x
            vel_msg.angular.y = request.angular_y
            vel_msg.angular.z = request.angular_z
            total_time = request.duration

            if total_time != 0:
                while time.time() - now < total_time:
                    self.vel_pub.publish(vel_msg)
                    time.sleep(0.05)
            else:
                while self.human == 0:
                    self.vel_pub.publish(vel_msg)
                    time.sleep(0.05)
                self.human = 0

            response.success = 1
        except Exception as e:
            self.get_logger().error(f"Error rotating robot:{e}")
            response.success = 0

    def human_callback(self, msg):
        if msg.data:
            self.human = 1

def main(args = None):
    rclpy.init(args=args)
    move_service = Move()
    rclpy.spin(move_service)
    move_service.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()