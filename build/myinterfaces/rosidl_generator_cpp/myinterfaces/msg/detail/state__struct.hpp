// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from myinterfaces:msg/State.idl
// generated code does not contain a copyright notice

#ifndef MYINTERFACES__MSG__DETAIL__STATE__STRUCT_HPP_
#define MYINTERFACES__MSG__DETAIL__STATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__myinterfaces__msg__State __attribute__((deprecated))
#else
# define DEPRECATED__myinterfaces__msg__State __declspec(deprecated)
#endif

namespace myinterfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct State_
{
  using Type = State_<ContainerAllocator>;

  explicit State_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->apriltag = 0l;
      this->task = 0l;
    }
  }

  explicit State_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->apriltag = 0l;
      this->task = 0l;
    }
  }

  // field types and members
  using _apriltag_type =
    int32_t;
  _apriltag_type apriltag;
  using _task_type =
    int32_t;
  _task_type task;

  // setters for named parameter idiom
  Type & set__apriltag(
    const int32_t & _arg)
  {
    this->apriltag = _arg;
    return *this;
  }
  Type & set__task(
    const int32_t & _arg)
  {
    this->task = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    myinterfaces::msg::State_<ContainerAllocator> *;
  using ConstRawPtr =
    const myinterfaces::msg::State_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<myinterfaces::msg::State_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<myinterfaces::msg::State_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      myinterfaces::msg::State_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<myinterfaces::msg::State_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      myinterfaces::msg::State_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<myinterfaces::msg::State_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<myinterfaces::msg::State_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<myinterfaces::msg::State_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__myinterfaces__msg__State
    std::shared_ptr<myinterfaces::msg::State_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__myinterfaces__msg__State
    std::shared_ptr<myinterfaces::msg::State_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const State_ & other) const
  {
    if (this->apriltag != other.apriltag) {
      return false;
    }
    if (this->task != other.task) {
      return false;
    }
    return true;
  }
  bool operator!=(const State_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct State_

// alias to use template instance with default allocator
using State =
  myinterfaces::msg::State_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace myinterfaces

#endif  // MYINTERFACES__MSG__DETAIL__STATE__STRUCT_HPP_
