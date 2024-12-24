// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from myinterfaces:srv/Headcontrol.idl
// generated code does not contain a copyright notice

#ifndef MYINTERFACES__SRV__DETAIL__HEADCONTROL__BUILDER_HPP_
#define MYINTERFACES__SRV__DETAIL__HEADCONTROL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "myinterfaces/srv/detail/headcontrol__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace myinterfaces
{

namespace srv
{

namespace builder
{

class Init_Headcontrol_Request_action
{
public:
  Init_Headcontrol_Request_action()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::myinterfaces::srv::Headcontrol_Request action(::myinterfaces::srv::Headcontrol_Request::_action_type arg)
  {
    msg_.action = std::move(arg);
    return std::move(msg_);
  }

private:
  ::myinterfaces::srv::Headcontrol_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::myinterfaces::srv::Headcontrol_Request>()
{
  return myinterfaces::srv::builder::Init_Headcontrol_Request_action();
}

}  // namespace myinterfaces


namespace myinterfaces
{

namespace srv
{

namespace builder
{

class Init_Headcontrol_Response_success
{
public:
  Init_Headcontrol_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::myinterfaces::srv::Headcontrol_Response success(::myinterfaces::srv::Headcontrol_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::myinterfaces::srv::Headcontrol_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::myinterfaces::srv::Headcontrol_Response>()
{
  return myinterfaces::srv::builder::Init_Headcontrol_Response_success();
}

}  // namespace myinterfaces

#endif  // MYINTERFACES__SRV__DETAIL__HEADCONTROL__BUILDER_HPP_
