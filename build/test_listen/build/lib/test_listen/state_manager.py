'''
介绍流程为：
判断用户是否准备好开始聆听介绍（否：回答，并等待用户主动发出要求）->介绍->
询问是否有问题（否：->根据用户输入回答问题或者结束介绍->
询问是否准备开始参观->根据用户输入决定是否开始参观
'''

from myinterfaces.msg import State
import time
from geometry_msgs.msg import Twist
from custom_msg.msg import RobotCommand
from myinterfaces.srv import Headcontrol
from std_msgs.msg import Bool
from .introduction import self_information, self_introduction, diabetic_information, diabetic_introduction, six_information, six_introduction, unitree_information, unitree_introduction, arm_information, arm_introduction

class StateManager:
    def __init__(self, speech_handler, ai_client, next_state_pub, vel_pub, robot_pub ,ready_pub, head_client):
        self.speech_handler = speech_handler
        self.ai_client = ai_client

        self.vel_pub = vel_pub # 发布速度控制信息
        self.robot_pub = robot_pub # 发布机器人控制模式状态信息
        self.next_state_pub = next_state_pub # 发布接下来的tag与task信息
        self.ready_pub = ready_pub
        self.head_client = head_client
        
        self.state = 1  # 介绍与提问状态的切换
        self.back_vel = Twist()
        self.stop_vel = Twist()
        self.back_vel.linear.x = -0.1 #后退速度
        self.back_time = 5 #back time
        self.robot = RobotCommand()
        self.robot.target_state = 3 #机器人控制模式状态
        self.apriltag = 0

        self.intro_judge = '你的名字叫“鸵鸟”，是一位专业的智能导游助手，负责为游客提供信息、解答问题以及引导他们进行参观。你的任务是根据游客的输入，判断他们的意图，并准确归类为以下两种之一：\n1. 要求介绍展品 \n2. 还不用开始介绍展品 \n请仅回答一个明确的分类编号！例如：输入：“可以了”，输出：“1.”；输入：“请稍等一下”，输出：“2.”'
        self.ques_judge = '你的名字叫“鸵鸟”，你是一位专业的智能导游助手，负责为游客提供信息、解答问题以及引导他们进行参观。你的任务是根据游客的输入，判断他们的意图，并准确归类为以下三种之一：\n1. 向你提问\n2. 结束提问\n3. 请求开始参观\n4. 没有在和你说话\n请仅回答一个明确的分类编号!,例如：输入：“这两个机器人有什么区别呢”，输出：“1.”；输入“可以说说两个机器人的具体区别吗？”，输出“1.”；输入：“哦哦”，输出“2.”；输入：“我没有问题了”，输出“3.”；输入“这个东西好神奇”，输出“4.”'

        

    def send_head_request(self, action):
        # 创建服务请求
        request = Headcontrol.Request()
        request.action = action

        # 发送请求并等待响应
        future = self.client.call_async(request)
        rclpy.spin_until_future_complete(self.head_client, future)
        response = future.result()
        if future.result() is not None:
            self.get_logger().info(f'Head Control Server Response')
        else:
            self.get_logger().error('Head Control Service call failed!')

    def handle_input(self, user_input):
        """根据当前状态处理用户输入。"""
        if self.apriltag == 0:
            self.tag0(user_input)
        # elif self.apriltag == 1:
        #     self.tag1(user_input)
        elif self.apriltag == 2:
            self.tag2(user_input)
        elif self.apriltag == 3:
            self.tag3(user_input)
        elif self.apriltag == 4:
            self.tag4(user_input)
        elif self.apriltag == 5:
            self.tag5(user_input)
        elif self.apriltag == 6:
            self.tag6(user_input)


    def tag0(self, user_input):#开始，自我介绍
        if self.state == 0:
            self.introduction_0(user_input)
        elif self.state == 1:
            self.questions0(user_input)

    def introduction_0(self, user_input):#开始，自我介绍
        system_prompt = ("你的名字叫“鸵鸟”，是一位专业的智能导游助手，负责为游客提供信息、解答问题以及引导他们进行参观。你的任务是根据游客的输入，判断他们的意图，并准确归类为以下两种之一：\n1. 要求你介绍自己 \n2. 还不用开始介绍自己 \n请仅回答一个明确的分类编号！例如：输入：“鸵鸟你好”，输出：“1.”；输入：“你好”，输出：“1.”；输入：“这个东西是这样使用的”，输出：“2.”")
        response = self.ai_client.get_response(system_prompt, user_input)
        if response == "1.":
            answer1 = "你好！我是鸵鸟，负责为您介绍我的数据服务实验室里的同事们。"; answer2 = '等你想开始这次旅程时，请告诉我，我将带你游览这里，到时候请跟紧我哦！'
            self.speech_handler.speak(answer1+answer2)
            self.send_head_request
            self.state = 1
        elif response == "2.":
            self.speech_handler.speak("好的，等你准备好再告诉我吧！")

    def questions0(self, user_input):#开始，自我介绍
        system_prompt = ("你的名字叫“鸵鸟”，你是一位专业的智能导游助手，负责为游客提供信息、解答问题以及引导他们进行参观。你的任务是根据游客的输入，判断他们的意图，并准确归类为以下四种之一：\n1. 向你提问\n2. 结束提问\n3. 请求开始参观\n4. 询问和你的交互方式。\n请仅回答一个明确的分类编号!,例如：输入：“我该怎么和你互动呢”，输出：“4.”；输入“你今年多大了？”，输出“1.”；输入：“我们可以开始了”，输出“3.”")
        response = self.ai_client.get_response(system_prompt, user_input)
        if response == "1.":
            prompt = ''
            dialog = self.ai_client.get_response(prompt, user_input)
            self.speech_handler.speak(dialog)
        elif response == "2.":
            self.speech_handler.speak("好的，等您准备好，我们就去第一个同事那里！")
        elif response == "3.":
            self.speech_handler.speak("好的，我们开始参观吧！")
            self.state = 0
            self.apriltag = 2 
            next_state = State()  # 填充状态信息
            next_state.apriltag = 0
            next_state.task = 0
            # self.get_logger().info('123')
            print(1)
            ready_or_not = Bool()
            ready_or_not.data = False
            self.ready_pub.publish(ready_or_not)
            print(2)
            time.sleep(2)
            self.next_state_pub.publish(next_state)
        elif response == "4.":
            self.speech_handler.speak('''当你准备好的时候，请告诉我可以开始介绍了，到时候我会领着您拜访我的同事们，您只需要跟在我后面。
                                      当我介绍完一个同事后，您可以向我提问，我会尽力回答您的问题。''')
            
    # def tag1(self, user_input):#第一个，人形 更新：人形因为可能回不来，直接取消了
    #     if self.state == 0:
    #         request_to_begin = "请问您准备好了吗"
    #         self.speech_handler.speak(request_to_begin)
    #         self.introduction_1(user_input)
    #     elif self.state == 1:
    #         self.questions_1(user_input)
    
    # def introduction_1(self, user_input):#第一个，人形
    #     system_prompt = ("你的名字叫“鸵鸟”，是一位专业的智能导游助手，负责为游客提供信息、解答问题以及引导他们进行参观。你的任务是根据游客的输入，判断他们的意图，并准确归类为以下两种之一：\n1. 要求介绍展品 \n2. 还不用开始介绍展品 \n请仅回答一个明确的分类编号！例如：输入：“可以了”，输出：“1.”；输入：“请稍等一下”，输出：“2.”")
    #     response = self.ai_client.get_response(system_prompt, user_input)
    #     if response == "1.":
    #         answer1 = "信息内容"
    #         self.speech_handler.speak(answer1)
    #         time.sleep(1)
    #         end_statement = "这就是我这位同事的介绍信息了，您有什么问题可以问我哦！"
    #         self.speech_handler.speak(end_statement)
    #         self.state = 1
    #     elif response == "2.":
    #         self.speech_handler.speak("好的，等你准备好再告诉我吧！")

    # def questions_1(self, user_input):#第一个，人形1. 向你提问2. 结束提问3. 请求开始参观
    #     system_prompt = ques_judge
    #     response = self.ai_client.get_response(system_prompt, user_input)
    #     if response == "1.":
    #         prompt = '你的名字叫“鸵鸟”，你是一位专业的智能导游助手，现在已经6个月大了，平常喜欢在数据服务实验室中休息。之所以名字叫鸵鸟，是因为鸵鸟是一种非常聪明的鸟类，于是我就被设计成了鸵鸟的样子，并取名为鸵鸟。现在游客询问你的相关信息，你可以回答他们的问题。'
    #         dialog = self.ai_client.get_response(prompt, user_input)
    #         self.speech_handler.speak(dialog)
    #     elif response == "2.":
    #         self.speech_handler.speak("好的，等你准备好，我们就去下一个同事那里！")
    #     elif response == "3.":
    #         self.speech_handler.speak("好的，我们现在就拜访去下一位！")
    #         self.state = 0
    #         next_state = State()  # 填充状态信息
    #         self.apriltag = 2 
    #         next_state.apriltag = 1
    #         next_state.task =
    #  2
    # ready_or_not = Bool()
    #         ready_or_not.data = 0
    #         self.ready_pub.publish(ready_or_not)
    #         time.
    #         sleep(2)
    #         self.next_state_pub.publish(next_state)
            
    def tag2(self, user_input):#第二个，大小六足
        if self.state == 0:
            self.introduction_2(user_input)
        elif self.state == 1:
            self.questions_2(user_input)
    
    def introduction_2(self, user_input):#第1个，diabetic
        system_prompt = self.intro_judge
        response = self.ai_client.get_response(system_prompt, user_input)
        if response == "1.":
            self.speech_handler.speak('第一位同事在我身体右前方，旁边有一个小水瓶，您可以观察一下。')
            answer1 = diabetic_introduction
            self.speech_handler.speak(answer1)
            end_statement = '不过我与这位同事并不太熟悉，因为这位同事平时并不参与什么研究项目，一直以来不怎么活跃，因此我不能介绍得很详细，请你见谅。不过如果你有什么想详细问的问题，也可以直接告诉我！'
            self.speech_handler.speak(end_statement)
            self.state = 1
        elif response == "2.":
            self.speech_handler.speak("好的，等你准备好再告诉我吧！")

    def questions_2(self, user_input):#第1个，diabetic1. 向你提问2. 结束提问3. 请求开始参观
        system_prompt = self.ques_judge
        response = self.ai_client.get_response(system_prompt, user_input)
        if response == "1.":
            prompt = diabetic_information
            dialog = self.ai_client.get_response(prompt, user_input)
            self.speech_handler.speak(dialog)
            self.speech_handler.speak("不知道我有没有解释清楚呢？")
        elif response == "2.":
            self.speech_handler.speak("好的，等你准备好，我们就去下一位同事那里！")
        elif response == "3.":
            self.speech_handler.speak("好的，我们开始参观吧！")
            self.state = 0
            next_state = State()  # 填充状态信息
            self.apriltag = 3 
            next_state.apriltag = 0
            next_state.task = 1

            ready_or_not = Bool()
            ready_or_not.data = False
            self.ready_pub.publish(ready_or_not)
            time.sleep(2)
            
            self.next_state_pub.publish(next_state)

    def tag3(self, user_input):#第2个，six
        if self.state == 0:
            self.introduction_3(user_input)
        elif self.state == 1:
            self.questions_3(user_input)
    
    def introduction_3(self, user_input):#第2个，six
        system_prompt = self.intro_judge
        response = self.ai_client.get_response(system_prompt, user_input)
        if response == "1.":
            self.speech_handler.speak('现在这两位同事在我的右侧，是两位红色的六足机器人。')
            answer1 = six_introduction
            self.speech_handler.speak(answer1)
            end_statement = "这就是我这两位同事的介绍信息了，您有没有什么问题呢？"
            self.speech_handler.speak(end_statement)
            self.state = 1
        elif response == "2.":
            self.speech_handler.speak("好的，等你准备好再告诉我吧！")

    def questions_3(self, user_input):#第三个，小机械臂1. 向你提问2. 结束提问3. 请求开始参观
        system_prompt = self.ques_judge
        response = self.ai_client.get_response(system_prompt, user_input)
        if response == "1.":
            prompt = six_information
            dialog = self.ai_client.get_response(prompt, user_input)
            self.speech_handler.speak(dialog)
            self.self.speech_handler.speak("不知道我有没有解释清楚呢？")
        elif response == "2.":
            self.speech_handler.speak("好的，等你准备好，我们就去下一个同事那里！")
        elif response == "3.":
            self.speech_handler.speak("好的，那我们离开咯，请跟上我！")
            self.state = 0
            next_state = State()  # 填充状态信息
            self.apriltag = 4 
            next_state.apriltag = 3
            next_state.task = 0

            ready_or_not = Bool()
            ready_or_not.data = False
            self.ready_pub.publish(ready_or_not)
            time.sleep(2)
            
            self.next_state_pub.publish(next_state)

    def tag4(self, user_input):#第3个，大机械臂
        if self.state == 0:
            self.introduction_4(user_input)
        elif self.state == 1:
            self.questions_4(user_input)
    
    def introduction_4(self, user_input):#第3个，大机械臂
        system_prompt = self.intro_judge
        response = self.ai_client.get_response(system_prompt, user_input)
        if response == "1.":
            self.speech_handler.speak('现在要介绍的同事就是我身旁的这个体型庞大的机械臂，您可以近距离看一看他。')
            answer1 = arm_introduction
            self.speech_handler.speak(answer1)
            end_statement = "这就是我这位同事的介绍信息了，您有什么问题可以问我哦！"
            self.speech_handler.speak(end_statement)
            self.state = 1
        elif response == "2.":
            self.speech_handler.speak("好的，等你准备好再告诉我吧！")

    def questions_4(self, user_input):#第3个，大机械臂 1. 向你提问2. 结束提问3. 请求开始参观
        system_prompt = self.ques_judge
        response = self.ai_client.get_response(system_prompt, user_input)
        if response == "1.":
            prompt = arm_information
            dialog = self.ai_client.get_response(prompt, user_input)
            self.speech_handler.speak(dialog)
            self.self.speech_handler.speak("不知道我有没有解释清楚呢？")
        elif response == "2.":
            self.speech_handler.speak("好的，等你准备好，我们就去下一个同事那里！")
        elif response == "3.":
            self.speech_handler.speak("好，接下来是第五和第六位同事")
            self.state = 0
            next_state = State()  # 填充状态信息
            self.apriltag = 5 
            next_state.apriltag = 4
            next_state.task = 0

            ready_or_not = Bool()
            ready_or_not.data = False
            self.ready_pub.publish(ready_or_not)
            time.sleep(2)
            
            self.next_state_pub.publish(next_state)

    def tag5(self, user_input):#第五个，go1,go2
        if self.state == 0:
            self.introduction_5(user_input)
        elif self.state == 1:
            self.questions_5(user_input)
    
    def introduction_5(self, user_input):#第五个，go1,go2
        system_prompt = self.intro_judge
        response = self.ai_client.get_response(system_prompt, user_input)
        if response == "1.":
            self.self.speech_handler.speak("现在要介绍的这两位同事是我旁边这两位帅气的机械狗。")
            answer1 = unitree_introduction
            self.speech_handler.speak(answer1)
            end_statement = "这就是我这位同事的介绍信息了，您有什么问题可以问我哦！"
            self.speech_handler.speak(end_statement)
            self.state = 1
        elif response == "2.":
            self.speech_handler.speak("好的，等你准备好再告诉我吧！")

    def questions_5(self, user_input):#第五个，go1,go2 1. 向你提问2. 结束提问3. 请求开始参观
        system_prompt = self.ques_judge
        response = self.ai_client.get_response(system_prompt, user_input)
        if response == "1.":
            prompt = unitree_information
            dialog = self.ai_client.get_response(prompt, user_input)
            self.speech_handler.speak(dialog)
            self.self.speech_handler.speak("不知道我有没有解释清楚呢？")
        elif response == "2.":
            self.speech_handler.speak("好的，等你准备好，我们就去下一个同事那里！")
        elif response == "3.":
            self.speech_handler.speak("好的，那我们去拜访今天的最后一位！")
            self.state = 0
            next_state = State()  # 填充状态信息
            self.apriltag = next_state.apriltag = 4
            next_state.task = 1

            ready_or_not = Bool()
            ready_or_not.data = False
            self.ready_pub.publish(ready_or_not)
            time.sleep(2)
            
            self.next_state_pub.publish(next_state)

    def tag6(self, user_input):#最后一个，鸵鸟自己
        if self.state == 0:
            self.introduction_6(user_input)
        elif self.state == 1:
            self.questions_6(user_input)
    
    def introduction_6(self, user_input):#最后一个，鸵鸟自己
        system_prompt = self.intro_judge
        response = self.ai_client.get_response(system_prompt, user_input)
        if response == "1.":
            answer1 = "最后一个介绍对象就是我啦，我来自我们的校友企业行思无界公司.这是里平时我工作的地方。我平时除了当导游，也会做一些其他任务，比如辅助其他的实验室学生们完成他们的项目，帮助他们学习双足机器人的控制，或是参与一些多模态的学习任务。"
            self.speech_handler.speak(answer1)
            time.sleep(0.6)
            answer1 = "当然现在的我还有很多不足的地方，比如好像还是不够灵活，并且记性也不太好，但是我会慢慢改正这些问题的"
            self.speech_handler.speak(answer1)  
            time.sleep(0.6)
            end_statement = "这就是我的自我介绍啦，不知道今天有没有帮到你呢？"
            self.speech_handler.speak(end_statement)
            self.state = 1
        elif response == "2.":
            self.speech_handler.speak("好的，等你准备好再告诉我吧！")

    def questions_6(self, user_input):#最后一个，鸵鸟自己 
        system_prompt = ("你的名字叫“鸵鸟”，你是一位专业的智能导游助手，负责为游客提供信息、解答问题以及引导他们进行参观。现在，你结束了你的这次任务，在询问游客的反馈。请判断他们的反馈，并准确归类为以下两种之一：\n1. 满意\n2. 不满意\n请仅回答一个明确的分类编号!,例如：输入：“谢谢，我今天收获了很多”，输出：“1.”；输入“感觉还是有很多问题”，输出“2.”")
        response = self.ai_client.get_response(system_prompt, user_input)
        if response == "2.":
            self.speech_handler.speak("好的，请将您的问题告诉我的设计师，不过我会继续努力的，希望下次能够帮到你！")
        elif response == "1.":
            self.speech_handler.speak("好的，我很荣幸能够帮到你，希望你有一个愉快的一天！")
        