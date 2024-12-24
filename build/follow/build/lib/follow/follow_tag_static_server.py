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
from myinterfaces.srv import Tag

class FollowtagStaticNode(Node):
    def __init__(self):
        super().__init__('tag_follower_static2')
        self.tag_coordinates_sub = Subscriber(self,
            TFMessage,
            '/tf')
        self.detection_sub = Subscriber(self,
            AprilTagDetectionArray,
            '/apriltag/detections')
        self.walk_service = self.create_service(Tag,"tag_server",self.handle_request)
        self.ts = ApproximateTimeSynchronizer([self.tag_coordinates_sub,self.detection_sub],10,0.1, allow_headerless=True)
        self.ts.registerCallback(self.tag_callback)

        # self.id_subscription = self.create_subscription(Int8,'tag_id',self.id_callback,qos_profile_sensor_data)
        self.publisher = self.create_publisher(Twist, '/vel_cmd', 10)
        self.tag_coordinates = None
        self.translation = None
        self.rotation = None

        self.target_coordinates=None

        self.x_offset = [0.0,1.7,1.7,0.0,1.7,0.8]
        self.z_offset = [-1.5,-0.7,-1.4,-0.3,0.45,1]
        self.is_seen = False
        # set the maximum velocity
        self.is_seen = False
        self.linear_velocity = 0.8
        self.angular_velocity = 0.4
        self.max_linear_velocity = 0.8
        self.max_angular_velocity = 0.4

        self.distance_threshold = 0
        
        self.last_linear_velocity = 0.0
        self.last_angular_velocity = 0.0

        self.velocity_threshold = 0.1
        self.follow_id = 0 # test
        self.follow_action = 0 # test
        self.count = 0
        self.linear_time = None
        self.rotation_time = None
        self.is_finished = False
        self.tf_msg = None
        self.detection_msg = None
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
        
        if self.follow_id == 0 and self.follow_action == 0:
            x_offset = self.x_offset[0]
            z_offset = self.z_offset[0]
        elif self.follow_id == 0 and self.follow_action == 1:
            x_offset = self.x_offset[1]
            z_offset = self.z_offset[1]
        elif self.follow_id == 2 and self.follow_action == 0:
            x_offset = self.x_offset[2]
            z_offset = self.z_offset[2]
        elif self.follow_id == 2 and self.follow_action == 1:
            x_offset = self.x_offset[3]
            z_offset = self.z_offset[3]
        elif self.follow_id == 2 and self.follow_action == 2:
            x_offset = self.x_offset[4]
            z_offset = self.z_offset[4]
        elif self.follow_id == 3 and self.follow_action == 0:
            x_offset = self.x_offset[5]
            z_offset = self.z_offset[5]
        else:
            return
        R = self.quaternion_to_rotation_matrix(quaternion)
        point_child = R @ (np.array(point) - np.array(translation))
        point_child[0]+=x_offset
        point_child[2]+=z_offset
        target_point = np.linalg.inv(R) @ np.array(point_child) + np.array(translation)
        return target_point

    def handle_request(self,request,response):

        self.follow_id = request.id.data
        self.follow_action = request.action.data
        # print("tracking ")
        if self.tf_msg:
            if len(self.tf_msg.transforms)!=0 and self.follow_id is not None:
                for index, tag in enumerate(self.detection_msg.detections):
                    if tag.id == self.follow_id:
                        self.is_seen = True
                        self.is_finished = False
                        self.count = 0
                        self.tag_coordinates = self.tf_msg.transforms[index].transform.translation
                        self.translation = [self.tf_msg.transforms[index].transform.translation.x,self.tf_msg.transforms[index].transform.translation.y,
                                            self.tf_msg.transforms[index].transform.translation.z]
                        self.rotation = [self.tf_msg.transforms[index].transform.rotation.x,self.tf_msg.transforms[index].transform.rotation.y,
                                            self.tf_msg.transforms[index].transform.rotation.z,self.tf_msg.transforms[index].transform.rotation.w]
                        self.publish_velocity()
                    else:
                        if self.translation is None:
                            self.find_tag()
                            self.count = 0
                        self.is_seen = False
                        self.count+=1

                        if self.translation is not None and self.count==100:
                            # last seen 
                            self.publish_velocity()   
                            
            else:
                if self.translation is None:
                    self.find_tag()
                    self.count = 0
                self.is_seen = False
                self.count+=1
                if self.translation is not None and self.count==100:
                    # last seen 
                    self.publish_velocity()
        if self.count>=250:
            # is_finished
            response.state = True
            self.translation = None
            self.rotation = None
            self.count = 0
        else:
            response.state = False
        
        return response

    def tag_callback(self, tf_msg, detection_msg):
        # print("receive tf_msg")
        self.tf_msg = tf_msg
        self.detection_msg = detection_msg
        
    def find_tag(self):
        velocity_msg = Twist()
        velocity_msg.linear.x = 0.0
        velocity_msg.linear.y = 0.0
        velocity_msg.angular.z = -0.15
        # Publish the velocity message
        # print(f"Trying to find tag ,publishing:{velocity_msg}")
        # self.publisher.publish(velocity_msg)

    def publish_velocity(self):
        # Calculate the velocity based on the tag pose
        # This is a placeholder, you need to implement the logic based on your robot's kinematics
        velocity_msg = Twist()
        self.target_coordinates = self.transform_point(self.translation,self.translation,self.rotation)
        # Linear velocity calculation
        x = self.target_coordinates[0]
        z = self.target_coordinates[2]
        print(f"target:{x,z}")

        angular = math.atan(x/z)
        # angular_velocity = - angular/self.rotation_time
        # linear_velocity = x/self.linear_time
        if self.is_seen:
            if z>=self.distance_threshold:
                self.linear_velocity  =0.5 * self.max_linear_velocity * (1 - math.exp(-z ))
            else:
                self.linear_velocity = 0.0

            self.linear_velocity = min(self.linear_velocity, self.max_linear_velocity)

            self.last_linear_velocity = 0.5 * self.last_linear_velocity + 0.5 * self.linear_velocity
            self.linear_velocity = self.last_linear_velocity


            if z != 0:
                angular = math.atan(x/z)
            else:
                angular = 0
            self.angular_velocity = -self.max_angular_velocity* angular
            if self.angular_velocity >= 0:
                self.angular_velocity = min(self.max_angular_velocity,self.angular_velocity)
            else:
                self.angular_velocity = max(-self.max_angular_velocity,self.angular_velocity)

            self.last_angular_velocity = 0.5 * self.last_angular_velocity + 0.5 * self.angular_velocity
            self.angular_velocity = self.last_angular_velocity

            velocity_msg.linear.x = self.linear_velocity
            velocity_msg.linear.y = 0.0
            velocity_msg.angular.z = self.angular_velocity
            # Publish the velocity message
            print(f"I can see the tag ,publishing:{velocity_msg}")
            # self.publisher.publish(velocity_msg)
        else:
            self.rotation_time = abs(angular/self.angular_velocity)
            self.linear_time = z/self.linear_velocity
            initial_time = self.get_clock().now()
            current_time = self.get_clock().now()

            while initial_time+rclpy.duration.Duration(seconds=self.rotation_time)>current_time and abs(self.angular_velocity)>self.velocity_threshold:
                velocity_msg.linear.x = 0.0
                velocity_msg.linear.y = 0.0
                # velocity_msg.angular.z = angular_velocity
                velocity_msg.angular.z = self.angular_velocity
                # Publish the velocity message
                # print(f"I cannot see the tag, publishing:{velocity_msg}")
                current_time = self.get_clock().now()
                # self.publisher.publish(velocity_msg)

            initial_time = self.get_clock().now()
            current_time = self.get_clock().now()

            while initial_time+rclpy.duration.Duration(seconds=self.linear_time)>current_time and abs(self.linear_velocity)>self.velocity_threshold:
                # velocity_msg.linear.x = linear_velocity
                velocity_msg.linear.x = self.linear_velocity
                velocity_msg.linear.y = 0.0
                velocity_msg.angular.z = 0.0
                # Publish the velocity message
                # print(f"I cannot see the tag, publishing:{velocity_msg}")
                current_time = self.get_clock().now()
                # self.publisher.publish(velocity_msg)


def main(args=None):
    rclpy.init(args=args)
    follow_tag_node = FollowtagStaticNode()
    rclpy.spin(follow_tag_node)
    follow_tag_node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
