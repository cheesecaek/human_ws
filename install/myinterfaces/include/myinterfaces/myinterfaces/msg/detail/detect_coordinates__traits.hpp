// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from myinterfaces:msg/DetectCoordinates.idl
// generated code does not contain a copyright notice

#ifndef MYINTERFACES__MSG__DETAIL__DETECT_COORDINATES__TRAITS_HPP_
#define MYINTERFACES__MSG__DETAIL__DETECT_COORDINATES__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "myinterfaces/msg/detail/detect_coordinates__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'coordinates'
#include "geometry_msgs/msg/detail/point__traits.hpp"

namespace myinterfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const DetectCoordinates & msg,
  std::ostream & out)
{
  out << "{";
  // member: detection
  {
    out << "detection: ";
    rosidl_generator_traits::value_to_yaml(msg.detection, out);
    out << ", ";
  }

  // member: name
  {
    if (msg.name.size() == 0) {
      out << "name: []";
    } else {
      out << "name: [";
      size_t pending_items = msg.name.size();
      for (auto item : msg.name) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: coordinates
  {
    if (msg.coordinates.size() == 0) {
      out << "coordinates: []";
    } else {
      out << "coordinates: [";
      size_t pending_items = msg.coordinates.size();
      for (auto item : msg.coordinates) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const DetectCoordinates & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: detection
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "detection: ";
    rosidl_generator_traits::value_to_yaml(msg.detection, out);
    out << "\n";
  }

  // member: name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.name.size() == 0) {
      out << "name: []\n";
    } else {
      out << "name:\n";
      for (auto item : msg.name) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: coordinates
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.coordinates.size() == 0) {
      out << "coordinates: []\n";
    } else {
      out << "coordinates:\n";
      for (auto item : msg.coordinates) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const DetectCoordinates & msg, bool use_flow_style = false)
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
  const myinterfaces::msg::DetectCoordinates & msg,
  std::ostream & out, size_t indentation = 0)
{
  myinterfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use myinterfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const myinterfaces::msg::DetectCoordinates & msg)
{
  return myinterfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<myinterfaces::msg::DetectCoordinates>()
{
  return "myinterfaces::msg::DetectCoordinates";
}

template<>
inline const char * name<myinterfaces::msg::DetectCoordinates>()
{
  return "myinterfaces/msg/DetectCoordinates";
}

template<>
struct has_fixed_size<myinterfaces::msg::DetectCoordinates>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<myinterfaces::msg::DetectCoordinates>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<myinterfaces::msg::DetectCoordinates>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MYINTERFACES__MSG__DETAIL__DETECT_COORDINATES__TRAITS_HPP_
