from launch import LaunchDescription
from launch_ros.actions import Node
def generate_launch_description():
    node1 = Node(
        package = 'follow',
        executable = 'rotate_human_node'
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

    launch_description = LaunchDescription(
        [node1, node2, node3, node4, node5, node6]
    )

    return launch_description
