// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from myinterfaces:msg/State.idl
// generated code does not contain a copyright notice

#ifndef MYINTERFACES__MSG__DETAIL__STATE__STRUCT_H_
#define MYINTERFACES__MSG__DETAIL__STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/State in the package myinterfaces.
typedef struct myinterfaces__msg__State
{
  int32_t apriltag;
  int32_t task;
} myinterfaces__msg__State;

// Struct for a sequence of myinterfaces__msg__State.
typedef struct myinterfaces__msg__State__Sequence
{
  myinterfaces__msg__State * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} myinterfaces__msg__State__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MYINTERFACES__MSG__DETAIL__STATE__STRUCT_H_
