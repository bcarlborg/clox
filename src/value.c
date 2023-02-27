#include <stdio.h>

#include "memory.h"
#include "value.h"

void printValue(Value value) { printf("%g", value); }

void initValueArray(ValueArray *array) {
  array->capacity = 0;
  array->count = 0;
  array->values = NULL;
}

void writeValueArray(ValueArray *array, Value value) {
  // if our capacity in our array isn't big enough for the new
  // value, then lets grow the array before adding the value
  if (array->count + 1 > array->capacity) {
    int oldCapacity = array->capacity;
    array->capacity = GROW_CAPACITY(oldCapacity);
    array->values =
        GROW_ARRAY(Value, array->values, oldCapacity, array->capacity);
  }

  // add our value
  array->values[array->count] = value;
  array->count++;
}

void freeValueArray(ValueArray *array) {
  // free the dynamic data
  FREE_ARRAY(Value, array->values, array->capacity);

  // zero out the ValueArray struct
  // our init function zeroes everything out, so we can just call that
  initValueArray(array);
}
