import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist,Point
from rclpy.qos import qos_profile_sensor_data
import numpy as np
import math
from message_filters import ApproximateTimeSynchronizer,Subscriber
from tf2_msgs.msg import TFMessage
from apriltag_msgs.msg import AprilTagDetectionArray
from std_msgs.msg import Int8
import time

class FollowtagStaticNode(Node):
    def __init__(self):
        super().__init__('tag_follower_static')
        self.tag_coordinates_sub = Subscriber(self,
            TFMessage,
            '/tf')
        self.detection_sub = Subscriber(self,
            AprilTagDetectionArray,
            '/apriltag/detections')
        self.ts = ApproximateTimeSynchronizer([self.tag_coordinates_sub,self.detection_sub],10,0.1, allow_headerless=True)
        self.ts.registerCallback(self.tag_callback)

        self.id_subscription = self.create_subscription(Int8,'tag_id',self.id_callback,qos_profile_sensor_data)
        self.publisher = self.create_publisher(Twist, '/vel_cmd', 10)
        self.tag_coordinates = None
        self.translation = []
        self.rotation = []
        self.target_coordinates=None
        self.x_offset = 1
        self.z_offset = -0.5
        self.last_seen = None
        # set the maximum velocity
        self.linear_velocity = 0.6
        self.angular_velocity = 0.4

        self.distance_threshold = 0


        self.follow_id = 1 # test
        self.count = 0
        self.linear_time = 5
        self.rotation_time = 3
    def quaternion_to_rotation_matrix(self,q):
        """
        将四元数转换为旋转矩阵。
        四元数 q = [w, x, y, z]
        """
        w, x, y, z = q
        return np.array([
            [1 - 2 * (y**2 + z**2), 2 * (x * y - z * w), 2 * (x * z + y * w)],
            [2 * (x * y + z * w), 1 - 2 * (x**2 + z**2), 2 * (y * z - x * w)],
            [2 * (x * z - y * w), 2 * (y * z + x * w), 1 - 2 * (x**2 + y**2)]
        ])
        
    def transform_point(self, point, translation, quaternion):

        R = self.quaternion_to_rotation_matrix(quaternion)
        point_child = R @ (np.array(point) - np.array(translation))
        point_child[0]+=self.x_offset
        point_child[2]+=self.z_offset
        target_point = np.linalg.inv(R) @ np.array(point_child) + np.array(translation)
        return target_point

    
    def id_callback(self,msg):
        self.follow_id = msg
        self.count = 0

    def tag_callback(self, tf_msg, detection_msg):
        if len(tf_msg.transforms)!=0 and self.follow_id is not None:
            for index, tag in enumerate(detection_msg.detections):
                if tag.id == self.follow_id:
                    print("detected")
                    self.count+=1
                    self.translation.append([tf_msg.transforms[index].transform.translation.x,tf_msg.transforms[index].transform.translation.y,
                                            tf_msg.transforms[index].transform.translation.z])
                    self.rotation.append([tf_msg.transforms[index].transform.rotation.x,tf_msg.transforms[index].transform.rotation.y,
                                            tf_msg.transforms[index].transform.rotation.z,tf_msg.transforms[index].transform.rotation.w])
                    if self.count == 20:
                        self.translation = np.mean(np.array(self.translation),axis=0).tolist()
                        self.rotation = np.mean(np.array(self.rotation),axis=0).tolist()
                        self.count =  0
                        print("Publishing velocity")
                        self.publish_velocity()                      
                        
                    
        else:
            pass
            

    def publish_velocity(self):
        # Calculate the velocity based on the tag pose
        # This is a placeholder, you need to implement the logic based on your robot's kinematics
        velocity_msg = Twist()
        self.target_coordinates = self.transform_point(self.translation,self.translation,self.rotation)
        # Linear velocity calculation
        x = self.target_coordinates[0]
        z = self.target_coordinates[2]

        angular = math.atan(x/z)
        # angular_velocity = - angular/self.rotation_time
        # linear_velocity = x/self.linear_time
        self.rotation_time = abs(angular/self.angular_velocity)
        self.linear_time = x/self.linear_velocity
        initial_time = self.get_clock().now()
        current_time = self.get_clock().now()

        while initial_time+rclpy.duration.Duration(seconds=self.rotation_time)>current_time:
            velocity_msg.linear.x = 0.0
            velocity_msg.linear.y = 0.0
            # velocity_msg.angular.z = angular_velocity
            velocity_msg.angular.z = self.angular_velocity if angular <= 0 else -self.angular_velocity
            # Publish the velocity message
            print(f"publishing:{velocity_msg}")
            current_time = self.get_clock().now()
            # self.publisher.publish(velocity_msg)

        initial_time = self.get_clock().now()
        current_time = self.get_clock().now()

        while initial_time+rclpy.duration.Duration(seconds=self.linear_time*2)>current_time:
            # velocity_msg.linear.x = linear_velocity
            velocity_msg.linear.x = self.linear_velocity
            velocity_msg.linear.y = 0.0
            velocity_msg.angular.z = 0.0
            # Publish the velocity message
            print(f"publishing:{velocity_msg}")
            current_time = self.get_clock().now()
            # self.publisher.publish(velocity_msg)
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
