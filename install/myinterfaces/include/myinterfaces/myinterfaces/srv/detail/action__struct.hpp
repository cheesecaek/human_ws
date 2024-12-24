// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from myinterfaces:srv/Action.idl
// generated code does not contain a copyright notice

#ifndef MYINTERFACES__SRV__DETAIL__ACTION__STRUCT_HPP_
#define MYINTERFACES__SRV__DETAIL__ACTION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__myinterfaces__srv__Action_Request __attribute__((deprecated))
#else
# define DEPRECATED__myinterfaces__srv__Action_Request __declspec(deprecated)
#endif

namespace myinterfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Action_Request_
{
  using Type = Action_Request_<ContainerAllocator>;

  explicit Action_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->linear_x = 0.0;
      this->linear_y = 0.0;
      this->linear_z = 0.0;
      this->angular_x = 0.0;
      this->angular_y = 0.0;
      this->angular_z = 0.0;
      this->duration = 0.0;
    }
  }

  explicit Action_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->linear_x = 0.0;
      this->linear_y = 0.0;
      this->linear_z = 0.0;
      this->angular_x = 0.0;
      this->angular_y = 0.0;
      this->angular_z = 0.0;
      this->duration = 0.0;
    }
  }

  // field types and members
  using _linear_x_type =
    double;
  _linear_x_type linear_x;
  using _linear_y_type =
    double;
  _linear_y_type linear_y;
  using _linear_z_type =
    double;
  _linear_z_type linear_z;
  using _angular_x_type =
    double;
  _angular_x_type angular_x;
  using _angular_y_type =
    double;
  _angular_y_type angular_y;
  using _angular_z_type =
    double;
  _angular_z_type angular_z;
  using _duration_type =
    double;
  _duration_type duration;

  // setters for named parameter idiom
  Type & set__linear_x(
    const double & _arg)
  {
    this->linear_x = _arg;
    return *this;
  }
  Type & set__linear_y(
    const double & _arg)
  {
    this->linear_y = _arg;
    return *this;
  }
  Type & set__linear_z(
    const double & _arg)
  {
    this->linear_z = _arg;
    return *this;
  }
  Type & set__angular_x(
    const double & _arg)
  {
    this->angular_x = _arg;
    return *this;
  }
  Type & set__angular_y(
    const double & _arg)
  {
    this->angular_y = _arg;
    return *this;
  }
  Type & set__angular_z(
    const double & _arg)
  {
    this->angular_z = _arg;
    return *this;
  }
  Type & set__duration(
    const double & _arg)
  {
    this->duration = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    myinterfaces::srv::Action_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const myinterfaces::srv::Action_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<myinterfaces::srv::Action_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<myinterfaces::srv::Action_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      myinterfaces::srv::Action_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<myinterfaces::srv::Action_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      myinterfaces::srv::Action_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<myinterfaces::srv::Action_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<myinterfaces::srv::Action_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<myinterfaces::srv::Action_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__myinterfaces__srv__Action_Request
    std::shared_ptr<myinterfaces::srv::Action_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__myinterfaces__srv__Action_Request
    std::shared_ptr<myinterfaces::srv::Action_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Action_Request_ & other) const
  {
    if (this->linear_x != other.linear_x) {
      return false;
    }
    if (this->linear_y != other.linear_y) {
      return false;
    }
    if (this->linear_z != other.linear_z) {
      return false;
    }
    if (this->angular_x != other.angular_x) {
      return false;
    }
    if (this->angular_y != other.angular_y) {
      return false;
    }
    if (this->angular_z != other.angular_z) {
      return false;
    }
    if (this->duration != other.duration) {
      return false;
    }
    return true;
  }
  bool operator!=(const Action_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Action_Request_

// alias to use template instance with default allocator
using Action_Request =
  myinterfaces::srv::Action_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace myinterfaces


#ifndef _WIN32
# define DEPRECATED__myinterfaces__srv__Action_Response __attribute__((deprecated))
#else
# define DEPRECATED__myinterfaces__srv__Action_Response __declspec(deprecated)
#endif

namespace myinterfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Action_Response_
{
  using Type = Action_Response_<ContainerAllocator>;

  explicit Action_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  explicit Action_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    myinterfaces::srv::Action_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const myinterfaces::srv::Action_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<myinterfaces::srv::Action_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<myinterfaces::srv::Action_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      myinterfaces::srv::Action_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<myinterfaces::srv::Action_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      myinterfaces::srv::Action_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<myinterfaces::srv::Action_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<myinterfaces::srv::Action_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<myinterfaces::srv::Action_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__myinterfaces__srv__Action_Response
    std::shared_ptr<myinterfaces::srv::Action_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__myinterfaces__srv__Action_Response
    std::shared_ptr<myinterfaces::srv::Action_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Action_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    return true;
  }
  bool operator!=(const Action_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Action_Response_

// alias to use template instance with default allocator
using Action_Response =
  myinterfaces::srv::Action_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace myinterfaces

namespace myinterfaces
{

namespace srv
{

struct Action
{
  using Request = myinterfaces::srv::Action_Request;
  using Response = myinterfaces::srv::Action_Response;
};

}  // namespace srv

}  // namespace myinterfaces

#endif  // MYINTERFACES__SRV__DETAIL__ACTION__STRUCT_HPP_
