from launch import LaunchDescription
from launch_ros.actions import Node
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
        package = 'follow',
        executable = "tag_server"
    )
    node6 = Node(
        package = 'human',
        executable = "coordinates_publisher"
    )
    include_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([
            PathJoinSubstitution([
                FindPackageShare('apriltag_ros'),  # 替换为你的包名
                'launch',
                'ostrich_36h11.launch.yml'
            ])
        ])
    ),

    launch_description = LaunchDescription(
        [node2, node3, node4, node6, include_launch]
    )

    return launch_description
