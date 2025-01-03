// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from myinterfaces:msg/State.idl
// generated code does not contain a copyright notice
#include "myinterfaces/msg/detail/state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
myinterfaces__msg__State__init(myinterfaces__msg__State * msg)
{
  if (!msg) {
    return false;
  }
  // apriltag
  // task
  return true;
}

void
myinterfaces__msg__State__fini(myinterfaces__msg__State * msg)
{
  if (!msg) {
    return;
  }
  // apriltag
  // task
}

bool
myinterfaces__msg__State__are_equal(const myinterfaces__msg__State * lhs, const myinterfaces__msg__State * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // apriltag
  if (lhs->apriltag != rhs->apriltag) {
    return false;
  }
  // task
  if (lhs->task != rhs->task) {
    return false;
  }
  return true;
}

bool
myinterfaces__msg__State__copy(
  const myinterfaces__msg__State * input,
  myinterfaces__msg__State * output)
{
  if (!input || !output) {
    return false;
  }
  // apriltag
  output->apriltag = input->apriltag;
  // task
  output->task = input->task;
  return true;
}

myinterfaces__msg__State *
myinterfaces__msg__State__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  myinterfaces__msg__State * msg = (myinterfaces__msg__State *)allocator.allocate(sizeof(myinterfaces__msg__State), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(myinterfaces__msg__State));
  bool success = myinterfaces__msg__State__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
myinterfaces__msg__State__destroy(myinterfaces__msg__State * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    myinterfaces__msg__State__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
myinterfaces__msg__State__Sequence__init(myinterfaces__msg__State__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  myinterfaces__msg__State * data = NULL;

  if (size) {
    data = (myinterfaces__msg__State *)allocator.zero_allocate(size, sizeof(myinterfaces__msg__State), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = myinterfaces__msg__State__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        myinterfaces__msg__State__fini(&data[i - 1]);
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
myinterfaces__msg__State__Sequence__fini(myinterfaces__msg__State__Sequence * array)
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
      myinterfaces__msg__State__fini(&array->data[i]);
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

myinterfaces__msg__State__Sequence *
myinterfaces__msg__State__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  myinterfaces__msg__State__Sequence * array = (myinterfaces__msg__State__Sequence *)allocator.allocate(sizeof(myinterfaces__msg__State__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = myinterfaces__msg__State__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
myinterfaces__msg__State__Sequence__destroy(myinterfaces__msg__State__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    myinterfaces__msg__State__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
myinterfaces__msg__State__Sequence__are_equal(const myinterfaces__msg__State__Sequence * lhs, const myinterfaces__msg__State__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!myinterfaces__msg__State__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
myinterfaces__msg__State__Sequence__copy(
  const myinterfaces__msg__State__Sequence * input,
  myinterfaces__msg__State__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(myinterfaces__msg__State);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    myinterfaces__msg__State * data =
      (myinterfaces__msg__State *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!myinterfaces__msg__State__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          myinterfaces__msg__State__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!myinterfaces__msg__State__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
