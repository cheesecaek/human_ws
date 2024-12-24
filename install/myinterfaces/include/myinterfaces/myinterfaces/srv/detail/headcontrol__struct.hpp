// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from myinterfaces:srv/Headcontrol.idl
// generated code does not contain a copyright notice

#ifndef MYINTERFACES__SRV__DETAIL__HEADCONTROL__STRUCT_HPP_
#define MYINTERFACES__SRV__DETAIL__HEADCONTROL__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'action'
#include "std_msgs/msg/detail/int8__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__myinterfaces__srv__Headcontrol_Request __attribute__((deprecated))
#else
# define DEPRECATED__myinterfaces__srv__Headcontrol_Request __declspec(deprecated)
#endif

namespace myinterfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Headcontrol_Request_
{
  using Type = Headcontrol_Request_<ContainerAllocator>;

  explicit Headcontrol_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : action(_init)
  {
    (void)_init;
  }

  explicit Headcontrol_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : action(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _action_type =
    std_msgs::msg::Int8_<ContainerAllocator>;
  _action_type action;

  // setters for named parameter idiom
  Type & set__action(
    const std_msgs::msg::Int8_<ContainerAllocator> & _arg)
  {
    this->action = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    myinterfaces::srv::Headcontrol_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const myinterfaces::srv::Headcontrol_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<myinterfaces::srv::Headcontrol_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<myinterfaces::srv::Headcontrol_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      myinterfaces::srv::Headcontrol_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<myinterfaces::srv::Headcontrol_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      myinterfaces::srv::Headcontrol_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<myinterfaces::srv::Headcontrol_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<myinterfaces::srv::Headcontrol_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<myinterfaces::srv::Headcontrol_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__myinterfaces__srv__Headcontrol_Request
    std::shared_ptr<myinterfaces::srv::Headcontrol_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__myinterfaces__srv__Headcontrol_Request
    std::shared_ptr<myinterfaces::srv::Headcontrol_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Headcontrol_Request_ & other) const
  {
    if (this->action != other.action) {
      return false;
    }
    return true;
  }
  bool operator!=(const Headcontrol_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Headcontrol_Request_

// alias to use template instance with default allocator
using Headcontrol_Request =
  myinterfaces::srv::Headcontrol_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace myinterfaces


#ifndef _WIN32
# define DEPRECATED__myinterfaces__srv__Headcontrol_Response __attribute__((deprecated))
#else
# define DEPRECATED__myinterfaces__srv__Headcontrol_Response __declspec(deprecated)
#endif

namespace myinterfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Headcontrol_Response_
{
  using Type = Headcontrol_Response_<ContainerAllocator>;

  explicit Headcontrol_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  explicit Headcontrol_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    myinterfaces::srv::Headcontrol_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const myinterfaces::srv::Headcontrol_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<myinterfaces::srv::Headcontrol_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<myinterfaces::srv::Headcontrol_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      myinterfaces::srv::Headcontrol_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<myinterfaces::srv::Headcontrol_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      myinterfaces::srv::Headcontrol_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<myinterfaces::srv::Headcontrol_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<myinterfaces::srv::Headcontrol_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<myinterfaces::srv::Headcontrol_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__myinterfaces__srv__Headcontrol_Response
    std::shared_ptr<myinterfaces::srv::Headcontrol_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__myinterfaces__srv__Headcontrol_Response
    std::shared_ptr<myinterfaces::srv::Headcontrol_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Headcontrol_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    return true;
  }
  bool operator!=(const Headcontrol_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Headcontrol_Response_

// alias to use template instance with default allocator
using Headcontrol_Response =
  myinterfaces::srv::Headcontrol_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace myinterfaces

namespace myinterfaces
{

namespace srv
{

struct Headcontrol
{
  using Request = myinterfaces::srv::Headcontrol_Request;
  using Response = myinterfaces::srv::Headcontrol_Response;
};

}  // namespace srv

}  // namespace myinterfaces

#endif  // MYINTERFACES__SRV__DETAIL__HEADCONTROL__STRUCT_HPP_
