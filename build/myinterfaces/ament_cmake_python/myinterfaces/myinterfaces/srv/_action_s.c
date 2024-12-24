// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from myinterfaces:srv/Action.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "myinterfaces/srv/detail/action__struct.h"
#include "myinterfaces/srv/detail/action__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool myinterfaces__srv__action__request__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[40];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("myinterfaces.srv._action.Action_Request", full_classname_dest, 39) == 0);
  }
  myinterfaces__srv__Action_Request * ros_message = _ros_message;
  {  // linear_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "linear_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->linear_x = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // linear_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "linear_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->linear_y = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // linear_z
    PyObject * field = PyObject_GetAttrString(_pymsg, "linear_z");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->linear_z = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // angular_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "angular_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->angular_x = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // angular_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "angular_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->angular_y = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // angular_z
    PyObject * field = PyObject_GetAttrString(_pymsg, "angular_z");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->angular_z = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // duration
    PyObject * field = PyObject_GetAttrString(_pymsg, "duration");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->duration = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * myinterfaces__srv__action__request__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of Action_Request */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("myinterfaces.srv._action");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "Action_Request");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  myinterfaces__srv__Action_Request * ros_message = (myinterfaces__srv__Action_Request *)raw_ros_message;
  {  // linear_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->linear_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "linear_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // linear_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->linear_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "linear_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // linear_z
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->linear_z);
    {
      int rc = PyObject_SetAttrString(_pymessage, "linear_z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // angular_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->angular_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "angular_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // angular_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->angular_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "angular_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // angular_z
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->angular_z);
    {
      int rc = PyObject_SetAttrString(_pymessage, "angular_z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // duration
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->duration);
    {
      int rc = PyObject_SetAttrString(_pymessage, "duration", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}

#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
// already included above
// #include <Python.h>
// already included above
// #include <stdbool.h>
// already included above
// #include "numpy/ndarrayobject.h"
// already included above
// #include "rosidl_runtime_c/visibility_control.h"
// already included above
// #include "myinterfaces/srv/detail/action__struct.h"
// already included above
// #include "myinterfaces/srv/detail/action__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool myinterfaces__srv__action__response__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[41];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("myinterfaces.srv._action.Action_Response", full_classname_dest, 40) == 0);
  }
  myinterfaces__srv__Action_Response * ros_message = _ros_message;
  {  // success
    PyObject * field = PyObject_GetAttrString(_pymsg, "success");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->success = (Py_True == field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * myinterfaces__srv__action__response__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of Action_Response */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("myinterfaces.srv._action");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "Action_Response");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  myinterfaces__srv__Action_Response * ros_message = (myinterfaces__srv__Action_Response *)raw_ros_message;
  {  // success
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->success ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "success", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
