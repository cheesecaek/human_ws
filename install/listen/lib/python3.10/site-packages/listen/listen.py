from .tts import tts as speak   #tts is a function to convert text to speech
import rclpy
from rclpy.node import Node
from std_msgs.msg import String
from openai import OpenAI
import opneai
import os
import speech_recognition as sr
import threading
import time
from myinterfaces.msg import State
from geometry_msgs.msg import Twist
from custom_msg.msg import RobotCommand

class Listen(Node):
    def __init__(self):
        super().__init__("listen_node")
        self.state_pub = self.create_publisher(State, 'state', 10)
        self.client = OpenAI(
            api_key =  "sk-b148bc11ccc74fb89fe9b94776d3cad0",
            base_url = "https://dashscope.aliyuncs.com/compatible-mode/v1",)
        self.apriltag = 1
        self.task = 1
        self.talk = 1
        os.environ['HTTP_PROXY'] = 'http://127.0.0.1:7897'
        os.environ['HTTPS_PROXY'] = 'http://127.0.0.1:7897'
        self.system_tempt = [[['answer'], ['information']], 
                             [[], []], 
                             [[], []], 
                             [[], []], 
                             [[], []], 
                             [[], []]]
        self.state = [0, 0, 0]  #tag task situation
        self.statement = 0
        self.back_vel = Twist()
        self.back_vel.linear.x = -0.1 #后退速度
        self.back_time = 5 #back time
        self.vel_pub = self.create_publisher(Twist, 'vel_cmd', 10)
        self.robot = RobotCommand()

        self.robot_pub = self.create_publisher(String, 'robot_cmd', 10)

    def apriltag_callback(self, msg):
        if msg.data:
            self.apriltag = msg.data

    def record(self) -> string:
        r = sr.Recognizer()
        with sr.Microphone() as source:
            print("请说话:")
            audio = r.listen(source)
            try:
                text = r.recognize_google(audio, language='zh-CN')
                print("你说了: " + text)
            except sr.UnknownValueError:
                print("无法识别语音")
                text = ""
            except sr.RequestError as e:
                print("无法连接到语音识别服务; {0}".format(e))
                text = ""
        return text

    def judge_and_speak(self, text) -> string:
        if self.apriltag == 0:
            if self.statement == 0:
                #询问是否开始介绍
                completion = self.client.chat.completions.create(
                    model="qwen-plus",
                    messages=[
                        {'role': 'system', 'content': '你的名字叫“鸵鸟”，是一位专业的智能导游助手，负责为游客提供信息、解答问题以及引导他们进行参观。你的任务是根据游客的输入，判断他们的意图，并准确归类为以下两种之一：\n1. 要求你介绍自己 \n2. 还不用开始介绍自己 \n请仅回答一个明确的分类编号！例如：输入：“鸵鸟你好”，输出：“1.”；输入：“这个东西是这样使用的”，输出：“2.”'},
                        {'role': 'user', 'content': text}],
                )
                if completion.choices[0].message.content == "1.":#介绍自己
                    answer1 = "你好！我是鸵鸟，负责为您介绍我的数据服务实验室里的同事们。"; answer2 = '等你想开始这次旅程时，请告诉我，我将带你游览这里，到时候请跟紧我哦！'
                    speak(answer1); time.sleep(1); speak(answer2)
                    self.statement = 1
                elif completion.choices[0].message.content == "2.":#等待命令
                    return 0
            elif self.statement == 1:
                completion = self.client.chat.completions.create(
                    model="qwen-plus",
                    messages=[
                        {'role': 'system', 'content': '你的名字叫“鸵鸟”，你是一位专业的智能导游助手，负责为游客提供信息、解答问题以及引导他们进行参观。你的任务是根据游客的输入，判断他们的意图，并准确归类为以下四种之一：\n1. 向你提问\n2. 结束提问\n3. 请求开始参观\n4. 询问和你的交互方式。\n请仅回答一个明确的分类编号!,例如：输入：“我该怎么和你互动呢”，输出：“4.”；输入“你今年多大了？”，输出“1.”；输入：“我们可以开始了”，输出“3.”'},
                        {'role': 'user', 'content': text}],
                )
                if completion.choices[0].message.content == "1.":#对话提问
                    dialog = self.client.chat.completions.create(
                    model="qwen-plus",
                    messages=[
                        {'role': 'system', 'content': '你的名字叫“鸵鸟”，你是一位专业的智能导游助手，现在已经6个月大了，平常喜欢在数据服务实验室中休息。之所以名字叫鸵鸟，是因为鸵鸟是一种非常聪明的鸟类，于是我就被设计成了鸵鸟的样子，并取名为鸵鸟。现在游客询问你的相关信息，你可以回答他们的问题。'},
                        {'role': 'user', 'content': text}],
                )
                    answer = dialog.choices[0].message.content
                    speak(answer)
                elif completion.choices[0].message.content == "3.":#请求开始参观
                    answer = "好的，我们可以开始了，请跟紧我哦！"
                    speak(answer)
                    self.apriltag = 1
                    self.task = 1
                    next = State()
                    next.apriltag = self.apriltag
                    next.task = self.task
                    #输入下一阶段的状态
                    self.state_pub.publish(next)

        elif self.apriltag == 1:
            if self.statement == 0:
                #等待开始介绍
                completion = self.client.chat.completions.create(
                    model="qwen-plus",
                    messages=[
                        {'role': 'system', 'content': '你的名字叫“鸵鸟”，是一位专业的智能导游助手，负责为游客提供信息、解答问题以及引导他们进行参观。你的任务是根据游客的输入，判断他们的意图，并准确归类为以下两种之一：\n1. 要求介绍展品 \n2. 还不用开始介绍展品 \n请仅回答一个明确的分类编号！例如：输入：“可以了”，输出：“1.”；输入：“请稍等一下”，输出：“2.”'},
                        {'role': 'user', 'content': text}],
                )
                if completion.choices[0].message.content == "1.":#介绍展品
                    answer1 = "信息内容"
                    speak(answer1); time.sleep(1); speak(answer2)
                    self.statement = 1
                elif completion.choices[0].message.content == "2.":#等待命令
                    return 0
            elif self.statement == 1:
                completion = self.client.chat.completions.create(
                    model="qwen-plus",
                    messages=[
                        {'role': 'system', 'content': '你的名字叫“鸵鸟”，你是一位专业的智能导游助手，负责为游客提供信息、解答问题以及引导他们进行参观。你的任务是根据游客的输入，判断他们的意图，并准确归类为以下四种之一：\n1. 向你提问\n2. 结束提问\n3. 请求开始参观\n请仅回答一个明确的分类编号!,例如：输入：“我该怎么和你互动呢”，输出：“4.”；输入“你今年多大了？”，输出“1.”；输入：“我们可以开始了”，输出“3.”'},
                        {'role': 'user', 'content': text}],
                )
                if completion.choices[0].message.content == "1.":#对话提问
                    dialog = self.client.chat.completions.create(
                    model="qwen-plus",
                    messages=[
                        {'role': 'system', 'content': '展品的信息是：，现在游客在向你提问，你可以回答他们的问题。'},
                        {'role': 'user', 'content': text}],
                )
                    answer = dialog.choices[0].message.content
                    speak(answer)
                elif completion.choices[0].message.content == "2.": return 0#结束提问
                elif completion.choices[0].message.content == "3.":#请求开始参观
                    answer = "好的，我们可以开始了，请跟紧我哦！"
                    speak(answer)
                    self.apriltag = 1
                    self.task = 1
                    next = State()
                    #输入下一阶段的状态
                    self.state_pub.publish(next)


    def listen_and_answer(self):
        while self.talk == 1:
            text = self.record()
            if text:
                self.judge_and_speak(text)


def main(args = None):
    rclpy.init(args=args)
    listen_node = Listen()
    apriltag = threading.Thread(target=rclpy.spin, args=(listen_node,))
    l_and_a = threading.Thread(target=listen_node.listen_and_answer, args=())
    apriltag.start()
    l_and_a.start()
    apriltag.join()
    l_and_a.join()
    listen_node.destroy_node()
    rclpy.shutdown()

if __name__ == "__main__":
    main()