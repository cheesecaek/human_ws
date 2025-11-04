# human_ws
for the ostrich

After downloading the file，please <br>
`git clone https://github.com/christianrauch/apriltag_ros.git`
under `/src`

How to track Human：
```bash
cd human_ws
colcon build --packages-select follow
colcon build --packages-select human
source install/setup.bash
ros2 run human coordinates_publisher
ros2 run follow follow_human_node # in another terminate
```

`coordinates_publisher.py` under `human` is to create topic publishing human coordinates(depth pic)<br>

`follower.py` under `follow` is to track human
