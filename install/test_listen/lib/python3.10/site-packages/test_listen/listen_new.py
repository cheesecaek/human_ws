import rclpy
from rclpy.node import Node
from .speech_handler import SpeechHandler
from .openai_client import OpenAIClient
from .state_manager import StateManager
import threading
from custom_msg.msg import RobotCommand
from geometry_msgs.msg import Twist
from myinterfaces.msg import State
from myinterfaces.srv import Headcontrol
from std_msgs.msg import Bool, Int8

class Listen(Node):
    def __init__(self):
        super().__init__("listen_node")
        self.speech_handler = SpeechHandler()
        self.ai_client = OpenAIClient(
            base_url_input = "https://tzydemo1219.openai.azure.com/",
            api_key_input = "732a9a231689443eb067de5d345550fa"
        )
        self.state_pub = self.create_publisher(State, 'state', 10)#tag与任务标号
        self.vel_pub = self.create_publisher(Twist, 'vel_cmd', 10)#速度发布
        self.robot_pub = self.create_publisher(RobotCommand, 'robot_cmd', 10)#平衡站立与走路
        self.ready_pub = self.create_publisher(Bool, 'ready_or_not', 10)
        self.head_client = self.create_client(Headcontrol, 'head_control_service')#头部动作
        
        self.state_manager = StateManager(
            self.speech_handler,
            self.ai_client,
            self.state_pub,
            self.vel_pub,
            self.robot_pub,
            self.ready_pub,
            self.head_client
        )

        self.head_client = self.create_client(Headcontrol, 'head_control_service')
        # 等待服务端启动
        while not self.head_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Waiting for head_control_service to become available...')

        self.apriltag = 0
        self.ready = 1
        self.ask_for_begin = 1
        self.answer_action_request = Bool()
        self.answer_action_request.data = True
        self.ready_sub = self.create_subscription(Bool, '/ready_or_not', self.ready_callback, 10)
        self.task_sub = self.create_subscription(State, 'state', self.state_callback, 10)
        self.test_pub = self.create_publisher(Bool, 'test', 10)
        self.answer_action_pub = self.create_publisher(Bool, 'answer_action_request', 10)
        


    def ready_callback(self, msg):
        if msg:
            self.ready = msg.data
            if self.ready == True:
                self.ask_for_begin = 1

    def state_callback(self, msg):
        if msg:
            self.apriltag = msg.apriltag

    def send_head_request(self, action):
        # 创建服务请求
        request = Headcontrol.Request()
        request.action = action

        # 发送请求并等待响应
        future = self.head_client.call_async(request)

    def listen_and_answer(self):
        request_to_begin = ['实验开始', '需要等一会再开始介绍吗？', '请问您准备好了吗?', '请问您准备好了吗?', '请问您准备好了吗?', '请问您准备好了吗?']
        request_order = 0
        while 1: 
            if self.ready:
                if self.ask_for_begin:
                    self.speech_handler.speak(request_to_begin[request_order])
                    request_order += 1
                    self.ask_for_begin = 0
                user_input = self.speech_handler.record()
                self.get_logger().info('ready')
                if user_input:
                    self.answer_action_pub.publish(self.answer_action_request)
                    self.state_manager.handle_input(user_input)

def main(args=None):
    rclpy.init(args=args)
    listen_node = Listen()
    listen_thread = threading.Thread(target=listen_node.listen_and_answer)
    listen_thread.start()
    rclpy.spin(listen_node)
    listen_thread.join()
    listen_node.destroy_node()
    rclpy.shutdown()

if __name__ == "__main__":
    main()
