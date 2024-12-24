import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist,Point
from rclpy.qos import qos_profile_sensor_data
import numpy as np
import math
from message_filters import ApproximateTimeSynchronizer,Subscriber
from tf2_msgs.msg import TFMessage
from apriltag_msgs.msg import AprilTagDetectionArray
from custom_msg.msg import RobotCommand
from std_msgs.msg import Int8
import time
from myinterfaces.srv import Tag

class FollowtagStaticNode(Node):
    def __init__(self):
        super().__init__('tag_follower_server')
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
        self.robotstate_publisher = self.create_publisher(RobotCommand,"/robot_cmd",10) # 切换行走：4，切换力控站立：3
        self.tag_coordinates = None
        self.translation = []
        self.rotation = []

        self.target_coordinates=None

        self.x_offset = [0.0, 1.7, 0.0, 1.7, 1.2, 0.0, -3.0]
        self.z_offset = [-1.5, -0.7, -0.5, 0.45, 1, -1.2, -3.0]


        # self.x_offset = [-2.0,2.0,-2.0,2.0]
        # self.z_offset = [-2,-2,-2,-2]
        self.stable = False
        self.linear_velocity = 0.5
        self.angular_velocity = 0.15

        self.distance_threshold = 0

        self.velocity_threshold = 0.1
        self.follow_id = 0 # test
        self.follow_action = 0 # test
        self.count = 0
        self.linear_time = None
        self.rotation_time = None
        self.is_finished = False
        self.tf_msg = None
        self.detection_msg = None

        self.is_real = True# test
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
        elif self.follow_id == 3 and self.follow_action == 0:
            x_offset = self.x_offset[4]
            z_offset = self.z_offset[4]
        elif self.follow_id == 4 and self.follow_action == 0:
            x_offset = self.x_offset[5]
            z_offset = self.z_offset[5]
        elif self.follow_id == 4 and self.follow_action == 1:
            x_offset = self.x_offset[6]
            z_offset = self.z_offset[6]
        else:
            return

        # if self.follow_id == 7 and self.follow_action == 0:
        #     x_offset = self.x_offset[0]
        #     z_offset = self.z_offset[0]
        # elif self.follow_id == 7 and self.follow_action == 1:
        #     x_offset = self.x_offset[1]
        #     z_offset = self.z_offset[1]
        # elif self.follow_id == 7 and self.follow_action == 2:
        #     x_offset = self.x_offset[2]
        #     z_offset = self.z_offset[2]
        # elif self.follow_id == 7 and self.follow_action == 3:
        #     x_offset = self.x_offset[3]
        #     z_offset = self.z_offset[3]

        # else:
        #     return

        R = self.quaternion_to_rotation_matrix(quaternion)
        point_child = R @ (np.array(point) - np.array(translation))
        point_child[0]+=x_offset
        point_child[2]+=z_offset
        target_point = np.linalg.inv(R) @ np.array(point_child) + np.array(translation)
        return target_point

    def handle_request(self,request,response):
        self.follow_id = request.id.data
        self.follow_action = request.action.data
        self.is_finished = False
        if self.tf_msg:
            # 正常接收tf信息
            if len(self.tf_msg.transforms)!=0 and self.follow_id is not None:
                # the robot can see a tag
                for index, tag in enumerate(self.detection_msg.detections):
                    if tag.id == self.follow_id:
                        # the robot can see the targeted tag
                        self.tag_coordinates = self.tf_msg.transforms[index].transform.translation
                        if abs(self.tag_coordinates.x)<=0.25 and not self.stable:
                            # 机器人正对着tag
                            State_command = RobotCommand()
                            State_command.target_state = 3 # 切换到站立
                            time.sleep(1.5)
                            if self.is_real:
                                self.robotstate_publisher.publish(State_command)
                            else:
                                print("start standing")
                            time.sleep(1.5) # 切换模式后停3秒确保安全
                            self.stable = True # 切换到稳定状态，开始读取坐标
                        elif not self.stable:
                            # 机器人没有正对着tag
                            if not self.stable:
                                self.find_tag()
                        if self.stable:
                            # 稳定读取坐标
                            self.count+=1
                            if self.count >=10:
                                self.translation.append([self.tf_msg.transforms[index].transform.translation.x,self.tf_msg.transforms[index].transform.translation.y,
                                                    self.tf_msg.transforms[index].transform.translation.z])
                                self.rotation.append([self.tf_msg.transforms[index].transform.rotation.x,self.tf_msg.transforms[index].transform.rotation.y,
                                                    self.tf_msg.transforms[index].transform.rotation.z,self.tf_msg.transforms[index].transform.rotation.w])
                            if self.count == 30:
                                print("Start to walk")
                                self.translation = np.mean(np.array(self.translation),axis=0).tolist()
                                self.rotation = np.mean(np.array(self.rotation),axis=0).tolist()
                                self.count =  0
                                State_command = RobotCommand()
                                State_command.target_state = 4 # 切换到行走
                                if self.is_real:
                                    self.robotstate_publisher.publish(State_command)
                                else:
                                    print("start walking")
                                    time.sleep(1)
                                self.stable = False
                                self.publish_velocity()
                    else:
                        if len(self.translation) == 0:
                            if not self.stable:
                                self.find_tag()     
            else:
                if len(self.translation) == 0:
                    if not self.stable:
                        self.find_tag()
        else:
            print("waiting for tf_msg...")
        response.state = self.is_finished
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
        if self.is_real:
            self.publisher.publish(velocity_msg)

    def publish_velocity(self):
        # Calculate the velocity based on the tag pose
        # This is a placeholder, you need to implement the logic based on your robot's kinematics
        velocity_msg = Twist()
        print("tag:",self.translation)
        self.target_coordinates = self.transform_point(self.translation,self.translation,self.rotation)
        # Linear velocity calculation
        x = self.target_coordinates[0]
        z = self.target_coordinates[2]
        print(f"target:{x,z}")

        angular = math.atan(x/z) 
        self.rotation_time = abs(angular/self.angular_velocity)
        self.linear_time = math.sqrt(x**2 + z**2)/self.linear_velocity
        initial_time = self.get_clock().now()
        current_time = self.get_clock().now()

        while initial_time+rclpy.duration.Duration(seconds=self.rotation_time)>current_time:
            velocity_msg.linear.x = 0.0
            velocity_msg.linear.y = 0.0
            velocity_msg.angular.z = self.angular_velocity if angular < 0 else -self.angular_velocity
            # Publish the velocity message
            # print(f"Walking to tag, publishing:{velocity_msg}")
            current_time = self.get_clock().now()
            if self.is_real:
                self.publisher.publish(velocity_msg)
                
        # decrease = 1
        # initial_time = self.get_clock().now()
        # current_time = self.get_clock().now()
        
        # while initial_time+rclpy.duration.Duration(seconds=1.0)>current_time:
        #     decrease += 1
        #     velocity_msg.linear.x = self.linear_velocity*(1-(1/decrease))
        #     velocity_msg.linear.y = 0.0
        #     velocity_msg.angular.z = 0.0
        #     # Publish the velocity message
        #     # print(f"Walking to tag, publishing:{velocity_msg}")
        #     current_time = self.get_clock().now()
        #     if self.is_real:
        #         self.publisher.publish(velocity_msg)
        initial_time = self.get_clock().now()
        current_time = self.get_clock().now()

        while initial_time+rclpy.duration.Duration(seconds=self.linear_time)>current_time:
            velocity_msg.linear.x = self.linear_velocity
            velocity_msg.linear.y = 0.0
            velocity_msg.angular.z = 0.0
            # Publish the velocity message
            # print(f"Walking to tag, publishing:{velocity_msg}")
            current_time = self.get_clock().now()
            if self.is_real:
                self.publisher.publish(velocity_msg)

        # decrease = 1
        # initial_time = self.get_clock().now()
        # current_time = self.get_clock().now()

        # while initial_time+rclpy.duration.Duration(seconds=1.0)>current_time:
        #     decrease += 1
        #     velocity_msg.linear.x = self.linear_velocity/(decrease*2)
        #     velocity_msg.linear.y = 0.0
        #     velocity_msg.angular.z = 0.0
        #     # Publish the velocity message
        #     # print(f"Walking to tag, publishing:{velocity_msg}")
        #     current_time = self.get_clock().now()
        #     if self.is_real:
        #         self.publisher.publish(velocity_msg)

        # 执行到这里时已经运动到目标位置
        self.is_finished = True
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
