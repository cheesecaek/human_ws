// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from myinterfaces:srv/Tag.idl
// generated code does not contain a copyright notice

#ifndef MYINTERFACES__SRV__DETAIL__TAG__STRUCT_HPP_
#define MYINTERFACES__SRV__DETAIL__TAG__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'id'
// Member 'action'
#include "std_msgs/msg/detail/int8__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__myinterfaces__srv__Tag_Request __attribute__((deprecated))
#else
# define DEPRECATED__myinterfaces__srv__Tag_Request __declspec(deprecated)
#endif

namespace myinterfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Tag_Request_
{
  using Type = Tag_Request_<ContainerAllocator>;

  explicit Tag_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : id(_init),
    action(_init)
  {
    (void)_init;
  }

  explicit Tag_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : id(_alloc, _init),
    action(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _id_type =
    std_msgs::msg::Int8_<ContainerAllocator>;
  _id_type id;
  using _action_type =
    std_msgs::msg::Int8_<ContainerAllocator>;
  _action_type action;

  // setters for named parameter idiom
  Type & set__id(
    const std_msgs::msg::Int8_<ContainerAllocator> & _arg)
  {
    this->id = _arg;
    return *this;
  }
  Type & set__action(
    const std_msgs::msg::Int8_<ContainerAllocator> & _arg)
  {
    this->action = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    myinterfaces::srv::Tag_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const myinterfaces::srv::Tag_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<myinterfaces::srv::Tag_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<myinterfaces::srv::Tag_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      myinterfaces::srv::Tag_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<myinterfaces::srv::Tag_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      myinterfaces::srv::Tag_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<myinterfaces::srv::Tag_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<myinterfaces::srv::Tag_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<myinterfaces::srv::Tag_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__myinterfaces__srv__Tag_Request
    std::shared_ptr<myinterfaces::srv::Tag_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__myinterfaces__srv__Tag_Request
    std::shared_ptr<myinterfaces::srv::Tag_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Tag_Request_ & other) const
  {
    if (this->id != other.id) {
      return false;
    }
    if (this->action != other.action) {
      return false;
    }
    return true;
  }
  bool operator!=(const Tag_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Tag_Request_

// alias to use template instance with default allocator
using Tag_Request =
  myinterfaces::srv::Tag_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace myinterfaces


#ifndef _WIN32
# define DEPRECATED__myinterfaces__srv__Tag_Response __attribute__((deprecated))
#else
# define DEPRECATED__myinterfaces__srv__Tag_Response __declspec(deprecated)
#endif

namespace myinterfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Tag_Response_
{
  using Type = Tag_Response_<ContainerAllocator>;

  explicit Tag_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->state = false;
    }
  }

  explicit Tag_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->state = false;
    }
  }

  // field types and members
  using _state_type =
    bool;
  _state_type state;

  // setters for named parameter idiom
  Type & set__state(
    const bool & _arg)
  {
    this->state = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    myinterfaces::srv::Tag_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const myinterfaces::srv::Tag_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<myinterfaces::srv::Tag_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<myinterfaces::srv::Tag_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      myinterfaces::srv::Tag_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<myinterfaces::srv::Tag_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      myinterfaces::srv::Tag_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<myinterfaces::srv::Tag_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<myinterfaces::srv::Tag_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<myinterfaces::srv::Tag_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__myinterfaces__srv__Tag_Response
    std::shared_ptr<myinterfaces::srv::Tag_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__myinterfaces__srv__Tag_Response
    std::shared_ptr<myinterfaces::srv::Tag_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Tag_Response_ & other) const
  {
    if (this->state != other.state) {
      return false;
    }
    return true;
  }
  bool operator!=(const Tag_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Tag_Response_

// alias to use template instance with default allocator
using Tag_Response =
  myinterfaces::srv::Tag_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace myinterfaces

namespace myinterfaces
{

namespace srv
{

struct Tag
{
  using Request = myinterfaces::srv::Tag_Request;
  using Response = myinterfaces::srv::Tag_Response;
};

}  // namespace srv

}  // namespace myinterfaces

#endif  // MYINTERFACES__SRV__DETAIL__TAG__STRUCT_HPP_
