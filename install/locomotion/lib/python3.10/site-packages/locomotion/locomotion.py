'''
You should start the node in when the robot is in balancestand state
'''

import rclpy
from rclpy.node import Node
from myinterfaces.srv import Humancoordinates
from myinterfaces.msg import DetectCoordinates
from rclpy.qos import qos_profile_sensor_data
from sensor_msgs.msg import Image,CameraInfo,Joy
from geometry_msgs.msg import Point,Twist
from custom_msg.msg import RobotCommand
import copy
import random
import numpy as np
import time
import math

class Locomotion(Node):
    def __init__(self):
        super().__init__('locomotion')
        # joy command publisher
        self.joy_command = self.create_publisher(Joy,"/joy",10)
        self.robot_command = self.create_publisher(RobotCommand,"/robot_cmd",10)

        # coordinate subscriber
        self.coordinate_sub = self.create_subscription(DetectCoordinates,"/coordinates",self.coordinate_callback,10)

        # velocity command publisher
        self.vel_command = self.create_publisher(Twist,"vel_cmd",10)

        # initial state of joy
        self.axes = [ -0.0, -0.0 ,1.0, -0.0, -0.0, 1.0, 0.0, 0.0]
        self.buttons = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
        
        self.max_linear_velocity = 0.8
        self.max_angular_velocity = 0.4
        
        # avoid collisions
        self.safe_mode = True
        self.istest = True
        self.depth_sub = self.create_subscription(Image,'/realsense_camera_node/sn036222070655/depth/u16/image_raw',self.depth_callback,10)
        self.is_safe = True
        # 480*640
        self.detection_range = 320
        self.detection_height = 320
        self.tracking_object = None
        self.tracking_object_index = 0
        self.detection_object = ['tv','bottle']
        self.distance_threshold = 1.0
        self.is_tracking = False
        self.missing_count = 0
        self.switch_to_walk()
        
        self.last_linear_velocity = 0.0
        self.last_angular_velocity = 0.0
        
        print("Locomotion Started!")
        
    def depth_callback(self, msg):
        if self.is_tracking and self.safe_mode:
            img_data = np.frombuffer(msg.data,dtype=np.uint16)
            depth_image = img_data.reshape((480,640))
            depth_frame = np.array(depth_image,dtype=np.float32)*0.001
            mean, indice = self.find_mean_and_indices_of_smallest_15_elements(depth_frame)
            
            if mean < 1.0:
                print(f"indice of cloest:{indice}")
                print("find obstacles")
                self.is_safe = False

                # stop the robot
                for i in range(10):
                    self.send_velocity(0.0,0.0,0.0)

                time.sleep(0.5)
                self.switch_to_standing()
                for i in range(5):
                    time.sleep(1)
                    self.move_head("random")

                # rotate
                if np.mean(indice)>320:
                    self.switch_to_walk()
                    
                    for i in range(5):
                        self.send_velocity(-0.2,0.0,0.4)
                else:
                    self.switch_to_walk()
                    for i in range(5):
                        self.send_velocity(-0.2,0.0,-0.4)
            else:
                self.is_safe = True

    def send_velocity(self,x,y,z):
        velocity_msg = Twist()
        self.last_linear_velocity = 0.5 * self.last_linear_velocity + 0.5 * x
        x = self.last_linear_velocity

        self.last_angular_velocity = 0.5 * self.last_angular_velocity + 0.5 * z
        z = self.last_angular_velocity
        velocity_msg.linear.x = float(x)
        velocity_msg.linear.y = float(y)
        velocity_msg.angular.z = float(z)
        if self.istest:
            pass
        else:
            self.vel_command.publish(velocity_msg)
        self.get_logger().info('Publishing velocity: x=%f, y=%f, z=%f' % (x, y, z))
    
    def coordinate_callback(self, msg):
        # implement your locomotion logic here
        self.tracking_object = self.detection_object[self.tracking_object_index]

        if self.is_safe:
            # find tv
            if self.tracking_object in msg.name:
                self.missing_count = 0
                self.is_tracking = True
                index = msg.name.index(self.tracking_object)
                print(f"{self.tracking_object} has been seen!")
                if msg.coordinates[index].z > self.distance_threshold:
                    x  =0.5 * self.max_linear_velocity * (1 - math.exp(-msg.coordinates[index].z ))
                else:
                    x = 0.0
                
                if msg.coordinates[index].x >=0:
                    
                    z = -self.max_angular_velocity* (1 - math.exp(-msg.coordinates[index].x ))
                else:
                    z = self.max_angular_velocity* (1 - math.exp(msg.coordinates[index].x ))
                print(f"z:{msg.coordinates[index].x}")
                if 0< msg.coordinates[index].z <= self.distance_threshold and 0<= msg.coordinates[index].x < 0.3:
                    print("Finish tracking")
                    self.send_velocity(0.0,0.0,0.0)
                    self.switch_to_standing()
                    self.is_tracking = False
                    self.move_head("front")
                    self.move_head('left')
                    self.move_head('right')
                    time.sleep(1)
                    self.switch_to_walking() 
                    

                    self.tracking_object_index += 1
                    if self.tracking_object_index < len(self.detection_object):
                    # rotate
                        self.send_velocity(0,0,self.max_angular_velocity)
                    else:
                        print("task completed successfully1")
                        self.switch_to_standing()
                        self.destroy_node()
                    
                else:
                    print("publishing velocity")
                    self.send_velocity(x,0.0,z)
            else:
                print(f"No {self.tracking_object} has been seen!")
                self.missing_count+=1
                if self.missing_count > 5:
                    self.send_velocity(0,0,self.max_angular_velocity)
        else:
            print("Unsafe to start locomotion!")



    def move_head(self,direction):
        # input direction: front back left right random
        joy_msg = Joy()
        axes_temp = copy.deepcopy(self.axes)
        buttons_temp  = copy.deepcopy(self.buttons)
        if direction == "front":
            axes_temp[4] = random.uniform(0,1)
        elif direction == "back":
            axes_temp[4] = random.uniform(-1,0)
        elif direction == "left":
            axes_temp[3] = random.uniform(0,1)
        elif direction == "right":
            axes_temp[3] = random.uniform(-1,0)
        elif direction == "random":
            axes_temp[3] = random.uniform(-1,1)
            axes_temp[4] = random.uniform(-1,1)

        for i in range(2):
            print("moving head")
            self.joy_command.publish(joy_msg)
    def switch_to_walk(self):
        # change the state of the robot to walking
        msg = RobotCommand()
        msg.target_state = 4
        if self.istest:
            print("switch to walk")
        else:
            self.robot_command.publish(msg)
    
    def switch_to_standing(self):
        # change the state of the robot to standing
        msg = RobotCommand()
        msg.target_state = 3
        if self.istest:
            print("switch to standing")
        else:
            self.robot_command.publish(msg)

    def find_mean_and_indices_of_smallest_15_elements(self, array):
        # 提取第320行
        row = array[319, :]  # 索引从0开始，所以第320行的索引是319

        # 找到最小的15个元素的索引
        smallest_15_indices = np.argsort(row)[:15]

        # 使用这些索引找到最小的15个元素
        smallest_15_elements = row[smallest_15_indices]

        # 计算这些元素的均值
        mean_value = np.mean(smallest_15_elements)

        # 返回均值和列索引
        return mean_value, smallest_15_indices


def main(args=None):
    rclpy.init(args=args)
    client = Locomotion()
    print("start locomotion node!")
    rclpy.spin(client)
    client.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()