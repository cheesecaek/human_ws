// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from myinterfaces:srv/Humancoordinates.idl
// generated code does not contain a copyright notice

#ifndef MYINTERFACES__SRV__DETAIL__HUMANCOORDINATES__BUILDER_HPP_
#define MYINTERFACES__SRV__DETAIL__HUMANCOORDINATES__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "myinterfaces/srv/detail/humancoordinates__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace myinterfaces
{

namespace srv
{

namespace builder
{

class Init_Humancoordinates_Request_depth_image
{
public:
  explicit Init_Humancoordinates_Request_depth_image(::myinterfaces::srv::Humancoordinates_Request & msg)
  : msg_(msg)
  {}
  ::myinterfaces::srv::Humancoordinates_Request depth_image(::myinterfaces::srv::Humancoordinates_Request::_depth_image_type arg)
  {
    msg_.depth_image = std::move(arg);
    return std::move(msg_);
  }

private:
  ::myinterfaces::srv::Humancoordinates_Request msg_;
};

class Init_Humancoordinates_Request_image
{
public:
  explicit Init_Humancoordinates_Request_image(::myinterfaces::srv::Humancoordinates_Request & msg)
  : msg_(msg)
  {}
  Init_Humancoordinates_Request_depth_image image(::myinterfaces::srv::Humancoordinates_Request::_image_type arg)
  {
    msg_.image = std::move(arg);
    return Init_Humancoordinates_Request_depth_image(msg_);
  }

private:
  ::myinterfaces::srv::Humancoordinates_Request msg_;
};

class Init_Humancoordinates_Request_camera_info
{
public:
  Init_Humancoordinates_Request_camera_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Humancoordinates_Request_image camera_info(::myinterfaces::srv::Humancoordinates_Request::_camera_info_type arg)
  {
    msg_.camera_info = std::move(arg);
    return Init_Humancoordinates_Request_image(msg_);
  }

private:
  ::myinterfaces::srv::Humancoordinates_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::myinterfaces::srv::Humancoordinates_Request>()
{
  return myinterfaces::srv::builder::Init_Humancoordinates_Request_camera_info();
}

}  // namespace myinterfaces


namespace myinterfaces
{

namespace srv
{

namespace builder
{

class Init_Humancoordinates_Response_response
{
public:
  explicit Init_Humancoordinates_Response_response(::myinterfaces::srv::Humancoordinates_Response & msg)
  : msg_(msg)
  {}
  ::myinterfaces::srv::Humancoordinates_Response response(::myinterfaces::srv::Humancoordinates_Response::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::myinterfaces::srv::Humancoordinates_Response msg_;
};

class Init_Humancoordinates_Response_coordinate
{
public:
  Init_Humancoordinates_Response_coordinate()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Humancoordinates_Response_response coordinate(::myinterfaces::srv::Humancoordinates_Response::_coordinate_type arg)
  {
    msg_.coordinate = std::move(arg);
    return Init_Humancoordinates_Response_response(msg_);
  }

private:
  ::myinterfaces::srv::Humancoordinates_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::myinterfaces::srv::Humancoordinates_Response>()
{
  return myinterfaces::srv::builder::Init_Humancoordinates_Response_coordinate();
}

}  // namespace myinterfaces

#endif  // MYINTERFACES__SRV__DETAIL__HUMANCOORDINATES__BUILDER_HPP_
