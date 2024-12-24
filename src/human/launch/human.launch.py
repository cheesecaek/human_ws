from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='human',
            executable='human_coordinate_server',
            name='human_coordinate_server'
        ),
        Node(
            package='human',
            executable='human_coordinate_client',
            name='human_coordinate_client'
        )
    ])