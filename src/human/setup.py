from setuptools import find_packages, setup

package_name = 'human'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='devon',
    maintainer_email='devon@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'start_nodes=human.launch.start_nodes:generate_launch_description',
            'human_coordinate_server_pcd = human.human_detection_pcd:main',
            'human_coordinate_client_pcd=human.human_client_pcd:main',
            'human_coordinate_server= human.human_detection:main',
            'human_coordinate_client=human.human_client:main',
            'coordinates_publisher = human.coordinates_publisher:main'
        ],
    },
)
