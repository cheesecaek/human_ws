// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from myinterfaces:msg/DetectCoordinates.idl
// generated code does not contain a copyright notice

#ifndef MYINTERFACES__MSG__DETAIL__DETECT_COORDINATES__BUILDER_HPP_
#define MYINTERFACES__MSG__DETAIL__DETECT_COORDINATES__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "myinterfaces/msg/detail/detect_coordinates__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace myinterfaces
{

namespace msg
{

namespace builder
{

class Init_DetectCoordinates_coordinates
{
public:
  explicit Init_DetectCoordinates_coordinates(::myinterfaces::msg::DetectCoordinates & msg)
  : msg_(msg)
  {}
  ::myinterfaces::msg::DetectCoordinates coordinates(::myinterfaces::msg::DetectCoordinates::_coordinates_type arg)
  {
    msg_.coordinates = std::move(arg);
    return std::move(msg_);
  }

private:
  ::myinterfaces::msg::DetectCoordinates msg_;
};

class Init_DetectCoordinates_name
{
public:
  explicit Init_DetectCoordinates_name(::myinterfaces::msg::DetectCoordinates & msg)
  : msg_(msg)
  {}
  Init_DetectCoordinates_coordinates name(::myinterfaces::msg::DetectCoordinates::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_DetectCoordinates_coordinates(msg_);
  }

private:
  ::myinterfaces::msg::DetectCoordinates msg_;
};

class Init_DetectCoordinates_detection
{
public:
  Init_DetectCoordinates_detection()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DetectCoordinates_name detection(::myinterfaces::msg::DetectCoordinates::_detection_type arg)
  {
    msg_.detection = std::move(arg);
    return Init_DetectCoordinates_name(msg_);
  }

private:
  ::myinterfaces::msg::DetectCoordinates msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::myinterfaces::msg::DetectCoordinates>()
{
  return myinterfaces::msg::builder::Init_DetectCoordinates_detection();
}

}  // namespace myinterfaces

#endif  // MYINTERFACES__MSG__DETAIL__DETECT_COORDINATES__BUILDER_HPP_
