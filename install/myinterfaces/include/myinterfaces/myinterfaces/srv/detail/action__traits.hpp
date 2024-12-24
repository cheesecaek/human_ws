// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from myinterfaces:srv/Action.idl
// generated code does not contain a copyright notice

#ifndef MYINTERFACES__SRV__DETAIL__ACTION__TRAITS_HPP_
#define MYINTERFACES__SRV__DETAIL__ACTION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "myinterfaces/srv/detail/action__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace myinterfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const Action_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: linear_x
  {
    out << "linear_x: ";
    rosidl_generator_traits::value_to_yaml(msg.linear_x, out);
    out << ", ";
  }

  // member: linear_y
  {
    out << "linear_y: ";
    rosidl_generator_traits::value_to_yaml(msg.linear_y, out);
    out << ", ";
  }

  // member: linear_z
  {
    out << "linear_z: ";
    rosidl_generator_traits::value_to_yaml(msg.linear_z, out);
    out << ", ";
  }

  // member: angular_x
  {
    out << "angular_x: ";
    rosidl_generator_traits::value_to_yaml(msg.angular_x, out);
    out << ", ";
  }

  // member: angular_y
  {
    out << "angular_y: ";
    rosidl_generator_traits::value_to_yaml(msg.angular_y, out);
    out << ", ";
  }

  // member: angular_z
  {
    out << "angular_z: ";
    rosidl_generator_traits::value_to_yaml(msg.angular_z, out);
    out << ", ";
  }

  // member: duration
  {
    out << "duration: ";
    rosidl_generator_traits::value_to_yaml(msg.duration, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Action_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: linear_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "linear_x: ";
    rosidl_generator_traits::value_to_yaml(msg.linear_x, out);
    out << "\n";
  }

  // member: linear_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "linear_y: ";
    rosidl_generator_traits::value_to_yaml(msg.linear_y, out);
    out << "\n";
  }

  // member: linear_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "linear_z: ";
    rosidl_generator_traits::value_to_yaml(msg.linear_z, out);
    out << "\n";
  }

  // member: angular_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "angular_x: ";
    rosidl_generator_traits::value_to_yaml(msg.angular_x, out);
    out << "\n";
  }

  // member: angular_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "angular_y: ";
    rosidl_generator_traits::value_to_yaml(msg.angular_y, out);
    out << "\n";
  }

  // member: angular_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "angular_z: ";
    rosidl_generator_traits::value_to_yaml(msg.angular_z, out);
    out << "\n";
  }

  // member: duration
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "duration: ";
    rosidl_generator_traits::value_to_yaml(msg.duration, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Action_Request & msg, bool use_flow_style = false)
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
  const myinterfaces::srv::Action_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  myinterfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use myinterfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const myinterfaces::srv::Action_Request & msg)
{
  return myinterfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<myinterfaces::srv::Action_Request>()
{
  return "myinterfaces::srv::Action_Request";
}

template<>
inline const char * name<myinterfaces::srv::Action_Request>()
{
  return "myinterfaces/srv/Action_Request";
}

template<>
struct has_fixed_size<myinterfaces::srv::Action_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<myinterfaces::srv::Action_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<myinterfaces::srv::Action_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace myinterfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const Action_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Action_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Action_Response & msg, bool use_flow_style = false)
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
  const myinterfaces::srv::Action_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  myinterfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use myinterfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const myinterfaces::srv::Action_Response & msg)
{
  return myinterfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<myinterfaces::srv::Action_Response>()
{
  return "myinterfaces::srv::Action_Response";
}

template<>
inline const char * name<myinterfaces::srv::Action_Response>()
{
  return "myinterfaces/srv/Action_Response";
}

template<>
struct has_fixed_size<myinterfaces::srv::Action_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<myinterfaces::srv::Action_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<myinterfaces::srv::Action_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<myinterfaces::srv::Action>()
{
  return "myinterfaces::srv::Action";
}

template<>
inline const char * name<myinterfaces::srv::Action>()
{
  return "myinterfaces/srv/Action";
}

template<>
struct has_fixed_size<myinterfaces::srv::Action>
  : std::integral_constant<
    bool,
    has_fixed_size<myinterfaces::srv::Action_Request>::value &&
    has_fixed_size<myinterfaces::srv::Action_Response>::value
  >
{
};

template<>
struct has_bounded_size<myinterfaces::srv::Action>
  : std::integral_constant<
    bool,
    has_bounded_size<myinterfaces::srv::Action_Request>::value &&
    has_bounded_size<myinterfaces::srv::Action_Response>::value
  >
{
};

template<>
struct is_service<myinterfaces::srv::Action>
  : std::true_type
{
};

template<>
struct is_service_request<myinterfaces::srv::Action_Request>
  : std::true_type
{
};

template<>
struct is_service_response<myinterfaces::srv::Action_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // MYINTERFACES__SRV__DETAIL__ACTION__TRAITS_HPP_
