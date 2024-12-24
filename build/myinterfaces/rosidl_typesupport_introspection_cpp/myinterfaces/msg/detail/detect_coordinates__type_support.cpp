// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from myinterfaces:msg/DetectCoordinates.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "myinterfaces/msg/detail/detect_coordinates__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace myinterfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void DetectCoordinates_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) myinterfaces::msg::DetectCoordinates(_init);
}

void DetectCoordinates_fini_function(void * message_memory)
{
  auto typed_message = static_cast<myinterfaces::msg::DetectCoordinates *>(message_memory);
  typed_message->~DetectCoordinates();
}

size_t size_function__DetectCoordinates__name(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<std::string> *>(untyped_member);
  return member->size();
}

const void * get_const_function__DetectCoordinates__name(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<std::string> *>(untyped_member);
  return &member[index];
}

void * get_function__DetectCoordinates__name(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<std::string> *>(untyped_member);
  return &member[index];
}

void fetch_function__DetectCoordinates__name(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const std::string *>(
    get_const_function__DetectCoordinates__name(untyped_member, index));
  auto & value = *reinterpret_cast<std::string *>(untyped_value);
  value = item;
}

void assign_function__DetectCoordinates__name(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<std::string *>(
    get_function__DetectCoordinates__name(untyped_member, index));
  const auto & value = *reinterpret_cast<const std::string *>(untyped_value);
  item = value;
}

void resize_function__DetectCoordinates__name(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<std::string> *>(untyped_member);
  member->resize(size);
}

size_t size_function__DetectCoordinates__coordinates(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<geometry_msgs::msg::Point> *>(untyped_member);
  return member->size();
}

const void * get_const_function__DetectCoordinates__coordinates(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<geometry_msgs::msg::Point> *>(untyped_member);
  return &member[index];
}

void * get_function__DetectCoordinates__coordinates(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<geometry_msgs::msg::Point> *>(untyped_member);
  return &member[index];
}

void fetch_function__DetectCoordinates__coordinates(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const geometry_msgs::msg::Point *>(
    get_const_function__DetectCoordinates__coordinates(untyped_member, index));
  auto & value = *reinterpret_cast<geometry_msgs::msg::Point *>(untyped_value);
  value = item;
}

void assign_function__DetectCoordinates__coordinates(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<geometry_msgs::msg::Point *>(
    get_function__DetectCoordinates__coordinates(untyped_member, index));
  const auto & value = *reinterpret_cast<const geometry_msgs::msg::Point *>(untyped_value);
  item = value;
}

void resize_function__DetectCoordinates__coordinates(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<geometry_msgs::msg::Point> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember DetectCoordinates_message_member_array[3] = {
  {
    "detection",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(myinterfaces::msg::DetectCoordinates, detection),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "name",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(myinterfaces::msg::DetectCoordinates, name),  // bytes offset in struct
    nullptr,  // default value
    size_function__DetectCoordinates__name,  // size() function pointer
    get_const_function__DetectCoordinates__name,  // get_const(index) function pointer
    get_function__DetectCoordinates__name,  // get(index) function pointer
    fetch_function__DetectCoordinates__name,  // fetch(index, &value) function pointer
    assign_function__DetectCoordinates__name,  // assign(index, value) function pointer
    resize_function__DetectCoordinates__name  // resize(index) function pointer
  },
  {
    "coordinates",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<geometry_msgs::msg::Point>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(myinterfaces::msg::DetectCoordinates, coordinates),  // bytes offset in struct
    nullptr,  // default value
    size_function__DetectCoordinates__coordinates,  // size() function pointer
    get_const_function__DetectCoordinates__coordinates,  // get_const(index) function pointer
    get_function__DetectCoordinates__coordinates,  // get(index) function pointer
    fetch_function__DetectCoordinates__coordinates,  // fetch(index, &value) function pointer
    assign_function__DetectCoordinates__coordinates,  // assign(index, value) function pointer
    resize_function__DetectCoordinates__coordinates  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers DetectCoordinates_message_members = {
  "myinterfaces::msg",  // message namespace
  "DetectCoordinates",  // message name
  3,  // number of fields
  sizeof(myinterfaces::msg::DetectCoordinates),
  DetectCoordinates_message_member_array,  // message members
  DetectCoordinates_init_function,  // function to initialize message memory (memory has to be allocated)
  DetectCoordinates_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t DetectCoordinates_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &DetectCoordinates_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace myinterfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<myinterfaces::msg::DetectCoordinates>()
{
  return &::myinterfaces::msg::rosidl_typesupport_introspection_cpp::DetectCoordinates_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, myinterfaces, msg, DetectCoordinates)() {
  return &::myinterfaces::msg::rosidl_typesupport_introspection_cpp::DetectCoordinates_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
