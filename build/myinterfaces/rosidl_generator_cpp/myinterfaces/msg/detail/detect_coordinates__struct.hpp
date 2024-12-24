// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from myinterfaces:msg/DetectCoordinates.idl
// generated code does not contain a copyright notice

#ifndef MYINTERFACES__MSG__DETAIL__DETECT_COORDINATES__STRUCT_HPP_
#define MYINTERFACES__MSG__DETAIL__DETECT_COORDINATES__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'coordinates'
#include "geometry_msgs/msg/detail/point__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__myinterfaces__msg__DetectCoordinates __attribute__((deprecated))
#else
# define DEPRECATED__myinterfaces__msg__DetectCoordinates __declspec(deprecated)
#endif

namespace myinterfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct DetectCoordinates_
{
  using Type = DetectCoordinates_<ContainerAllocator>;

  explicit DetectCoordinates_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->detection = false;
    }
  }

  explicit DetectCoordinates_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->detection = false;
    }
  }

  // field types and members
  using _detection_type =
    bool;
  _detection_type detection;
  using _name_type =
    std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>>;
  _name_type name;
  using _coordinates_type =
    std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Point_<ContainerAllocator>>>;
  _coordinates_type coordinates;

  // setters for named parameter idiom
  Type & set__detection(
    const bool & _arg)
  {
    this->detection = _arg;
    return *this;
  }
  Type & set__name(
    const std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>> & _arg)
  {
    this->name = _arg;
    return *this;
  }
  Type & set__coordinates(
    const std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Point_<ContainerAllocator>>> & _arg)
  {
    this->coordinates = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    myinterfaces::msg::DetectCoordinates_<ContainerAllocator> *;
  using ConstRawPtr =
    const myinterfaces::msg::DetectCoordinates_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<myinterfaces::msg::DetectCoordinates_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<myinterfaces::msg::DetectCoordinates_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      myinterfaces::msg::DetectCoordinates_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<myinterfaces::msg::DetectCoordinates_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      myinterfaces::msg::DetectCoordinates_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<myinterfaces::msg::DetectCoordinates_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<myinterfaces::msg::DetectCoordinates_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<myinterfaces::msg::DetectCoordinates_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__myinterfaces__msg__DetectCoordinates
    std::shared_ptr<myinterfaces::msg::DetectCoordinates_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__myinterfaces__msg__DetectCoordinates
    std::shared_ptr<myinterfaces::msg::DetectCoordinates_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DetectCoordinates_ & other) const
  {
    if (this->detection != other.detection) {
      return false;
    }
    if (this->name != other.name) {
      return false;
    }
    if (this->coordinates != other.coordinates) {
      return false;
    }
    return true;
  }
  bool operator!=(const DetectCoordinates_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DetectCoordinates_

// alias to use template instance with default allocator
using DetectCoordinates =
  myinterfaces::msg::DetectCoordinates_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace myinterfaces

#endif  // MYINTERFACES__MSG__DETAIL__DETECT_COORDINATES__STRUCT_HPP_
