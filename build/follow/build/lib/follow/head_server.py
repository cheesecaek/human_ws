import rclpy
from rclpy.node import Node
from std_msgs.msg import Int8,Bool
from sensor_msgs.msg import Joy
from myinterfaces.srv import Headcontrol
import copy
import time
import csv
class RobotHeadController(Node):
    def __init__(self):
        super().__init__('robot_head_controller')

        self.server = self.create_service(Headcontrol, 'head_control_service', self.server_callback)
        self.head_action_pub = self.create_publisher(Bool, 'head_action', 10)
        self.publisher = self.create_publisher(Joy, '/joy', 10)
        # 动作控制成员变量
        self.button1 = -0.0#左边摇杆左右 脖子左右扭
        self.button2 = -0.0#同上，上下 脖子上下
        self.button3 = -0.0#右边摇杆左右 脖子侧摆
        self.button4 = -0.0#同上，上下 脖子前后

        self.axes = [ -0.0, -0.0 ,1.0, -0.0, -0.0, 1.0, 0.0, 0.0]
        self.buttons = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
        self.get_logger().info('RobotHeadController service node has been started.')

    def server_callback(self, request, response):
        # 根据接收到的服务请求数据，控制动作
        if request.action.data > 0:
            # 闲置动作
            self.get_logger().info('Action 1 triggered.')
            data = self.read_csv(f'/home/robot/joy_data{request.action.data}.csv')
            curren_index = 0
            while curren_index < len(data):
                row = data[curren_index]
                msg = Joy()
                msg.header.stamp = self.get_clock().now().to_msg()
                msg.axes = [row[0], row[1], 1.0, row[2], row[3], 1.0, 0.0, 0.0]
                msg.buttons = self.buttons
                self.publisher.publish(msg)
                time.sleep(0.01)
                curren_index += 1
            self.get_logger().info('oooooooo')
            time.sleep(3)
            is_head_action = Bool()
            is_head_action.data = True
            self.head_action_pub.publish(is_head_action)

        elif request.action.data == 0:#应答动作
            # 查询动作
            self.button4 = -1.0
            self.set_action(300)
            time.sleep(0.5)
            is_head_action = Bool()
            is_head_action.data = True
            self.head_action_pub.publish(is_head_action)

        else:
            self.get_logger().info('wrong number')
            response.success = False
            is_head_action = Bool()
            is_head_action.data = True
            self.head_action_pub.publish(is_head_action)
            return response
            
        # 响应客户端
        self.button1 = -0.0
        self.button2 = -0.0
        self.button3 = -0.0
        self.button4 = -0.0

        response.success = True
        return response

    def set_action(self, duration=100):
        # 设置动作参数并发布到 /joy
        axes_temp = copy.deepcopy(self.axes)
        buttons_temp  = copy.deepcopy(self.buttons)
        axes_temp[0] = self.button1
        axes_temp[1] = self.button2
        axes_temp[3] = self.button3
        axes_temp[4] = self.button4

        joy_msg = Joy()
        joy_msg.header.stamp = self.get_clock().now().to_msg()
        joy_msg.buttons = buttons_temp
        joy_msg.axes = axes_temp  

        for i in range(duration):
            time.sleep(0.01)  # 0.01s 发布一次
            self.publisher.publish(joy_msg)

    def read_csv(self, file_path):
        """读取CSV文件并返回从第一行有数据到最后一行有数据的行数据"""
        data = []
        try:
            with open(file_path, mode='r') as file:
                reader = csv.reader(file)
                next(reader)  # 跳过表头

                for row in reader:
                    # 检查当前行是否有有效数据（非空行）
                    if all(cell.strip() for cell in row):  # 确保每个单元格都有数据
                        data.append([float(val) for val in row])
            self.get_logger().info(f"Successfully extracted {len(data)} rows with valid data")
        except Exception as e:
            self.get_logger().error(f"Error reading CSV: {e}")
        return data

def main(args=None):
    rclpy.init(args=args)
    node = RobotHeadController()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()