// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from myinterfaces:srv/Tag.idl
// generated code does not contain a copyright notice

#ifndef MYINTERFACES__SRV__DETAIL__TAG__TRAITS_HPP_
#define MYINTERFACES__SRV__DETAIL__TAG__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "myinterfaces/srv/detail/tag__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'id'
// Member 'action'
#include "std_msgs/msg/detail/int8__traits.hpp"

namespace myinterfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const Tag_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: id
  {
    out << "id: ";
    to_flow_style_yaml(msg.id, out);
    out << ", ";
  }

  // member: action
  {
    out << "action: ";
    to_flow_style_yaml(msg.action, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Tag_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "id:\n";
    to_block_style_yaml(msg.id, out, indentation + 2);
  }

  // member: action
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "action:\n";
    to_block_style_yaml(msg.action, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Tag_Request & msg, bool use_flow_style = false)
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
  const myinterfaces::srv::Tag_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  myinterfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use myinterfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const myinterfaces::srv::Tag_Request & msg)
{
  return myinterfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<myinterfaces::srv::Tag_Request>()
{
  return "myinterfaces::srv::Tag_Request";
}

template<>
inline const char * name<myinterfaces::srv::Tag_Request>()
{
  return "myinterfaces/srv/Tag_Request";
}

template<>
struct has_fixed_size<myinterfaces::srv::Tag_Request>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Int8>::value> {};

template<>
struct has_bounded_size<myinterfaces::srv::Tag_Request>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Int8>::value> {};

template<>
struct is_message<myinterfaces::srv::Tag_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace myinterfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const Tag_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: state
  {
    out << "state: ";
    rosidl_generator_traits::value_to_yaml(msg.state, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Tag_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: state
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "state: ";
    rosidl_generator_traits::value_to_yaml(msg.state, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Tag_Response & msg, bool use_flow_style = false)
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
  const myinterfaces::srv::Tag_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  myinterfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use myinterfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const myinterfaces::srv::Tag_Response & msg)
{
  return myinterfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<myinterfaces::srv::Tag_Response>()
{
  return "myinterfaces::srv::Tag_Response";
}

template<>
inline const char * name<myinterfaces::srv::Tag_Response>()
{
  return "myinterfaces/srv/Tag_Response";
}

template<>
struct has_fixed_size<myinterfaces::srv::Tag_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<myinterfaces::srv::Tag_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<myinterfaces::srv::Tag_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<myinterfaces::srv::Tag>()
{
  return "myinterfaces::srv::Tag";
}

template<>
inline const char * name<myinterfaces::srv::Tag>()
{
  return "myinterfaces/srv/Tag";
}

template<>
struct has_fixed_size<myinterfaces::srv::Tag>
  : std::integral_constant<
    bool,
    has_fixed_size<myinterfaces::srv::Tag_Request>::value &&
    has_fixed_size<myinterfaces::srv::Tag_Response>::value
  >
{
};

template<>
struct has_bounded_size<myinterfaces::srv::Tag>
  : std::integral_constant<
    bool,
    has_bounded_size<myinterfaces::srv::Tag_Request>::value &&
    has_bounded_size<myinterfaces::srv::Tag_Response>::value
  >
{
};

template<>
struct is_service<myinterfaces::srv::Tag>
  : std::true_type
{
};

template<>
struct is_service_request<myinterfaces::srv::Tag_Request>
  : std::true_type
{
};

template<>
struct is_service_response<myinterfaces::srv::Tag_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // MYINTERFACES__SRV__DETAIL__TAG__TRAITS_HPP_
