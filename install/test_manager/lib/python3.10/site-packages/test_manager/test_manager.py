import rclpy
from rclpy.node import Node
from myinterfaces.srv import Apriltag

class TestManager(Node):
    def __init__(self):
        super().__init__()
        self.apriltag_client = self.create_client(Apriltag, 'apriltag')
        self.apriltag = 0
        self.action = 0
        self.req = apriltag.Request()

    def send_request(self, a, b):
        self.req.apriltag = a
        self.req.action = b
        return self.apriltag_client.call_async(self.req)

def main(args=None):
    rclpy.init(args=args)
    node = TestManager()
    while rclpy.ok():
        apriltag_order = eval(input("Enter the apriltag order: "))
        action_order = eval(input("Enter the action: "))
        future = node.send_request(apriltag_order, action_order)
        rclpy.spin_until_future_complete(node, future)
        response = future.result()
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()