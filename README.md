# human_ws
for the ostrich

拉取本文件后，请先在`/src`目录下<br>
`git clone https://github.com/christianrauch/apriltag_ros.git`

为防止环境太乱了，可以在运行这两个程序时看缺少哪个包，直接安装哪个包

人物跟踪运行方法：
```bash
cd human_ws
colcon build --packages-select follow
colcon build --packages-select human
source install/setup.bash
ros2 run human coordinates_publisher
ros2 run follow follow_human_node # 新开一个终端
```

human文件夹下的coordinates_publisher.py的功能为创建topic，发布人物坐标信息（深度图信息）<br>
follow文件夹下的follower.py的功能为跟踪人物