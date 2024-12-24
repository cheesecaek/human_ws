// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from myinterfaces:msg/State.idl
// generated code does not contain a copyright notice

#ifndef MYINTERFACES__MSG__DETAIL__STATE__TRAITS_HPP_
#define MYINTERFACES__MSG__DETAIL__STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "myinterfaces/msg/detail/state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace myinterfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const State & msg,
  std::ostream & out)
{
  out << "{";
  // member: apriltag
  {
    out << "apriltag: ";
    rosidl_generator_traits::value_to_yaml(msg.apriltag, out);
    out << ", ";
  }

  // member: task
  {
    out << "task: ";
    rosidl_generator_traits::value_to_yaml(msg.task, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const State & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: apriltag
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "apriltag: ";
    rosidl_generator_traits::value_to_yaml(msg.apriltag, out);
    out << "\n";
  }

  // member: task
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "task: ";
    rosidl_generator_traits::value_to_yaml(msg.task, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const State & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace myinterfaces

namespace rosidl_generator_traits
{

[[deprecated("use myinterfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const myinterfaces::msg::State & msg,
  std::ostream & out, size_t indentation = 0)
{
  myinterfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use myinterfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const myinterfaces::msg::State & msg)
{
  return myinterfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<myinterfaces::msg::State>()
{
  return "myinterfaces::msg::State";
}

template<>
inline const char * name<myinterfaces::msg::State>()
{
  return "myinterfaces/msg/State";
}

template<>
struct has_fixed_size<myinterfaces::msg::State>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<myinterfaces::msg::State>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<myinterfaces::msg::State>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MYINTERFACES__MSG__DETAIL__STATE__TRAITS_HPP_
