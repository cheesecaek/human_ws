import rclpy
from rclpy.node import Node
from myinterfaces.srv import Humancoordinatespcd
from rclpy.qos import qos_profile_sensor_data
from sensor_msgs.msg import Image, PointCloud2
from sensor_msgs_py import point_cloud2
from geometry_msgs.msg import Point
from message_filters import ApproximateTimeSynchronizer,Subscriber

class ImageAndPointCloud2ToCoordinateClient(Node):
    def __init__(self):
        super().__init__('human_coordinate_client_pcd')
        self.client = self.create_client(Humancoordinatespcd, 'human_coordinate_server_pcd')

        # self.image_sub = self.create_subscription(
        #     Image,
        #     '/realsense_camera_node/sn036222070655/color/bgr/image_raw',
        #     self.image_callback,
        #     qos_profile_sensor_data)
        # self.pointcloud_sub = self.create_subscription(
        #     PointCloud2,
        #     '/realsense_camera_node/sn036222070655/xyz/pointcloud',
        #     self.pointcloud_callback,
        #     qos_profile_sensor_data)

        # Time synchronizer
        self.image_sub = Subscriber(self,
            Image,
            '/realsense_camera_node/sn036222070655/color/bgr/image_raw')
        self.pointcloud_sub = Subscriber(self,
            PointCloud2,
            '/realsense_camera_node/sn036222070655/xyz/pointcloud')
        self.ts = ApproximateTimeSynchronizer([self.image_sub,self.pointcloud_sub],10,0.1)
        self.ts.registerCallback(self.sync_callback)
        self.image = None
        self.pointcloud = None

    # def image_callback(self, msg):
    #     # self.get_logger().info("getting color image")
    #     self.image = msg
    #     self.send_request()
        

    # def pointcloud_callback(self, msg):
    #     # self.get_logger().info('getting pointcloud')
    #     self.pointcloud = msg
    #     self.send_request()
    def sync_callback(self,color_msg,pcd_msg):
        self.image = color_msg
        self.pointcloud = pcd_msg
        self.send_request()

    def send_request(self):
        if self.image is None or self.pointcloud is None:
            self.get_logger().info('Waiting for image and pointcloud data...')
            return

        while not self.client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Service not available, waiting again...')
            return
        
        request = Humancoordinatespcd.Request()
        request.image = self.image
        request.pointcloud = self.pointcloud
        # print(f"color image;{self.image.header}")
        # print(f'pointcloud;{self.pointcloud.header}')
        future = self.client.call_async(request)
        future.add_done_callback(self.response_callback)

    def response_callback(self, future):
        try:
            response = future.result()
        except Exception as e:
            self.get_logger().info('Service call failed %r' % (e,))
        else:
            self.get_logger().info('Service response: %s' % (response.coordinate,))

def main(args=None):
    rclpy.init(args=args)
    client = ImageAndPointCloud2ToCoordinateClient()
    rclpy.spin(client)
    client.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()