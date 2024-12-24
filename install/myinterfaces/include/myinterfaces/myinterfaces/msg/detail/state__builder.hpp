// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from myinterfaces:msg/State.idl
// generated code does not contain a copyright notice

#ifndef MYINTERFACES__MSG__DETAIL__STATE__BUILDER_HPP_
#define MYINTERFACES__MSG__DETAIL__STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "myinterfaces/msg/detail/state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace myinterfaces
{

namespace msg
{

namespace builder
{

class Init_State_task
{
public:
  explicit Init_State_task(::myinterfaces::msg::State & msg)
  : msg_(msg)
  {}
  ::myinterfaces::msg::State task(::myinterfaces::msg::State::_task_type arg)
  {
    msg_.task = std::move(arg);
    return std::move(msg_);
  }

private:
  ::myinterfaces::msg::State msg_;
};

class Init_State_apriltag
{
public:
  Init_State_apriltag()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_State_task apriltag(::myinterfaces::msg::State::_apriltag_type arg)
  {
    msg_.apriltag = std::move(arg);
    return Init_State_task(msg_);
  }

private:
  ::myinterfaces::msg::State msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::myinterfaces::msg::State>()
{
  return myinterfaces::msg::builder::Init_State_apriltag();
}

}  // namespace myinterfaces

#endif  // MYINTERFACES__MSG__DETAIL__STATE__BUILDER_HPP_
