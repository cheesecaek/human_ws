import rclpy
from rclpy.node import Node
from myinterfaces.srv import Tag
from rclpy.qos import qos_profile_sensor_data
from geometry_msgs.msg import Point,Twist
import time


class ImageAndDepthImageToCoordinateClient(Node):
    def __init__(self):
        super().__init__('tag_test_client')
        self.client = self.create_client(Tag, 'tag_server')
        self.follow_id = None
        self.action = None
        self.index = 0
        self.task_list = [[0,0],[0,1],[2,0],[2,1],[3,0],[4,0]]
        # self.task_list = [[7,0],[7,1],[7,2],[7,3]]
        self.start()

    def start(self):
        self.send_request()

    def send_request(self):
        self.follow_id = self.task_list[self.index][0]
        self.action = self.task_list[self.index][1]

        while not self.client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Service not available, waiting again...')
        
        request = Tag.Request()
        request.id.data = self.follow_id
        request.action.data = self.action
        print("sending request:",self.follow_id,self.action)
        future = self.client.call_async(request)
        future.add_done_callback(self.response_callback)

    def response_callback(self, future):
        try:
            response = future.result()
            if response.state:
                print("task finishing")
                time.sleep(5)
                self.index+=1
                self.send_request()
            else:
                time.sleep(0.1)
                self.send_request()
        except Exception as e:
            self.get_logger().info('Service call failed %r' % (e,))
        else:
            pass
            


def main(args=None):
    rclpy.init(args=args)
    client = ImageAndDepthImageToCoordinateClient()
    rclpy.spin(client)
    client.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()