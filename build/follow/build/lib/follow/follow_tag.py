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

class FollowtagNode(Node):
    def __init__(self):
        super().__init__('tag_follower')
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
        self.translation = None
        self.rotation = None
        self.target_coordinates=None
        self.x_offset = 1
        self.z_offset = -0.5

        # set the maximum velocity
        self.max_linear_velocity = 0.8
        self.max_angular_velocity = 0.4

        self.distance_threshold = 0
        
        self.last_linear_velocity = 0.0
        self.last_angular_velocity = 0.0
        self.follow_id = 7 # test

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

    def tag_callback(self, tf_msg, detection_msg):
        if len(tf_msg.transforms)!=0 and self.follow_id is not None:
            for index, tag in enumerate(detection_msg.detections):
                if tag.id == self.follow_id:
                    self.tag_coordinates = tf_msg.transforms[index].transform.translation
                    self.translation = [tf_msg.transforms[index].transform.translation.x,tf_msg.transforms[index].transform.translation.y,tf_msg.transforms[index].transform.translation.z]
                    self.rotation = [tf_msg.transforms[index].transform.rotation.x,tf_msg.transforms[index].transform.rotation.y,tf_msg.transforms[index].transform.rotation.z,tf_msg.transforms[index].transform.rotation.w]
                    print(self.translation,self.rotation)
                    print("Publishing velocity")
                    self.publish_velocity()
        else:
            
            print("message empty!")
            

    def publish_velocity(self):
        # Calculate the velocity based on the tag pose
        # This is a placeholder, you need to implement the logic based on your robot's kinematics
        velocity_msg = Twist()
        self.target_coordinates = self.transform_point(self.translation,self.translation,self.rotation)
        # Linear velocity calculation
        if self.target_coordinates[2]>=self.distance_threshold:
            linear_velocity  =0.5 * self.max_linear_velocity * (1 - math.exp(-self.target_coordinates[2] ))
        else:
            linear_velocity = 0.0

        linear_velocity = min(linear_velocity, self.max_linear_velocity)

        self.last_linear_velocity = 0.5 * self.last_linear_velocity + 0.5 * linear_velocity
        linear_velocity = self.last_linear_velocity


        if self.target_coordinates[2] != 0:
            angular = math.atan(self.target_coordinates[0]/self.target_coordinates[2])
        else:
            angular = 0
        angular_velocity = -self.max_angular_velocity* angular
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

def main(args=None):
    rclpy.init(args=args)
    follow_tag_node = FollowtagNode()
    rclpy.spin(follow_tag_node)
    follow_tag_node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
