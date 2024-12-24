// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from myinterfaces:srv/Humancoordinates.idl
// generated code does not contain a copyright notice

#ifndef MYINTERFACES__SRV__DETAIL__HUMANCOORDINATES__STRUCT_HPP_
#define MYINTERFACES__SRV__DETAIL__HUMANCOORDINATES__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'camera_info'
#include "sensor_msgs/msg/detail/camera_info__struct.hpp"
// Member 'image'
// Member 'depth_image'
#include "sensor_msgs/msg/detail/image__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__myinterfaces__srv__Humancoordinates_Request __attribute__((deprecated))
#else
# define DEPRECATED__myinterfaces__srv__Humancoordinates_Request __declspec(deprecated)
#endif

namespace myinterfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Humancoordinates_Request_
{
  using Type = Humancoordinates_Request_<ContainerAllocator>;

  explicit Humancoordinates_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : camera_info(_init),
    image(_init),
    depth_image(_init)
  {
    (void)_init;
  }

  explicit Humancoordinates_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : camera_info(_alloc, _init),
    image(_alloc, _init),
    depth_image(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _camera_info_type =
    sensor_msgs::msg::CameraInfo_<ContainerAllocator>;
  _camera_info_type camera_info;
  using _image_type =
    sensor_msgs::msg::Image_<ContainerAllocator>;
  _image_type image;
  using _depth_image_type =
    sensor_msgs::msg::Image_<ContainerAllocator>;
  _depth_image_type depth_image;

  // setters for named parameter idiom
  Type & set__camera_info(
    const sensor_msgs::msg::CameraInfo_<ContainerAllocator> & _arg)
  {
    this->camera_info = _arg;
    return *this;
  }
  Type & set__image(
    const sensor_msgs::msg::Image_<ContainerAllocator> & _arg)
  {
    this->image = _arg;
    return *this;
  }
  Type & set__depth_image(
    const sensor_msgs::msg::Image_<ContainerAllocator> & _arg)
  {
    this->depth_image = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    myinterfaces::srv::Humancoordinates_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const myinterfaces::srv::Humancoordinates_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<myinterfaces::srv::Humancoordinates_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<myinterfaces::srv::Humancoordinates_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      myinterfaces::srv::Humancoordinates_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<myinterfaces::srv::Humancoordinates_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      myinterfaces::srv::Humancoordinates_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<myinterfaces::srv::Humancoordinates_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<myinterfaces::srv::Humancoordinates_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<myinterfaces::srv::Humancoordinates_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__myinterfaces__srv__Humancoordinates_Request
    std::shared_ptr<myinterfaces::srv::Humancoordinates_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__myinterfaces__srv__Humancoordinates_Request
    std::shared_ptr<myinterfaces::srv::Humancoordinates_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Humancoordinates_Request_ & other) const
  {
    if (this->camera_info != other.camera_info) {
      return false;
    }
    if (this->image != other.image) {
      return false;
    }
    if (this->depth_image != other.depth_image) {
      return false;
    }
    return true;
  }
  bool operator!=(const Humancoordinates_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Humancoordinates_Request_

// alias to use template instance with default allocator
using Humancoordinates_Request =
  myinterfaces::srv::Humancoordinates_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace myinterfaces


// Include directives for member types
// Member 'coordinate'
#include "geometry_msgs/msg/detail/point__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__myinterfaces__srv__Humancoordinates_Response __attribute__((deprecated))
#else
# define DEPRECATED__myinterfaces__srv__Humancoordinates_Response __declspec(deprecated)
#endif

namespace myinterfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Humancoordinates_Response_
{
  using Type = Humancoordinates_Response_<ContainerAllocator>;

  explicit Humancoordinates_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : coordinate(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->response = false;
    }
  }

  explicit Humancoordinates_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : coordinate(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->response = false;
    }
  }

  // field types and members
  using _coordinate_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _coordinate_type coordinate;
  using _response_type =
    bool;
  _response_type response;

  // setters for named parameter idiom
  Type & set__coordinate(
    const geometry_msgs::msg::Point_<ContainerAllocator> & _arg)
  {
    this->coordinate = _arg;
    return *this;
  }
  Type & set__response(
    const bool & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    myinterfaces::srv::Humancoordinates_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const myinterfaces::srv::Humancoordinates_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<myinterfaces::srv::Humancoordinates_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<myinterfaces::srv::Humancoordinates_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      myinterfaces::srv::Humancoordinates_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<myinterfaces::srv::Humancoordinates_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      myinterfaces::srv::Humancoordinates_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<myinterfaces::srv::Humancoordinates_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<myinterfaces::srv::Humancoordinates_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<myinterfaces::srv::Humancoordinates_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__myinterfaces__srv__Humancoordinates_Response
    std::shared_ptr<myinterfaces::srv::Humancoordinates_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__myinterfaces__srv__Humancoordinates_Response
    std::shared_ptr<myinterfaces::srv::Humancoordinates_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Humancoordinates_Response_ & other) const
  {
    if (this->coordinate != other.coordinate) {
      return false;
    }
    if (this->response != other.response) {
      return false;
    }
    return true;
  }
  bool operator!=(const Humancoordinates_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Humancoordinates_Response_

// alias to use template instance with default allocator
using Humancoordinates_Response =
  myinterfaces::srv::Humancoordinates_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace myinterfaces

namespace myinterfaces
{

namespace srv
{

struct Humancoordinates
{
  using Request = myinterfaces::srv::Humancoordinates_Request;
  using Response = myinterfaces::srv::Humancoordinates_Response;
};

}  // namespace srv

}  // namespace myinterfaces

#endif  // MYINTERFACES__SRV__DETAIL__HUMANCOORDINATES__STRUCT_HPP_
