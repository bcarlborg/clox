#ifndef CLOX_CHUNK_H
#define CLOX_CHUNK_H

#include "common.h"
#include "value.h"

typedef enum {
  OP_RETURN,
  OP_CONSTANT,
} OpCode;

typedef struct {
  int count;
  int capacity;
  uint8_t *code; // pointer to an array
  ValueArray constants;
} Chunk;

void initChunk(Chunk *chunk);

void freeChunk(Chunk *chunk);

// add a new byte to the collection of bytes
// in this chunk
void writeChunk(Chunk *chunk, uint8_t byte);

// add a new constant to our chunk and return the
// index of that constatnt in the constants array
int addConstant(Chunk *chunk, Value value);

#endif /* CLOX_CHUNK_H */
