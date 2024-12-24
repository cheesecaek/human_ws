import rclpy
from rclpy.node import Node
import time
from myinterfaces.srv import Headcontrol
from std_msgs.msg import Int8, Bool
import threading
import random
from custom_msg.msg import RobotCommand
class RobotHeadClient(Node):
    def __init__(self):
        super().__init__('robot_head_client')

        self.nod = Int8()
        self.nod.data = 0
        self.is_speaking = True
        self.act = True
        
        self.head_action_pub = self.create_publisher(Bool, 'head_action', 10)
        self.head_client = self.create_client(Headcontrol, 'head_control_service')
        self.answer_action_sub = self.create_subscription(Bool, '/answer_action_request', self.answer_action_callback, 10)
        self.ready_callback = self.create_subscription(Bool, '/ready_or_not', self.ready_callback, 10)
        self.robot_cmd_sub = self.create_subscription(RobotCommand, '/robot_cmd', self.robot_cmd_callback, 10)
        # 等待服务端启动
        while not self.head_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Waiting for head_control_service to become available...')

        self.get_logger().info('Connected to head_control_service')
        
    def send_head_request(self, action):
        # 创建服务请求
        request = Headcontrol.Request()
        request.action = action
        is_head_action = Bool()
        is_head_action.data = False #False时不能进入下一阶段
        self.head_action_pub.publish(is_head_action)
        # 发送请求并等待响应
        future = self.head_client.call_async(request)
        # rclpy.spin_until_future_complete(self, future)
        future.add_done_callback(self.head_server_callback)

    def head_server_callback(self,future):
        response = future.result()
        self.get_logger().info(f'{response}')
        if future.result() is not None:
            self.get_logger().info(f'Server response: success={future.result().success}"')
            
        else:
            self.get_logger().error('Service call failed!')
    def answer_action_callback(self, msg):
        if msg: self.send_head_request(self.nod)
        
    def robot_cmd_callback(self, msg):
        self.get_logger().info("receive state ")
        if msg and msg.target_state == 3: self.act = True
        elif msg and msg.target_state == 4: self.act = False

    def ready_callback(self, msg):
        self.get_logger().info("receive ready msg")
        if msg and msg.data == True:
            self.is_speaking = True
        elif msg and msg.data == False:
            self.is_speaking = False

    def random_action(self):
        while 1:
            
            if self.is_speaking and self.act:
                
                sleep_time = random.choice(range(10, 15))
                action_order = Int8()
                action_order.data = random.choice(range(1, 8))
                self.send_head_request(action_order)
                
                
                time.sleep(sleep_time)
                self.get_logger().info("random")

def main(args=None):
    rclpy.init(args=args)

    # 创建客户端节点
    client = RobotHeadClient()
    Thread1 = threading.Thread(target = client.random_action)
    Thread1.start()
    rclpy.spin(client)
    Thread1.join()
    client.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()