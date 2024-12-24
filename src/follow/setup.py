from setuptools import find_packages, setup

package_name = 'follow'

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
            "tag_server = follow.tag_server:main",
            "rotate_human_node = follow.rotate_human_server: main",
            "robot_head_controller = follow.head_server:main",
            "camerainfo = follow.camerainfo_tag:main",
            "head_client = follow.head_client:main"
        ],
    },
)
