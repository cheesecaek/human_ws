import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Joy
import csv

class JoyDataRecorder(Node):
    def __init__(self):
        super().__init__('joy_data_recorder')

        # 创建一个订阅者，订阅指定的topic
        self.subscription = self.create_subscription(
            Joy,
            'joy',  # 替换为你的topic名称
            self.joy_callback,
            10
        )

        # 打开一个CSV文件用于写入
        self.file = open('/home/robot/joy_data8.csv', mode='w', newline='')
        self.csv_writer = csv.writer(self.file)

        # 写入CSV文件的表头
        self.csv_writer.writerow(['axes[0]', 'axes[1]', 'axes[3]', 'axes[4]'])
        self.get_logger().info("Joy data recorder initialized and recording to joy_data.csv")

    def joy_callback(self, msg):
        try:
            # 提取需要的数据
            axes_data = [
                msg.axes[0] if len(msg.axes) > 0 else None,
                msg.axes[1] if len(msg.axes) > 1 else None,
                msg.axes[3] if len(msg.axes) > 2 else None,
                msg.axes[4] if len(msg.axes) > 3 else None
            ]

            # 将数据写入CSV文件
            self.csv_writer.writerow(axes_data)

            # 日志输出记录
            self.get_logger().info(f"Recorded data: {axes_data}")
        except Exception as e:
            self.get_logger().error(f"Error processing Joy message: {e}")

    def destroy_node(self):
        # 在销毁节点之前关闭文件
        self.file.close()
        super().destroy_node()


def main(args=None):
    rclpy.init(args=args)
    
    joy_data_recorder = JoyDataRecorder()

    try:
        rclpy.spin(joy_data_recorder)
    except KeyboardInterrupt:
        pass
    finally:
        joy_data_recorder.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()