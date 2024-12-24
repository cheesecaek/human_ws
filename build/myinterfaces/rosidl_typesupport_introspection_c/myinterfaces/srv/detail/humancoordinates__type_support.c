// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from myinterfaces:srv/Humancoordinates.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "myinterfaces/srv/detail/humancoordinates__rosidl_typesupport_introspection_c.h"
#include "myinterfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "myinterfaces/srv/detail/humancoordinates__functions.h"
#include "myinterfaces/srv/detail/humancoordinates__struct.h"


// Include directives for member types
// Member `camera_info`
#include "sensor_msgs/msg/camera_info.h"
// Member `camera_info`
#include "sensor_msgs/msg/detail/camera_info__rosidl_typesupport_introspection_c.h"
// Member `image`
// Member `depth_image`
#include "sensor_msgs/msg/image.h"
// Member `image`
// Member `depth_image`
#include "sensor_msgs/msg/detail/image__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void myinterfaces__srv__Humancoordinates_Request__rosidl_typesupport_introspection_c__Humancoordinates_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  myinterfaces__srv__Humancoordinates_Request__init(message_memory);
}

void myinterfaces__srv__Humancoordinates_Request__rosidl_typesupport_introspection_c__Humancoordinates_Request_fini_function(void * message_memory)
{
  myinterfaces__srv__Humancoordinates_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember myinterfaces__srv__Humancoordinates_Request__rosidl_typesupport_introspection_c__Humancoordinates_Request_message_member_array[3] = {
  {
    "camera_info",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(myinterfaces__srv__Humancoordinates_Request, camera_info),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "image",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(myinterfaces__srv__Humancoordinates_Request, image),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "depth_image",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(myinterfaces__srv__Humancoordinates_Request, depth_image),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers myinterfaces__srv__Humancoordinates_Request__rosidl_typesupport_introspection_c__Humancoordinates_Request_message_members = {
  "myinterfaces__srv",  // message namespace
  "Humancoordinates_Request",  // message name
  3,  // number of fields
  sizeof(myinterfaces__srv__Humancoordinates_Request),
  myinterfaces__srv__Humancoordinates_Request__rosidl_typesupport_introspection_c__Humancoordinates_Request_message_member_array,  // message members
  myinterfaces__srv__Humancoordinates_Request__rosidl_typesupport_introspection_c__Humancoordinates_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  myinterfaces__srv__Humancoordinates_Request__rosidl_typesupport_introspection_c__Humancoordinates_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t myinterfaces__srv__Humancoordinates_Request__rosidl_typesupport_introspection_c__Humancoordinates_Request_message_type_support_handle = {
  0,
  &myinterfaces__srv__Humancoordinates_Request__rosidl_typesupport_introspection_c__Humancoordinates_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_myinterfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, myinterfaces, srv, Humancoordinates_Request)() {
  myinterfaces__srv__Humancoordinates_Request__rosidl_typesupport_introspection_c__Humancoordinates_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sensor_msgs, msg, CameraInfo)();
  myinterfaces__srv__Humancoordinates_Request__rosidl_typesupport_introspection_c__Humancoordinates_Request_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sensor_msgs, msg, Image)();
  myinterfaces__srv__Humancoordinates_Request__rosidl_typesupport_introspection_c__Humancoordinates_Request_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sensor_msgs, msg, Image)();
  if (!myinterfaces__srv__Humancoordinates_Request__rosidl_typesupport_introspection_c__Humancoordinates_Request_message_type_support_handle.typesupport_identifier) {
    myinterfaces__srv__Humancoordinates_Request__rosidl_typesupport_introspection_c__Humancoordinates_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &myinterfaces__srv__Humancoordinates_Request__rosidl_typesupport_introspection_c__Humancoordinates_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "myinterfaces/srv/detail/humancoordinates__rosidl_typesupport_introspection_c.h"
// already included above
// #include "myinterfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "myinterfaces/srv/detail/humancoordinates__functions.h"
// already included above
// #include "myinterfaces/srv/detail/humancoordinates__struct.h"


// Include directives for member types
// Member `coordinate`
#include "geometry_msgs/msg/point.h"
// Member `coordinate`
#include "geometry_msgs/msg/detail/point__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void myinterfaces__srv__Humancoordinates_Response__rosidl_typesupport_introspection_c__Humancoordinates_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  myinterfaces__srv__Humancoordinates_Response__init(message_memory);
}

void myinterfaces__srv__Humancoordinates_Response__rosidl_typesupport_introspection_c__Humancoordinates_Response_fini_function(void * message_memory)
{
  myinterfaces__srv__Humancoordinates_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember myinterfaces__srv__Humancoordinates_Response__rosidl_typesupport_introspection_c__Humancoordinates_Response_message_member_array[2] = {
  {
    "coordinate",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(myinterfaces__srv__Humancoordinates_Response, coordinate),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "response",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(myinterfaces__srv__Humancoordinates_Response, response),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers myinterfaces__srv__Humancoordinates_Response__rosidl_typesupport_introspection_c__Humancoordinates_Response_message_members = {
  "myinterfaces__srv",  // message namespace
  "Humancoordinates_Response",  // message name
  2,  // number of fields
  sizeof(myinterfaces__srv__Humancoordinates_Response),
  myinterfaces__srv__Humancoordinates_Response__rosidl_typesupport_introspection_c__Humancoordinates_Response_message_member_array,  // message members
  myinterfaces__srv__Humancoordinates_Response__rosidl_typesupport_introspection_c__Humancoordinates_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  myinterfaces__srv__Humancoordinates_Response__rosidl_typesupport_introspection_c__Humancoordinates_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t myinterfaces__srv__Humancoordinates_Response__rosidl_typesupport_introspection_c__Humancoordinates_Response_message_type_support_handle = {
  0,
  &myinterfaces__srv__Humancoordinates_Response__rosidl_typesupport_introspection_c__Humancoordinates_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_myinterfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, myinterfaces, srv, Humancoordinates_Response)() {
  myinterfaces__srv__Humancoordinates_Response__rosidl_typesupport_introspection_c__Humancoordinates_Response_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  if (!myinterfaces__srv__Humancoordinates_Response__rosidl_typesupport_introspection_c__Humancoordinates_Response_message_type_support_handle.typesupport_identifier) {
    myinterfaces__srv__Humancoordinates_Response__rosidl_typesupport_introspection_c__Humancoordinates_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &myinterfaces__srv__Humancoordinates_Response__rosidl_typesupport_introspection_c__Humancoordinates_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "myinterfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "myinterfaces/srv/detail/humancoordinates__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers myinterfaces__srv__detail__humancoordinates__rosidl_typesupport_introspection_c__Humancoordinates_service_members = {
  "myinterfaces__srv",  // service namespace
  "Humancoordinates",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // myinterfaces__srv__detail__humancoordinates__rosidl_typesupport_introspection_c__Humancoordinates_Request_message_type_support_handle,
  NULL  // response message
  // myinterfaces__srv__detail__humancoordinates__rosidl_typesupport_introspection_c__Humancoordinates_Response_message_type_support_handle
};

static rosidl_service_type_support_t myinterfaces__srv__detail__humancoordinates__rosidl_typesupport_introspection_c__Humancoordinates_service_type_support_handle = {
  0,
  &myinterfaces__srv__detail__humancoordinates__rosidl_typesupport_introspection_c__Humancoordinates_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, myinterfaces, srv, Humancoordinates_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, myinterfaces, srv, Humancoordinates_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_myinterfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, myinterfaces, srv, Humancoordinates)() {
  if (!myinterfaces__srv__detail__humancoordinates__rosidl_typesupport_introspection_c__Humancoordinates_service_type_support_handle.typesupport_identifier) {
    myinterfaces__srv__detail__humancoordinates__rosidl_typesupport_introspection_c__Humancoordinates_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)myinterfaces__srv__detail__humancoordinates__rosidl_typesupport_introspection_c__Humancoordinates_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, myinterfaces, srv, Humancoordinates_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, myinterfaces, srv, Humancoordinates_Response)()->data;
  }

  return &myinterfaces__srv__detail__humancoordinates__rosidl_typesupport_introspection_c__Humancoordinates_service_type_support_handle;
}
