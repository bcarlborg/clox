#ifndef CLOX_MEMORY_H
#define CLOX_MEMORY_H

#include "common.h"

// when you need to determine the new capacity
// for a dynamic array, use this macro to calculate
// the new capicity based on the old capacity
#define GROW_CAPACITY(capacity) ((capacity) < 8 ? 8 : (capacity)*2)

// when you have determined the new size of your array
// call this macro which will copy oldCount values from
// pointer to a new array of newCount size, then free the
// data at your old pointer
#define GROW_ARRAY(type, pointer, oldCount, newCount)                          \
  (type *)reallocate(pointer, sizeof(type) * (oldCount),                       \
                     sizeof(type) * newCount)

#define FREE_ARRAY(type, pointer, oldCount)                                    \
  reallocate(pointer, sizeof(type) * oldCount, 0)

void *reallocate(void *pointer, size_t oldSize, size_t newSize);

#endif /* CLOX_MEMORY_H */

