// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from myinterfaces:srv/Tag.idl
// generated code does not contain a copyright notice

#ifndef MYINTERFACES__SRV__DETAIL__TAG__BUILDER_HPP_
#define MYINTERFACES__SRV__DETAIL__TAG__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "myinterfaces/srv/detail/tag__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace myinterfaces
{

namespace srv
{

namespace builder
{

class Init_Tag_Request_action
{
public:
  explicit Init_Tag_Request_action(::myinterfaces::srv::Tag_Request & msg)
  : msg_(msg)
  {}
  ::myinterfaces::srv::Tag_Request action(::myinterfaces::srv::Tag_Request::_action_type arg)
  {
    msg_.action = std::move(arg);
    return std::move(msg_);
  }

private:
  ::myinterfaces::srv::Tag_Request msg_;
};

class Init_Tag_Request_id
{
public:
  Init_Tag_Request_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Tag_Request_action id(::myinterfaces::srv::Tag_Request::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_Tag_Request_action(msg_);
  }

private:
  ::myinterfaces::srv::Tag_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::myinterfaces::srv::Tag_Request>()
{
  return myinterfaces::srv::builder::Init_Tag_Request_id();
}

}  // namespace myinterfaces


namespace myinterfaces
{

namespace srv
{

namespace builder
{

class Init_Tag_Response_state
{
public:
  Init_Tag_Response_state()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::myinterfaces::srv::Tag_Response state(::myinterfaces::srv::Tag_Response::_state_type arg)
  {
    msg_.state = std::move(arg);
    return std::move(msg_);
  }

private:
  ::myinterfaces::srv::Tag_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::myinterfaces::srv::Tag_Response>()
{
  return myinterfaces::srv::builder::Init_Tag_Response_state();
}

}  // namespace myinterfaces

#endif  // MYINTERFACES__SRV__DETAIL__TAG__BUILDER_HPP_
