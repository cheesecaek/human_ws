// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from myinterfaces:srv/Action.idl
// generated code does not contain a copyright notice
#include "myinterfaces/srv/detail/action__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
myinterfaces__srv__Action_Request__init(myinterfaces__srv__Action_Request * msg)
{
  if (!msg) {
    return false;
  }
  // linear_x
  // linear_y
  // linear_z
  // angular_x
  // angular_y
  // angular_z
  // duration
  return true;
}

void
myinterfaces__srv__Action_Request__fini(myinterfaces__srv__Action_Request * msg)
{
  if (!msg) {
    return;
  }
  // linear_x
  // linear_y
  // linear_z
  // angular_x
  // angular_y
  // angular_z
  // duration
}

bool
myinterfaces__srv__Action_Request__are_equal(const myinterfaces__srv__Action_Request * lhs, const myinterfaces__srv__Action_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // linear_x
  if (lhs->linear_x != rhs->linear_x) {
    return false;
  }
  // linear_y
  if (lhs->linear_y != rhs->linear_y) {
    return false;
  }
  // linear_z
  if (lhs->linear_z != rhs->linear_z) {
    return false;
  }
  // angular_x
  if (lhs->angular_x != rhs->angular_x) {
    return false;
  }
  // angular_y
  if (lhs->angular_y != rhs->angular_y) {
    return false;
  }
  // angular_z
  if (lhs->angular_z != rhs->angular_z) {
    return false;
  }
  // duration
  if (lhs->duration != rhs->duration) {
    return false;
  }
  return true;
}

bool
myinterfaces__srv__Action_Request__copy(
  const myinterfaces__srv__Action_Request * input,
  myinterfaces__srv__Action_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // linear_x
  output->linear_x = input->linear_x;
  // linear_y
  output->linear_y = input->linear_y;
  // linear_z
  output->linear_z = input->linear_z;
  // angular_x
  output->angular_x = input->angular_x;
  // angular_y
  output->angular_y = input->angular_y;
  // angular_z
  output->angular_z = input->angular_z;
  // duration
  output->duration = input->duration;
  return true;
}

myinterfaces__srv__Action_Request *
myinterfaces__srv__Action_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  myinterfaces__srv__Action_Request * msg = (myinterfaces__srv__Action_Request *)allocator.allocate(sizeof(myinterfaces__srv__Action_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(myinterfaces__srv__Action_Request));
  bool success = myinterfaces__srv__Action_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
myinterfaces__srv__Action_Request__destroy(myinterfaces__srv__Action_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    myinterfaces__srv__Action_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
myinterfaces__srv__Action_Request__Sequence__init(myinterfaces__srv__Action_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  myinterfaces__srv__Action_Request * data = NULL;

  if (size) {
    data = (myinterfaces__srv__Action_Request *)allocator.zero_allocate(size, sizeof(myinterfaces__srv__Action_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = myinterfaces__srv__Action_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        myinterfaces__srv__Action_Request__fini(&data[i - 1]);
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
myinterfaces__srv__Action_Request__Sequence__fini(myinterfaces__srv__Action_Request__Sequence * array)
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
      myinterfaces__srv__Action_Request__fini(&array->data[i]);
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

myinterfaces__srv__Action_Request__Sequence *
myinterfaces__srv__Action_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  myinterfaces__srv__Action_Request__Sequence * array = (myinterfaces__srv__Action_Request__Sequence *)allocator.allocate(sizeof(myinterfaces__srv__Action_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = myinterfaces__srv__Action_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
myinterfaces__srv__Action_Request__Sequence__destroy(myinterfaces__srv__Action_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    myinterfaces__srv__Action_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
myinterfaces__srv__Action_Request__Sequence__are_equal(const myinterfaces__srv__Action_Request__Sequence * lhs, const myinterfaces__srv__Action_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!myinterfaces__srv__Action_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
myinterfaces__srv__Action_Request__Sequence__copy(
  const myinterfaces__srv__Action_Request__Sequence * input,
  myinterfaces__srv__Action_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(myinterfaces__srv__Action_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    myinterfaces__srv__Action_Request * data =
      (myinterfaces__srv__Action_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!myinterfaces__srv__Action_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          myinterfaces__srv__Action_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!myinterfaces__srv__Action_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
myinterfaces__srv__Action_Response__init(myinterfaces__srv__Action_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  return true;
}

void
myinterfaces__srv__Action_Response__fini(myinterfaces__srv__Action_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
}

bool
myinterfaces__srv__Action_Response__are_equal(const myinterfaces__srv__Action_Response * lhs, const myinterfaces__srv__Action_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  return true;
}

bool
myinterfaces__srv__Action_Response__copy(
  const myinterfaces__srv__Action_Response * input,
  myinterfaces__srv__Action_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  return true;
}

myinterfaces__srv__Action_Response *
myinterfaces__srv__Action_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  myinterfaces__srv__Action_Response * msg = (myinterfaces__srv__Action_Response *)allocator.allocate(sizeof(myinterfaces__srv__Action_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(myinterfaces__srv__Action_Response));
  bool success = myinterfaces__srv__Action_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
myinterfaces__srv__Action_Response__destroy(myinterfaces__srv__Action_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    myinterfaces__srv__Action_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
myinterfaces__srv__Action_Response__Sequence__init(myinterfaces__srv__Action_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  myinterfaces__srv__Action_Response * data = NULL;

  if (size) {
    data = (myinterfaces__srv__Action_Response *)allocator.zero_allocate(size, sizeof(myinterfaces__srv__Action_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = myinterfaces__srv__Action_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        myinterfaces__srv__Action_Response__fini(&data[i - 1]);
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
myinterfaces__srv__Action_Response__Sequence__fini(myinterfaces__srv__Action_Response__Sequence * array)
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
      myinterfaces__srv__Action_Response__fini(&array->data[i]);
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

myinterfaces__srv__Action_Response__Sequence *
myinterfaces__srv__Action_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  myinterfaces__srv__Action_Response__Sequence * array = (myinterfaces__srv__Action_Response__Sequence *)allocator.allocate(sizeof(myinterfaces__srv__Action_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = myinterfaces__srv__Action_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
myinterfaces__srv__Action_Response__Sequence__destroy(myinterfaces__srv__Action_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    myinterfaces__srv__Action_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
myinterfaces__srv__Action_Response__Sequence__are_equal(const myinterfaces__srv__Action_Response__Sequence * lhs, const myinterfaces__srv__Action_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!myinterfaces__srv__Action_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
myinterfaces__srv__Action_Response__Sequence__copy(
  const myinterfaces__srv__Action_Response__Sequence * input,
  myinterfaces__srv__Action_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(myinterfaces__srv__Action_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    myinterfaces__srv__Action_Response * data =
      (myinterfaces__srv__Action_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!myinterfaces__srv__Action_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          myinterfaces__srv__Action_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!myinterfaces__srv__Action_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
