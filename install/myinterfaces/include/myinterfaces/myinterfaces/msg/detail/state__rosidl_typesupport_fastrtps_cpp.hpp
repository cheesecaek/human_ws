// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from myinterfaces:msg/State.idl
// generated code does not contain a copyright notice

#ifndef MYINTERFACES__MSG__DETAIL__STATE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define MYINTERFACES__MSG__DETAIL__STATE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "myinterfaces/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "myinterfaces/msg/detail/state__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace myinterfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_myinterfaces
cdr_serialize(
  const myinterfaces::msg::State & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_myinterfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  myinterfaces::msg::State & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_myinterfaces
get_serialized_size(
  const myinterfaces::msg::State & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_myinterfaces
max_serialized_size_State(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace myinterfaces

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_myinterfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, myinterfaces, msg, State)();

#ifdef __cplusplus
}
#endif

#endif  // MYINTERFACES__MSG__DETAIL__STATE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
