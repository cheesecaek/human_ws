// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from myinterfaces:srv/Tag.idl
// generated code does not contain a copyright notice

#ifndef MYINTERFACES__SRV__DETAIL__TAG__STRUCT_H_
#define MYINTERFACES__SRV__DETAIL__TAG__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'id'
// Member 'action'
#include "std_msgs/msg/detail/int8__struct.h"

/// Struct defined in srv/Tag in the package myinterfaces.
typedef struct myinterfaces__srv__Tag_Request
{
  std_msgs__msg__Int8 id;
  std_msgs__msg__Int8 action;
} myinterfaces__srv__Tag_Request;

// Struct for a sequence of myinterfaces__srv__Tag_Request.
typedef struct myinterfaces__srv__Tag_Request__Sequence
{
  myinterfaces__srv__Tag_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} myinterfaces__srv__Tag_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/Tag in the package myinterfaces.
typedef struct myinterfaces__srv__Tag_Response
{
  bool state;
} myinterfaces__srv__Tag_Response;

// Struct for a sequence of myinterfaces__srv__Tag_Response.
typedef struct myinterfaces__srv__Tag_Response__Sequence
{
  myinterfaces__srv__Tag_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} myinterfaces__srv__Tag_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MYINTERFACES__SRV__DETAIL__TAG__STRUCT_H_
