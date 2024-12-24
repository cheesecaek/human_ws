import numpy as np
import rclpy
from rclpy.node import Node
from std_msgs.msg import String, Bool
from std_srvs.srv import Trigger
from custom_msg.msg import RobotCommand
import time
from geometry_msgs.msg import Point, Twist
from myinterfaces.msg import State
from myinterfaces.srv import Tag
import random
import threading
import math
import copy
from message_filters import ApproximateTimeSynchronizer,Subscriber
from tf2_msgs.msg import TFMessage
from apriltag_msgs.msg import AprilTagDetectionArray
from std_msgs.msg import Int8
from sensor_msgs.msg import Joy

class Manager(Node):
    def __init__(self):
        super().__init__('manage')
        self.state = State()
        self.ready_pub = self.create_publisher(Bool, 'ready_or_not', 10)
        self.vel_pub = self.create_publisher(Twist, 'vel_cmd', 10)
        self.head_pub = self.create_publisher(Joy, '/joy', 10)
        self.stand_or_walk_pub = self.create_publisher(RobotCommand, 'robot_cmd', 10)
        self.task_sub = self.create_subscription(State, 'state', self.state_callback, 10)
        self.pixel_coordinate_sub = self.create_subscription(Point, '/human_pixel_coordinate', self.pixel_coordinate_callback, 10)
        self.head_action_sub = self.create_subscription(Bool, '/head_action', self.head_action_callback, 10)

        self.apriltag = 0
        self.task = -1
        self.last_task = self.task
        self.last_tag = self.apriltag

        self.tag_coordinates_sub = Subscriber(self, TFMessage, '/tf')
        self.detection_sub = Subscriber(self, AprilTagDetectionArray, '/apriltag/detections')
        self.ts = ApproximateTimeSynchronizer([self.tag_coordinates_sub,self.detection_sub],10,0.1, allow_headerless=True)
        self.ts.registerCallback(self.tag_callback)
        
        self.tag_coordinates = None
        self.target_coordinates=None
        self.translation = []
        self.rotation = []
        self.x_offset = [0.0, 3.0, 0.0, 1.7, 1.2, 0.0, -3.0]
        self.z_offset = [-2.0, 1.0, -0.5, 0.45, 1, -1.2, -3.0]
        self.is_head_action = False #False时不能进入下一阶段

        self.linear_velocity = 0.4
        self.angular_velocity = 0.3

        self.count = 0
        self.linear_time = None
        self.rotation_time = None
        self.tf_msg = None
        self.detection_msg = None

        self.is_real = True# test
        self.pixel_x = None
        self.pixel_y = None

        self.axes = [ -0.0, -0.0 ,1.0, -0.0, -0.0, 1.0, 0.0, 0.0]
        self.buttons = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    def tag_callback(self, tf_msg, detection_msg):
        # print("receive tf_msg")
        self.tf_msg = tf_msg
        self.detection_msg = detection_msg
        if len(tf_msg.transforms) != 0:
            # 检测到tag的次数
            self.count+=1
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
        if self.apriltag == 0 and self.task == 0:
            x_offset = self.x_offset[0]
            z_offset = self.z_offset[0]
        elif self.apriltag == 0 and self.task == 1:
            x_offset = self.x_offset[1]
            z_offset = self.z_offset[1]
        elif self.apriltag == 2 and self.task == 0:
            x_offset = self.x_offset[2]
            z_offset = self.z_offset[2]
        elif self.apriltag == 2 and self.task == 1:
            x_offset = self.x_offset[3]
            z_offset = self.z_offset[3]
        elif self.apriltag == 3 and self.task == 0:
            x_offset = self.x_offset[4]
            z_offset = self.z_offset[4]
        elif self.apriltag == 4 and self.task == 0:
            x_offset = self.x_offset[5]
            z_offset = self.z_offset[5]
        elif self.apriltag == 4 and self.task == 1:
            x_offset = self.x_offset[6]
            z_offset = self.z_offset[6]
        else:
            return

        R = self.quaternion_to_rotation_matrix(quaternion)
        point_child = R @ (np.array(point) - np.array(translation))
        point_child[0]+=x_offset
        point_child[2]+=z_offset
        target_point = np.linalg.inv(R) @ np.array(point_child) + np.array(translation)
        return target_point
    
    
    def send_tag_request(self):
        while self.tf_msg is None:
            self.get_logger().info('ll')
        index = 0
        is_finished = False
        # 旋转直到找到tag
        while not is_finished:
            if len(self.tf_msg.transforms)!=0 and self.apriltag is not None:
                # the robot can see a tag
                tf_msg = self.tf_msg
                detection_msg = self.detection_msg
                for i, tag in enumerate(detection_msg.detections):
                    if tag.id == self.apriltag:
                        index = i
                        # the robot can see the targeted tag
                        self.tag_coordinates = tf_msg.transforms[index].transform.translation
                        if abs(math.atan(self.tag_coordinates.x/self.tag_coordinates.z))<= math.pi/6:
                            # 机器人正对着tag
                            State_command = RobotCommand()
                            State_command.target_state = 3 # 切换到站立
                            time.sleep(0.5)
                            if self.is_real:
                                self.stand_or_walk_pub.publish(State_command)
                            else:
                                print("start standing")
                            time.sleep(1.5) # 此时停止1.5s确保tf_message接收到的是稳定的坐标
                            is_finished = True # 如果机器人正对tag，则停止旋转
            else:
                self.find_tag()
        initial_count = self.count
        # 稳定读取坐标
        self.get_logger().info('tag found')
        while self.count-initial_count<=30:
            # 稳定读取坐标
            try:
                self.translation.append([self.tf_msg.transforms[index].transform.translation.x,self.tf_msg.transforms[index].transform.translation.y,
                                self.tf_msg.transforms[index].transform.translation.z])
                self.rotation.append([self.tf_msg.transforms[index].transform.rotation.x,self.tf_msg.transforms[index].transform.rotation.y,
                                                self.tf_msg.transforms[index].transform.rotation.z,self.tf_msg.transforms[index].transform.rotation.w])
            except IndexError as e:
                self.get_logger().info(e)
                self.count-=1
            finally:
                continue
        # 计算平均值
        self.translation = np.mean(np.array(self.translation),axis=0).tolist()
        self.rotation = np.mean(np.array(self.rotation),axis=0).tolist()
        State_command = RobotCommand()
        State_command.target_state = 4 # 切换到行走
        time.sleep(0.5)
        if self.is_real:
            self.stand_or_walk_pub.publish(State_command)
        else:
            self.get_logger().info('start_walking')
        self.get_logger().info('walk')
        self.publish_velocity()
    
    def find_tag(self):
        velocity_msg = Twist()
        # 使得旋转半径为30cm
        velocity_msg.linear.x = 0.0
        velocity_msg.linear.y = 0.0
        if self.tag_coordinates is not None:

            velocity_msg.angular.z = -0.3 if self.tag_coordinates.x > 0 else 0.3
        else:
            velocity_msg.angular.z = -0.3
        # Publish the velocity message
        # print(f"Trying to find tag ,publishing:{velocity_msg}")
        if self.is_real:
            self.vel_pub.publish(velocity_msg)

    def publish_velocity(self):
        # Calculate the velocity based on the tag pose
        # This is a placeholder, you need to implement the logic based on your robot's kinematics
        velocity_msg = Twist()
        self.target_coordinates = self.transform_point(self.translation,self.translation,self.rotation)
        # Linear velocity calculation
        x = self.target_coordinates[0]
        z = self.target_coordinates[2]
        self.get_logger().info(f"distance:{math.sqrt(x**2 + z**2)}")

        angular = math.atan(x/z) 
        self.rotation_time = abs(angular/self.angular_velocity)
        self.linear_time = (math.sqrt(x**2 + z**2)/self.linear_velocity)*2
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
                self.vel_pub.publish(velocity_msg)

        initial_time = self.get_clock().now()
        current_time = self.get_clock().now()

        while initial_time+rclpy.duration.Duration(seconds=self.linear_time)>current_time:
            t = (current_time-initial_time).nanoseconds /1e9 # 计算运动的秒数
            if t < self.linear_time/2:
                velocity_msg.linear.x = self.linear_velocity*(t)/(self.linear_time/2)
                velocity_msg.linear.y = 0.0
                velocity_msg.angular.z = 0.0
            else:
                velocity_msg.linear.x = self.linear_velocity*(self.linear_time-t)/(self.linear_time/2)
                velocity_msg.linear.y = 0.0
                velocity_msg.angular.z = 0.0

            current_time = self.get_clock().now()
            if self.is_real:
                self.vel_pub.publish(velocity_msg)

        # 执行到这里时已经运动到目标位置
        self.translation = []
        self.rotation = []

    def state_callback(self, msg):
        if msg:
            self.apriltag = msg.apriltag
            self.task = msg.task
            print(self.apriltag, self.task)

    # def human_callback(self, msg):
    #     if msg:
    #         self.human = True
    #         self.pixel_x = msg.x

    def pixel_coordinate_callback(self, msg):
        if msg:
            self.pixel_x = msg.x
            self.pixel_y = msg.y
            self.human = True
            # 处理接收到的像素坐标

    def head_action_callback(self, msg):
        if msg:
            if msg.data == True: 
                self.is_head_action = True
                self.get_logger().info('1')
            else: 
                self.is_head_action = False
                self.get_logger().info('2')

    # def rotate_human(self):
    #     axes_temp = copy.deepcopy(self.axes)
    #     buttons_temp  = copy.deepcopy(self.buttons)
    #     while (self.task == self.last_task) and (self.apriltag == self.last_tag):
    #         if self.human:
    #             axes_temp[0] -= (self.pixel_x-320)/320
    #             axes_temp[1] = 0.7
    #             if abs(axes_temp[0]) <= 1:
    #                 joy_msg = Joy()
    #                 joy_msg.header.stamp = self.get_clock().now().to_msg()
    #                 joy_msg.buttons = buttons_temp
    #                 joy_msg.axes = axes_temp
    #                 for i in range(20):
    #                     self.head_pub.publish(joy_msg)
    #                     time.sleep(0.01)
    #                 self.human = False
    #             else:
    #                 time.sleep(1.2)
    #                 self.human = False
    #                 self.body_rotate_human()
    #                 axes_temp = copy.deepcopy(self.axes)
    #                 buttons_temp  = copy.deepcopy(self.buttons)

                

    def body_rotate_human(self):
        while not self.human:
            walk = RobotCommand()
            walk.target_state = 4
            self.stand_or_walk_pub.publish(walk)
            vel = Twist()
            vel.linear.x = 0.0
            vel.angular.z = -0.3 if self.pixel_x is not None and self.pixel_x>320 else 0.3
            self.vel_pub.publish(vel)
            time.sleep(0.1)
        while abs(self.pixel_x-320) > 200:
            vel = Twist()
            vel.linear.x = 0.0
            vel.angular.z = -0.3 if self.pixel_x is not None and self.pixel_x>320 else 0.3
            self.vel_pub.publish(vel)
            time.sleep(0.1)
        self.human = False
        stand = RobotCommand()
        stand.target_state = 3
        self.stand_or_walk_pub.publish(stand)
        time.sleep(0.5)

    def handle_task(self):
        self.last_task = self.task
        self.last_tag = self.apriltag
        ready_or_not = Bool()
        while True:
            if (self.task != self.last_task) or (self.apriltag != self.last_tag):
                while True:
                    if self.is_head_action == True: break #等待头部动作完成
                self.last_task = self.task
                self.last_tag = self.apriltag

                walk = RobotCommand()
                walk.target_state = 4   
                self.get_logger().info('123')
                self.stand_or_walk_pub.publish(walk)
                time.sleep(0.5)

                # Send tag request
                self.get_logger().info('321')
                self.send_tag_request()
                self.get_logger().info('ok')
                # Send human request
                
                self.human = False
                self.body_rotate_human()
                self.get_logger().info("Human is detected")
                time.sleep(0.5)

                ready_or_not.data = True
                self.ready_pub.publish(ready_or_not)



def main(args=None):
    rclpy.init(args=args)
    node = Manager()
    Thread1 = threading.Thread(target=node.handle_task)
    Thread1.start()
    rclpy.spin(node)
    Thread1.join()
    node.get_logger().info("Shutting down...")
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()