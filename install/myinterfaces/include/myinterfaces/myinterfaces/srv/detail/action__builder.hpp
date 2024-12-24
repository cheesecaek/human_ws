// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from myinterfaces:srv/Action.idl
// generated code does not contain a copyright notice

#ifndef MYINTERFACES__SRV__DETAIL__ACTION__BUILDER_HPP_
#define MYINTERFACES__SRV__DETAIL__ACTION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "myinterfaces/srv/detail/action__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace myinterfaces
{

namespace srv
{

namespace builder
{

class Init_Action_Request_duration
{
public:
  explicit Init_Action_Request_duration(::myinterfaces::srv::Action_Request & msg)
  : msg_(msg)
  {}
  ::myinterfaces::srv::Action_Request duration(::myinterfaces::srv::Action_Request::_duration_type arg)
  {
    msg_.duration = std::move(arg);
    return std::move(msg_);
  }

private:
  ::myinterfaces::srv::Action_Request msg_;
};

class Init_Action_Request_angular_z
{
public:
  explicit Init_Action_Request_angular_z(::myinterfaces::srv::Action_Request & msg)
  : msg_(msg)
  {}
  Init_Action_Request_duration angular_z(::myinterfaces::srv::Action_Request::_angular_z_type arg)
  {
    msg_.angular_z = std::move(arg);
    return Init_Action_Request_duration(msg_);
  }

private:
  ::myinterfaces::srv::Action_Request msg_;
};

class Init_Action_Request_angular_y
{
public:
  explicit Init_Action_Request_angular_y(::myinterfaces::srv::Action_Request & msg)
  : msg_(msg)
  {}
  Init_Action_Request_angular_z angular_y(::myinterfaces::srv::Action_Request::_angular_y_type arg)
  {
    msg_.angular_y = std::move(arg);
    return Init_Action_Request_angular_z(msg_);
  }

private:
  ::myinterfaces::srv::Action_Request msg_;
};

class Init_Action_Request_angular_x
{
public:
  explicit Init_Action_Request_angular_x(::myinterfaces::srv::Action_Request & msg)
  : msg_(msg)
  {}
  Init_Action_Request_angular_y angular_x(::myinterfaces::srv::Action_Request::_angular_x_type arg)
  {
    msg_.angular_x = std::move(arg);
    return Init_Action_Request_angular_y(msg_);
  }

private:
  ::myinterfaces::srv::Action_Request msg_;
};

class Init_Action_Request_linear_z
{
public:
  explicit Init_Action_Request_linear_z(::myinterfaces::srv::Action_Request & msg)
  : msg_(msg)
  {}
  Init_Action_Request_angular_x linear_z(::myinterfaces::srv::Action_Request::_linear_z_type arg)
  {
    msg_.linear_z = std::move(arg);
    return Init_Action_Request_angular_x(msg_);
  }

private:
  ::myinterfaces::srv::Action_Request msg_;
};

class Init_Action_Request_linear_y
{
public:
  explicit Init_Action_Request_linear_y(::myinterfaces::srv::Action_Request & msg)
  : msg_(msg)
  {}
  Init_Action_Request_linear_z linear_y(::myinterfaces::srv::Action_Request::_linear_y_type arg)
  {
    msg_.linear_y = std::move(arg);
    return Init_Action_Request_linear_z(msg_);
  }

private:
  ::myinterfaces::srv::Action_Request msg_;
};

class Init_Action_Request_linear_x
{
public:
  Init_Action_Request_linear_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Action_Request_linear_y linear_x(::myinterfaces::srv::Action_Request::_linear_x_type arg)
  {
    msg_.linear_x = std::move(arg);
    return Init_Action_Request_linear_y(msg_);
  }

private:
  ::myinterfaces::srv::Action_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::myinterfaces::srv::Action_Request>()
{
  return myinterfaces::srv::builder::Init_Action_Request_linear_x();
}

}  // namespace myinterfaces


namespace myinterfaces
{

namespace srv
{

namespace builder
{

class Init_Action_Response_success
{
public:
  Init_Action_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::myinterfaces::srv::Action_Response success(::myinterfaces::srv::Action_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::myinterfaces::srv::Action_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::myinterfaces::srv::Action_Response>()
{
  return myinterfaces::srv::builder::Init_Action_Response_success();
}

}  // namespace myinterfaces

#endif  // MYINTERFACES__SRV__DETAIL__ACTION__BUILDER_HPP_
