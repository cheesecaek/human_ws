// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from myinterfaces:msg/DetectCoordinates.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "myinterfaces/msg/detail/detect_coordinates__rosidl_typesupport_introspection_c.h"
#include "myinterfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "myinterfaces/msg/detail/detect_coordinates__functions.h"
#include "myinterfaces/msg/detail/detect_coordinates__struct.h"


// Include directives for member types
// Member `name`
#include "rosidl_runtime_c/string_functions.h"
// Member `coordinates`
#include "geometry_msgs/msg/point.h"
// Member `coordinates`
#include "geometry_msgs/msg/detail/point__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void myinterfaces__msg__DetectCoordinates__rosidl_typesupport_introspection_c__DetectCoordinates_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  myinterfaces__msg__DetectCoordinates__init(message_memory);
}

void myinterfaces__msg__DetectCoordinates__rosidl_typesupport_introspection_c__DetectCoordinates_fini_function(void * message_memory)
{
  myinterfaces__msg__DetectCoordinates__fini(message_memory);
}

size_t myinterfaces__msg__DetectCoordinates__rosidl_typesupport_introspection_c__size_function__DetectCoordinates__name(
  const void * untyped_member)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return member->size;
}

const void * myinterfaces__msg__DetectCoordinates__rosidl_typesupport_introspection_c__get_const_function__DetectCoordinates__name(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void * myinterfaces__msg__DetectCoordinates__rosidl_typesupport_introspection_c__get_function__DetectCoordinates__name(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void myinterfaces__msg__DetectCoordinates__rosidl_typesupport_introspection_c__fetch_function__DetectCoordinates__name(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const rosidl_runtime_c__String * item =
    ((const rosidl_runtime_c__String *)
    myinterfaces__msg__DetectCoordinates__rosidl_typesupport_introspection_c__get_const_function__DetectCoordinates__name(untyped_member, index));
  rosidl_runtime_c__String * value =
    (rosidl_runtime_c__String *)(untyped_value);
  *value = *item;
}

void myinterfaces__msg__DetectCoordinates__rosidl_typesupport_introspection_c__assign_function__DetectCoordinates__name(
  void * untyped_member, size_t index, const void * untyped_value)
{
  rosidl_runtime_c__String * item =
    ((rosidl_runtime_c__String *)
    myinterfaces__msg__DetectCoordinates__rosidl_typesupport_introspection_c__get_function__DetectCoordinates__name(untyped_member, index));
  const rosidl_runtime_c__String * value =
    (const rosidl_runtime_c__String *)(untyped_value);
  *item = *value;
}

bool myinterfaces__msg__DetectCoordinates__rosidl_typesupport_introspection_c__resize_function__DetectCoordinates__name(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  rosidl_runtime_c__String__Sequence__fini(member);
  return rosidl_runtime_c__String__Sequence__init(member, size);
}

size_t myinterfaces__msg__DetectCoordinates__rosidl_typesupport_introspection_c__size_function__DetectCoordinates__coordinates(
  const void * untyped_member)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return member->size;
}

const void * myinterfaces__msg__DetectCoordinates__rosidl_typesupport_introspection_c__get_const_function__DetectCoordinates__coordinates(
  const void * untyped_member, size_t index)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void * myinterfaces__msg__DetectCoordinates__rosidl_typesupport_introspection_c__get_function__DetectCoordinates__coordinates(
  void * untyped_member, size_t index)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void myinterfaces__msg__DetectCoordinates__rosidl_typesupport_introspection_c__fetch_function__DetectCoordinates__coordinates(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const geometry_msgs__msg__Point * item =
    ((const geometry_msgs__msg__Point *)
    myinterfaces__msg__DetectCoordinates__rosidl_typesupport_introspection_c__get_const_function__DetectCoordinates__coordinates(untyped_member, index));
  geometry_msgs__msg__Point * value =
    (geometry_msgs__msg__Point *)(untyped_value);
  *value = *item;
}

void myinterfaces__msg__DetectCoordinates__rosidl_typesupport_introspection_c__assign_function__DetectCoordinates__coordinates(
  void * untyped_member, size_t index, const void * untyped_value)
{
  geometry_msgs__msg__Point * item =
    ((geometry_msgs__msg__Point *)
    myinterfaces__msg__DetectCoordinates__rosidl_typesupport_introspection_c__get_function__DetectCoordinates__coordinates(untyped_member, index));
  const geometry_msgs__msg__Point * value =
    (const geometry_msgs__msg__Point *)(untyped_value);
  *item = *value;
}

bool myinterfaces__msg__DetectCoordinates__rosidl_typesupport_introspection_c__resize_function__DetectCoordinates__coordinates(
  void * untyped_member, size_t size)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  geometry_msgs__msg__Point__Sequence__fini(member);
  return geometry_msgs__msg__Point__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember myinterfaces__msg__DetectCoordinates__rosidl_typesupport_introspection_c__DetectCoordinates_message_member_array[3] = {
  {
    "detection",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(myinterfaces__msg__DetectCoordinates, detection),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "name",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(myinterfaces__msg__DetectCoordinates, name),  // bytes offset in struct
    NULL,  // default value
    myinterfaces__msg__DetectCoordinates__rosidl_typesupport_introspection_c__size_function__DetectCoordinates__name,  // size() function pointer
    myinterfaces__msg__DetectCoordinates__rosidl_typesupport_introspection_c__get_const_function__DetectCoordinates__name,  // get_const(index) function pointer
    myinterfaces__msg__DetectCoordinates__rosidl_typesupport_introspection_c__get_function__DetectCoordinates__name,  // get(index) function pointer
    myinterfaces__msg__DetectCoordinates__rosidl_typesupport_introspection_c__fetch_function__DetectCoordinates__name,  // fetch(index, &value) function pointer
    myinterfaces__msg__DetectCoordinates__rosidl_typesupport_introspection_c__assign_function__DetectCoordinates__name,  // assign(index, value) function pointer
    myinterfaces__msg__DetectCoordinates__rosidl_typesupport_introspection_c__resize_function__DetectCoordinates__name  // resize(index) function pointer
  },
  {
    "coordinates",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(myinterfaces__msg__DetectCoordinates, coordinates),  // bytes offset in struct
    NULL,  // default value
    myinterfaces__msg__DetectCoordinates__rosidl_typesupport_introspection_c__size_function__DetectCoordinates__coordinates,  // size() function pointer
    myinterfaces__msg__DetectCoordinates__rosidl_typesupport_introspection_c__get_const_function__DetectCoordinates__coordinates,  // get_const(index) function pointer
    myinterfaces__msg__DetectCoordinates__rosidl_typesupport_introspection_c__get_function__DetectCoordinates__coordinates,  // get(index) function pointer
    myinterfaces__msg__DetectCoordinates__rosidl_typesupport_introspection_c__fetch_function__DetectCoordinates__coordinates,  // fetch(index, &value) function pointer
    myinterfaces__msg__DetectCoordinates__rosidl_typesupport_introspection_c__assign_function__DetectCoordinates__coordinates,  // assign(index, value) function pointer
    myinterfaces__msg__DetectCoordinates__rosidl_typesupport_introspection_c__resize_function__DetectCoordinates__coordinates  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers myinterfaces__msg__DetectCoordinates__rosidl_typesupport_introspection_c__DetectCoordinates_message_members = {
  "myinterfaces__msg",  // message namespace
  "DetectCoordinates",  // message name
  3,  // number of fields
  sizeof(myinterfaces__msg__DetectCoordinates),
  myinterfaces__msg__DetectCoordinates__rosidl_typesupport_introspection_c__DetectCoordinates_message_member_array,  // message members
  myinterfaces__msg__DetectCoordinates__rosidl_typesupport_introspection_c__DetectCoordinates_init_function,  // function to initialize message memory (memory has to be allocated)
  myinterfaces__msg__DetectCoordinates__rosidl_typesupport_introspection_c__DetectCoordinates_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t myinterfaces__msg__DetectCoordinates__rosidl_typesupport_introspection_c__DetectCoordinates_message_type_support_handle = {
  0,
  &myinterfaces__msg__DetectCoordinates__rosidl_typesupport_introspection_c__DetectCoordinates_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_myinterfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, myinterfaces, msg, DetectCoordinates)() {
  myinterfaces__msg__DetectCoordinates__rosidl_typesupport_introspection_c__DetectCoordinates_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  if (!myinterfaces__msg__DetectCoordinates__rosidl_typesupport_introspection_c__DetectCoordinates_message_type_support_handle.typesupport_identifier) {
    myinterfaces__msg__DetectCoordinates__rosidl_typesupport_introspection_c__DetectCoordinates_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &myinterfaces__msg__DetectCoordinates__rosidl_typesupport_introspection_c__DetectCoordinates_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
