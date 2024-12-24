// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from myinterfaces:srv/Action.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "myinterfaces/srv/detail/action__rosidl_typesupport_introspection_c.h"
#include "myinterfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "myinterfaces/srv/detail/action__functions.h"
#include "myinterfaces/srv/detail/action__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void myinterfaces__srv__Action_Request__rosidl_typesupport_introspection_c__Action_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  myinterfaces__srv__Action_Request__init(message_memory);
}

void myinterfaces__srv__Action_Request__rosidl_typesupport_introspection_c__Action_Request_fini_function(void * message_memory)
{
  myinterfaces__srv__Action_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember myinterfaces__srv__Action_Request__rosidl_typesupport_introspection_c__Action_Request_message_member_array[7] = {
  {
    "linear_x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(myinterfaces__srv__Action_Request, linear_x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "linear_y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(myinterfaces__srv__Action_Request, linear_y),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "linear_z",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(myinterfaces__srv__Action_Request, linear_z),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "angular_x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(myinterfaces__srv__Action_Request, angular_x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "angular_y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(myinterfaces__srv__Action_Request, angular_y),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "angular_z",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(myinterfaces__srv__Action_Request, angular_z),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "duration",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(myinterfaces__srv__Action_Request, duration),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers myinterfaces__srv__Action_Request__rosidl_typesupport_introspection_c__Action_Request_message_members = {
  "myinterfaces__srv",  // message namespace
  "Action_Request",  // message name
  7,  // number of fields
  sizeof(myinterfaces__srv__Action_Request),
  myinterfaces__srv__Action_Request__rosidl_typesupport_introspection_c__Action_Request_message_member_array,  // message members
  myinterfaces__srv__Action_Request__rosidl_typesupport_introspection_c__Action_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  myinterfaces__srv__Action_Request__rosidl_typesupport_introspection_c__Action_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t myinterfaces__srv__Action_Request__rosidl_typesupport_introspection_c__Action_Request_message_type_support_handle = {
  0,
  &myinterfaces__srv__Action_Request__rosidl_typesupport_introspection_c__Action_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_myinterfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, myinterfaces, srv, Action_Request)() {
  if (!myinterfaces__srv__Action_Request__rosidl_typesupport_introspection_c__Action_Request_message_type_support_handle.typesupport_identifier) {
    myinterfaces__srv__Action_Request__rosidl_typesupport_introspection_c__Action_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &myinterfaces__srv__Action_Request__rosidl_typesupport_introspection_c__Action_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "myinterfaces/srv/detail/action__rosidl_typesupport_introspection_c.h"
// already included above
// #include "myinterfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "myinterfaces/srv/detail/action__functions.h"
// already included above
// #include "myinterfaces/srv/detail/action__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void myinterfaces__srv__Action_Response__rosidl_typesupport_introspection_c__Action_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  myinterfaces__srv__Action_Response__init(message_memory);
}

void myinterfaces__srv__Action_Response__rosidl_typesupport_introspection_c__Action_Response_fini_function(void * message_memory)
{
  myinterfaces__srv__Action_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember myinterfaces__srv__Action_Response__rosidl_typesupport_introspection_c__Action_Response_message_member_array[1] = {
  {
    "success",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(myinterfaces__srv__Action_Response, success),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers myinterfaces__srv__Action_Response__rosidl_typesupport_introspection_c__Action_Response_message_members = {
  "myinterfaces__srv",  // message namespace
  "Action_Response",  // message name
  1,  // number of fields
  sizeof(myinterfaces__srv__Action_Response),
  myinterfaces__srv__Action_Response__rosidl_typesupport_introspection_c__Action_Response_message_member_array,  // message members
  myinterfaces__srv__Action_Response__rosidl_typesupport_introspection_c__Action_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  myinterfaces__srv__Action_Response__rosidl_typesupport_introspection_c__Action_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t myinterfaces__srv__Action_Response__rosidl_typesupport_introspection_c__Action_Response_message_type_support_handle = {
  0,
  &myinterfaces__srv__Action_Response__rosidl_typesupport_introspection_c__Action_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_myinterfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, myinterfaces, srv, Action_Response)() {
  if (!myinterfaces__srv__Action_Response__rosidl_typesupport_introspection_c__Action_Response_message_type_support_handle.typesupport_identifier) {
    myinterfaces__srv__Action_Response__rosidl_typesupport_introspection_c__Action_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &myinterfaces__srv__Action_Response__rosidl_typesupport_introspection_c__Action_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "myinterfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "myinterfaces/srv/detail/action__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers myinterfaces__srv__detail__action__rosidl_typesupport_introspection_c__Action_service_members = {
  "myinterfaces__srv",  // service namespace
  "Action",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // myinterfaces__srv__detail__action__rosidl_typesupport_introspection_c__Action_Request_message_type_support_handle,
  NULL  // response message
  // myinterfaces__srv__detail__action__rosidl_typesupport_introspection_c__Action_Response_message_type_support_handle
};

static rosidl_service_type_support_t myinterfaces__srv__detail__action__rosidl_typesupport_introspection_c__Action_service_type_support_handle = {
  0,
  &myinterfaces__srv__detail__action__rosidl_typesupport_introspection_c__Action_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, myinterfaces, srv, Action_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, myinterfaces, srv, Action_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_myinterfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, myinterfaces, srv, Action)() {
  if (!myinterfaces__srv__detail__action__rosidl_typesupport_introspection_c__Action_service_type_support_handle.typesupport_identifier) {
    myinterfaces__srv__detail__action__rosidl_typesupport_introspection_c__Action_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)myinterfaces__srv__detail__action__rosidl_typesupport_introspection_c__Action_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, myinterfaces, srv, Action_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, myinterfaces, srv, Action_Response)()->data;
  }

  return &myinterfaces__srv__detail__action__rosidl_typesupport_introspection_c__Action_service_type_support_handle;
}
