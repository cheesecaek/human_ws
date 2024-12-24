from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import PathJoinSubstitution
from launch_ros.substitutions import FindPackageShare
def generate_launch_description():
    node1 = Node(
        package = 'follow',
        executable = 'head_client'
    )

    node2 = Node(
        package = 'manager',
        executable = 'manager_node'
    )
    node3 = Node(
        package = 'follow',
        executable = 'camerainfo'
    )
    node4 = Node(
        package = 'follow',
        executable = 'robot_head_controller'
    )
    node5 = Node(
        package = 'test_listen',
        executable = "listen_new_node",
        name = 'listen',
        output = 'screen',
        prefix = ['xterm -hold -e']
    )
    node6 = Node(
        package = 'human',
        executable = "coordinates_publisher"
    )
    # include_launch = IncludeLaunchDescription(
    #     PythonLaunchDescriptionSource([
    #         PathJoinSubstitution([
    #             FindPackageShare('apriltag_ros'),  # 替换为你的包名
    #             'launch',
    #             'ostrich_36h11.launch.yml'
    #         ])
    #     ])
    # )

    launch_description = LaunchDescription(
        [node1, node2, node3, node4, node5, node6]
    )

    return launch_description
