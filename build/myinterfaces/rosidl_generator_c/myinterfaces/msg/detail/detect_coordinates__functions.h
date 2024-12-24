// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from myinterfaces:msg/DetectCoordinates.idl
// generated code does not contain a copyright notice

#ifndef MYINTERFACES__MSG__DETAIL__DETECT_COORDINATES__FUNCTIONS_H_
#define MYINTERFACES__MSG__DETAIL__DETECT_COORDINATES__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "myinterfaces/msg/rosidl_generator_c__visibility_control.h"

#include "myinterfaces/msg/detail/detect_coordinates__struct.h"

/// Initialize msg/DetectCoordinates message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * myinterfaces__msg__DetectCoordinates
 * )) before or use
 * myinterfaces__msg__DetectCoordinates__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_myinterfaces
bool
myinterfaces__msg__DetectCoordinates__init(myinterfaces__msg__DetectCoordinates * msg);

/// Finalize msg/DetectCoordinates message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_myinterfaces
void
myinterfaces__msg__DetectCoordinates__fini(myinterfaces__msg__DetectCoordinates * msg);

/// Create msg/DetectCoordinates message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * myinterfaces__msg__DetectCoordinates__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_myinterfaces
myinterfaces__msg__DetectCoordinates *
myinterfaces__msg__DetectCoordinates__create();

/// Destroy msg/DetectCoordinates message.
/**
 * It calls
 * myinterfaces__msg__DetectCoordinates__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_myinterfaces
void
myinterfaces__msg__DetectCoordinates__destroy(myinterfaces__msg__DetectCoordinates * msg);

/// Check for msg/DetectCoordinates message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_myinterfaces
bool
myinterfaces__msg__DetectCoordinates__are_equal(const myinterfaces__msg__DetectCoordinates * lhs, const myinterfaces__msg__DetectCoordinates * rhs);

/// Copy a msg/DetectCoordinates message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_myinterfaces
bool
myinterfaces__msg__DetectCoordinates__copy(
  const myinterfaces__msg__DetectCoordinates * input,
  myinterfaces__msg__DetectCoordinates * output);

/// Initialize array of msg/DetectCoordinates messages.
/**
 * It allocates the memory for the number of elements and calls
 * myinterfaces__msg__DetectCoordinates__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_myinterfaces
bool
myinterfaces__msg__DetectCoordinates__Sequence__init(myinterfaces__msg__DetectCoordinates__Sequence * array, size_t size);

/// Finalize array of msg/DetectCoordinates messages.
/**
 * It calls
 * myinterfaces__msg__DetectCoordinates__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_myinterfaces
void
myinterfaces__msg__DetectCoordinates__Sequence__fini(myinterfaces__msg__DetectCoordinates__Sequence * array);

/// Create array of msg/DetectCoordinates messages.
/**
 * It allocates the memory for the array and calls
 * myinterfaces__msg__DetectCoordinates__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_myinterfaces
myinterfaces__msg__DetectCoordinates__Sequence *
myinterfaces__msg__DetectCoordinates__Sequence__create(size_t size);

/// Destroy array of msg/DetectCoordinates messages.
/**
 * It calls
 * myinterfaces__msg__DetectCoordinates__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_myinterfaces
void
myinterfaces__msg__DetectCoordinates__Sequence__destroy(myinterfaces__msg__DetectCoordinates__Sequence * array);

/// Check for msg/DetectCoordinates message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_myinterfaces
bool
myinterfaces__msg__DetectCoordinates__Sequence__are_equal(const myinterfaces__msg__DetectCoordinates__Sequence * lhs, const myinterfaces__msg__DetectCoordinates__Sequence * rhs);

/// Copy an array of msg/DetectCoordinates messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_myinterfaces
bool
myinterfaces__msg__DetectCoordinates__Sequence__copy(
  const myinterfaces__msg__DetectCoordinates__Sequence * input,
  myinterfaces__msg__DetectCoordinates__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // MYINTERFACES__MSG__DETAIL__DETECT_COORDINATES__FUNCTIONS_H_
