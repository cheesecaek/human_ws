// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from myinterfaces:srv/Humancoordinates.idl
// generated code does not contain a copyright notice

#ifndef MYINTERFACES__SRV__DETAIL__HUMANCOORDINATES__TRAITS_HPP_
#define MYINTERFACES__SRV__DETAIL__HUMANCOORDINATES__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "myinterfaces/srv/detail/humancoordinates__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'camera_info'
#include "sensor_msgs/msg/detail/camera_info__traits.hpp"
// Member 'image'
// Member 'depth_image'
#include "sensor_msgs/msg/detail/image__traits.hpp"

namespace myinterfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const Humancoordinates_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: camera_info
  {
    out << "camera_info: ";
    to_flow_style_yaml(msg.camera_info, out);
    out << ", ";
  }

  // member: image
  {
    out << "image: ";
    to_flow_style_yaml(msg.image, out);
    out << ", ";
  }

  // member: depth_image
  {
    out << "depth_image: ";
    to_flow_style_yaml(msg.depth_image, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Humancoordinates_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: camera_info
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "camera_info:\n";
    to_block_style_yaml(msg.camera_info, out, indentation + 2);
  }

  // member: image
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "image:\n";
    to_block_style_yaml(msg.image, out, indentation + 2);
  }

  // member: depth_image
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "depth_image:\n";
    to_block_style_yaml(msg.depth_image, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Humancoordinates_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace myinterfaces

namespace rosidl_generator_traits
{

[[deprecated("use myinterfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const myinterfaces::srv::Humancoordinates_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  myinterfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use myinterfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const myinterfaces::srv::Humancoordinates_Request & msg)
{
  return myinterfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<myinterfaces::srv::Humancoordinates_Request>()
{
  return "myinterfaces::srv::Humancoordinates_Request";
}

template<>
inline const char * name<myinterfaces::srv::Humancoordinates_Request>()
{
  return "myinterfaces/srv/Humancoordinates_Request";
}

template<>
struct has_fixed_size<myinterfaces::srv::Humancoordinates_Request>
  : std::integral_constant<bool, has_fixed_size<sensor_msgs::msg::CameraInfo>::value && has_fixed_size<sensor_msgs::msg::Image>::value> {};

template<>
struct has_bounded_size<myinterfaces::srv::Humancoordinates_Request>
  : std::integral_constant<bool, has_bounded_size<sensor_msgs::msg::CameraInfo>::value && has_bounded_size<sensor_msgs::msg::Image>::value> {};

template<>
struct is_message<myinterfaces::srv::Humancoordinates_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'coordinate'
#include "geometry_msgs/msg/detail/point__traits.hpp"

namespace myinterfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const Humancoordinates_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: coordinate
  {
    out << "coordinate: ";
    to_flow_style_yaml(msg.coordinate, out);
    out << ", ";
  }

  // member: response
  {
    out << "response: ";
    rosidl_generator_traits::value_to_yaml(msg.response, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Humancoordinates_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: coordinate
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "coordinate:\n";
    to_block_style_yaml(msg.coordinate, out, indentation + 2);
  }

  // member: response
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "response: ";
    rosidl_generator_traits::value_to_yaml(msg.response, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Humancoordinates_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace myinterfaces

namespace rosidl_generator_traits
{

[[deprecated("use myinterfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const myinterfaces::srv::Humancoordinates_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  myinterfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use myinterfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const myinterfaces::srv::Humancoordinates_Response & msg)
{
  return myinterfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<myinterfaces::srv::Humancoordinates_Response>()
{
  return "myinterfaces::srv::Humancoordinates_Response";
}

template<>
inline const char * name<myinterfaces::srv::Humancoordinates_Response>()
{
  return "myinterfaces/srv/Humancoordinates_Response";
}

template<>
struct has_fixed_size<myinterfaces::srv::Humancoordinates_Response>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Point>::value> {};

template<>
struct has_bounded_size<myinterfaces::srv::Humancoordinates_Response>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Point>::value> {};

template<>
struct is_message<myinterfaces::srv::Humancoordinates_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<myinterfaces::srv::Humancoordinates>()
{
  return "myinterfaces::srv::Humancoordinates";
}

template<>
inline const char * name<myinterfaces::srv::Humancoordinates>()
{
  return "myinterfaces/srv/Humancoordinates";
}

template<>
struct has_fixed_size<myinterfaces::srv::Humancoordinates>
  : std::integral_constant<
    bool,
    has_fixed_size<myinterfaces::srv::Humancoordinates_Request>::value &&
    has_fixed_size<myinterfaces::srv::Humancoordinates_Response>::value
  >
{
};

template<>
struct has_bounded_size<myinterfaces::srv::Humancoordinates>
  : std::integral_constant<
    bool,
    has_bounded_size<myinterfaces::srv::Humancoordinates_Request>::value &&
    has_bounded_size<myinterfaces::srv::Humancoordinates_Response>::value
  >
{
};

template<>
struct is_service<myinterfaces::srv::Humancoordinates>
  : std::true_type
{
};

template<>
struct is_service_request<myinterfaces::srv::Humancoordinates_Request>
  : std::true_type
{
};

template<>
struct is_service_response<myinterfaces::srv::Humancoordinates_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // MYINTERFACES__SRV__DETAIL__HUMANCOORDINATES__TRAITS_HPP_
