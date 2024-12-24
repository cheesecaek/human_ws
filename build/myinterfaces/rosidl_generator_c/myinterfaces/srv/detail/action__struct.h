// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from myinterfaces:srv/Action.idl
// generated code does not contain a copyright notice

#ifndef MYINTERFACES__SRV__DETAIL__ACTION__STRUCT_H_
#define MYINTERFACES__SRV__DETAIL__ACTION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/Action in the package myinterfaces.
typedef struct myinterfaces__srv__Action_Request
{
  double linear_x;
  double linear_y;
  double linear_z;
  double angular_x;
  double angular_y;
  double angular_z;
  double duration;
} myinterfaces__srv__Action_Request;

// Struct for a sequence of myinterfaces__srv__Action_Request.
typedef struct myinterfaces__srv__Action_Request__Sequence
{
  myinterfaces__srv__Action_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} myinterfaces__srv__Action_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/Action in the package myinterfaces.
typedef struct myinterfaces__srv__Action_Response
{
  bool success;
} myinterfaces__srv__Action_Response;

// Struct for a sequence of myinterfaces__srv__Action_Response.
typedef struct myinterfaces__srv__Action_Response__Sequence
{
  myinterfaces__srv__Action_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} myinterfaces__srv__Action_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MYINTERFACES__SRV__DETAIL__ACTION__STRUCT_H_
