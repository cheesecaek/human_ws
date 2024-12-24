// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from myinterfaces:msg/DetectCoordinates.idl
// generated code does not contain a copyright notice

#ifndef MYINTERFACES__MSG__DETAIL__DETECT_COORDINATES__STRUCT_H_
#define MYINTERFACES__MSG__DETAIL__DETECT_COORDINATES__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'name'
#include "rosidl_runtime_c/string.h"
// Member 'coordinates'
#include "geometry_msgs/msg/detail/point__struct.h"

/// Struct defined in msg/DetectCoordinates in the package myinterfaces.
typedef struct myinterfaces__msg__DetectCoordinates
{
  bool detection;
  rosidl_runtime_c__String__Sequence name;
  geometry_msgs__msg__Point__Sequence coordinates;
} myinterfaces__msg__DetectCoordinates;

// Struct for a sequence of myinterfaces__msg__DetectCoordinates.
typedef struct myinterfaces__msg__DetectCoordinates__Sequence
{
  myinterfaces__msg__DetectCoordinates * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} myinterfaces__msg__DetectCoordinates__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MYINTERFACES__MSG__DETAIL__DETECT_COORDINATES__STRUCT_H_
