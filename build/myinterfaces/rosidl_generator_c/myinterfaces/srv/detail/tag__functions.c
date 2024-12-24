// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from myinterfaces:srv/Tag.idl
// generated code does not contain a copyright notice
#include "myinterfaces/srv/detail/tag__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `id`
// Member `action`
#include "std_msgs/msg/detail/int8__functions.h"

bool
myinterfaces__srv__Tag_Request__init(myinterfaces__srv__Tag_Request * msg)
{
  if (!msg) {
    return false;
  }
  // id
  if (!std_msgs__msg__Int8__init(&msg->id)) {
    myinterfaces__srv__Tag_Request__fini(msg);
    return false;
  }
  // action
  if (!std_msgs__msg__Int8__init(&msg->action)) {
    myinterfaces__srv__Tag_Request__fini(msg);
    return false;
  }
  return true;
}

void
myinterfaces__srv__Tag_Request__fini(myinterfaces__srv__Tag_Request * msg)
{
  if (!msg) {
    return;
  }
  // id
  std_msgs__msg__Int8__fini(&msg->id);
  // action
  std_msgs__msg__Int8__fini(&msg->action);
}

bool
myinterfaces__srv__Tag_Request__are_equal(const myinterfaces__srv__Tag_Request * lhs, const myinterfaces__srv__Tag_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // id
  if (!std_msgs__msg__Int8__are_equal(
      &(lhs->id), &(rhs->id)))
  {
    return false;
  }
  // action
  if (!std_msgs__msg__Int8__are_equal(
      &(lhs->action), &(rhs->action)))
  {
    return false;
  }
  return true;
}

bool
myinterfaces__srv__Tag_Request__copy(
  const myinterfaces__srv__Tag_Request * input,
  myinterfaces__srv__Tag_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // id
  if (!std_msgs__msg__Int8__copy(
      &(input->id), &(output->id)))
  {
    return false;
  }
  // action
  if (!std_msgs__msg__Int8__copy(
      &(input->action), &(output->action)))
  {
    return false;
  }
  return true;
}

myinterfaces__srv__Tag_Request *
myinterfaces__srv__Tag_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  myinterfaces__srv__Tag_Request * msg = (myinterfaces__srv__Tag_Request *)allocator.allocate(sizeof(myinterfaces__srv__Tag_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(myinterfaces__srv__Tag_Request));
  bool success = myinterfaces__srv__Tag_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
myinterfaces__srv__Tag_Request__destroy(myinterfaces__srv__Tag_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    myinterfaces__srv__Tag_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
myinterfaces__srv__Tag_Request__Sequence__init(myinterfaces__srv__Tag_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  myinterfaces__srv__Tag_Request * data = NULL;

  if (size) {
    data = (myinterfaces__srv__Tag_Request *)allocator.zero_allocate(size, sizeof(myinterfaces__srv__Tag_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = myinterfaces__srv__Tag_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        myinterfaces__srv__Tag_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
myinterfaces__srv__Tag_Request__Sequence__fini(myinterfaces__srv__Tag_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      myinterfaces__srv__Tag_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

myinterfaces__srv__Tag_Request__Sequence *
myinterfaces__srv__Tag_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  myinterfaces__srv__Tag_Request__Sequence * array = (myinterfaces__srv__Tag_Request__Sequence *)allocator.allocate(sizeof(myinterfaces__srv__Tag_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = myinterfaces__srv__Tag_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
myinterfaces__srv__Tag_Request__Sequence__destroy(myinterfaces__srv__Tag_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    myinterfaces__srv__Tag_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
myinterfaces__srv__Tag_Request__Sequence__are_equal(const myinterfaces__srv__Tag_Request__Sequence * lhs, const myinterfaces__srv__Tag_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!myinterfaces__srv__Tag_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
myinterfaces__srv__Tag_Request__Sequence__copy(
  const myinterfaces__srv__Tag_Request__Sequence * input,
  myinterfaces__srv__Tag_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(myinterfaces__srv__Tag_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    myinterfaces__srv__Tag_Request * data =
      (myinterfaces__srv__Tag_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!myinterfaces__srv__Tag_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          myinterfaces__srv__Tag_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!myinterfaces__srv__Tag_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
myinterfaces__srv__Tag_Response__init(myinterfaces__srv__Tag_Response * msg)
{
  if (!msg) {
    return false;
  }
  // state
  return true;
}

void
myinterfaces__srv__Tag_Response__fini(myinterfaces__srv__Tag_Response * msg)
{
  if (!msg) {
    return;
  }
  // state
}

bool
myinterfaces__srv__Tag_Response__are_equal(const myinterfaces__srv__Tag_Response * lhs, const myinterfaces__srv__Tag_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // state
  if (lhs->state != rhs->state) {
    return false;
  }
  return true;
}

bool
myinterfaces__srv__Tag_Response__copy(
  const myinterfaces__srv__Tag_Response * input,
  myinterfaces__srv__Tag_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // state
  output->state = input->state;
  return true;
}

myinterfaces__srv__Tag_Response *
myinterfaces__srv__Tag_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  myinterfaces__srv__Tag_Response * msg = (myinterfaces__srv__Tag_Response *)allocator.allocate(sizeof(myinterfaces__srv__Tag_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(myinterfaces__srv__Tag_Response));
  bool success = myinterfaces__srv__Tag_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
myinterfaces__srv__Tag_Response__destroy(myinterfaces__srv__Tag_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    myinterfaces__srv__Tag_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
myinterfaces__srv__Tag_Response__Sequence__init(myinterfaces__srv__Tag_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  myinterfaces__srv__Tag_Response * data = NULL;

  if (size) {
    data = (myinterfaces__srv__Tag_Response *)allocator.zero_allocate(size, sizeof(myinterfaces__srv__Tag_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = myinterfaces__srv__Tag_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        myinterfaces__srv__Tag_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
myinterfaces__srv__Tag_Response__Sequence__fini(myinterfaces__srv__Tag_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      myinterfaces__srv__Tag_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

myinterfaces__srv__Tag_Response__Sequence *
myinterfaces__srv__Tag_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  myinterfaces__srv__Tag_Response__Sequence * array = (myinterfaces__srv__Tag_Response__Sequence *)allocator.allocate(sizeof(myinterfaces__srv__Tag_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = myinterfaces__srv__Tag_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
myinterfaces__srv__Tag_Response__Sequence__destroy(myinterfaces__srv__Tag_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    myinterfaces__srv__Tag_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
myinterfaces__srv__Tag_Response__Sequence__are_equal(const myinterfaces__srv__Tag_Response__Sequence * lhs, const myinterfaces__srv__Tag_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!myinterfaces__srv__Tag_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
myinterfaces__srv__Tag_Response__Sequence__copy(
  const myinterfaces__srv__Tag_Response__Sequence * input,
  myinterfaces__srv__Tag_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(myinterfaces__srv__Tag_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    myinterfaces__srv__Tag_Response * data =
      (myinterfaces__srv__Tag_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!myinterfaces__srv__Tag_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          myinterfaces__srv__Tag_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!myinterfaces__srv__Tag_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
