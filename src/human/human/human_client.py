import rclpy
from rclpy.node import Node
from myinterfaces.srv import Humancoordinates
from rclpy.qos import qos_profile_sensor_data
from sensor_msgs.msg import Image,CameraInfo
from geometry_msgs.msg import Point
from message_filters import ApproximateTimeSynchronizer,Subscriber

class ImageAndDepthImageToCoordinateClient(Node):
    def __init__(self):
        super().__init__('human_coordinate_client')
        self.client = self.create_client(Humancoordinates, 'human_coordinate_server')

        self.image_sub = Subscriber(self,
            Image,
            '/realsense_camera_node/sn036222070655/color/bgr/image_raw')
        self.depth_sub = Subscriber(self,
            Image,
            '/realsense_camera_node/sn036222070655/depth/u16/image_raw')
        self.ts = ApproximateTimeSynchronizer([self.image_sub,self.depth_sub],10,0.1)
        self.ts.registerCallback(self.sync_callback)
        self.image = None
        self.depth_image = None
        
        self.coordinate_publisher = self.create_publisher(Point,'/human_coordinate',10)
    def sync_callback(self,color_msg,depth_msg):
        self.image = color_msg
        self.depth_image = depth_msg
        self.send_request()

    def send_request(self):
        if self.image is None or self.depth_image is None:
            self.get_logger().info('Waiting for image and pointcloud data...')
            return

        while not self.client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Service not available, waiting again...')
            return
        
        request = Humancoordinates.Request()
        request.image = self.image
        request.depth_image = self.depth_image
        
        future = self.client.call_async(request)
        future.add_done_callback(self.response_callback)

    def response_callback(self, future):
        try:
            response = future.result()
            if response.response:
                self.coordinate_publisher.publish(response.coordinate)
        except Exception as e:
            self.get_logger().info('Service call failed %r' % (e,))
        else:
            self.get_logger().info('Service response: %s' % (response.coordinate,))


def main(args=None):
    rclpy.init(args=args)
    client = ImageAndDepthImageToCoordinateClient()
    rclpy.spin(client)
    client.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()