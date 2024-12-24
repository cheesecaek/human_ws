import rclpy
from rclpy.node import Node
from myinterfaces.srv import Tag
from rclpy.qos import qos_profile_sensor_data
from geometry_msgs.msg import Point,Twist
import time

# 该client必须持续发送请求直到response.state = True
class ImageAndDepthImageToCoordinateClient(Node):
    def __init__(self):
        super().__init__('tag_test_client')
        self.tag_client = self.create_client(Tag, 'tag_server')
        self.index = 0
        self.task_list = [[0,0],[0,1],[2,0],[2,1],[2.2],[3,0]]

        self.send_request()

    def send_tag_request(self,tag_id,task_id):
        while not self.client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Service not available, waiting again...')
        
        request = Tag.Request()
        request.id.data = tag_id
        request.action.data = task_id
        future = self.client.call_async(request)
        future.add_done_callback(self.response_callback)
        rclpy.spin_until_future_complete(self.tag_client, future)
        if future.state:
            return
        else:
            send_tag_request(tag_id,task_id)

def main(args=None):
    rclpy.init(args=args)
    client = ImageAndDepthImageToCoordinateClient()
    rclpy.spin(client)
    client.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()