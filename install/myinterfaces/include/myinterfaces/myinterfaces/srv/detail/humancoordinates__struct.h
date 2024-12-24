// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from myinterfaces:srv/Humancoordinates.idl
// generated code does not contain a copyright notice

#ifndef MYINTERFACES__SRV__DETAIL__HUMANCOORDINATES__STRUCT_H_
#define MYINTERFACES__SRV__DETAIL__HUMANCOORDINATES__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'camera_info'
#include "sensor_msgs/msg/detail/camera_info__struct.h"
// Member 'image'
// Member 'depth_image'
#include "sensor_msgs/msg/detail/image__struct.h"

/// Struct defined in srv/Humancoordinates in the package myinterfaces.
typedef struct myinterfaces__srv__Humancoordinates_Request
{
  sensor_msgs__msg__CameraInfo camera_info;
  sensor_msgs__msg__Image image;
  sensor_msgs__msg__Image depth_image;
} myinterfaces__srv__Humancoordinates_Request;

// Struct for a sequence of myinterfaces__srv__Humancoordinates_Request.
typedef struct myinterfaces__srv__Humancoordinates_Request__Sequence
{
  myinterfaces__srv__Humancoordinates_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} myinterfaces__srv__Humancoordinates_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'coordinate'
#include "geometry_msgs/msg/detail/point__struct.h"

/// Struct defined in srv/Humancoordinates in the package myinterfaces.
typedef struct myinterfaces__srv__Humancoordinates_Response
{
  geometry_msgs__msg__Point coordinate;
  bool response;
} myinterfaces__srv__Humancoordinates_Response;

// Struct for a sequence of myinterfaces__srv__Humancoordinates_Response.
typedef struct myinterfaces__srv__Humancoordinates_Response__Sequence
{
  myinterfaces__srv__Humancoordinates_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} myinterfaces__srv__Humancoordinates_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MYINTERFACES__SRV__DETAIL__HUMANCOORDINATES__STRUCT_H_
