#ifndef CLOX_CHUNK_H
#define CLOX_CHUNK_H

#include "common.h"
#include "value.h"

typedef enum {
  OP_CONSTANT,
  OP_NEGATE,
  OP_ADD,
  OP_SUBTRACT,
  OP_MULTIPLY,
  OP_DIVIDE,
  OP_RETURN,
} OpCode;

typedef struct {
  int count;
  int capacity;
  uint8_t *code; // array of op codes and arguments
  int *lines;    // line number for each element in code,
                 //		has a 1:1 mapping with code.
  ValueArray constants;
} Chunk;

void initChunk(Chunk *chunk);

void freeChunk(Chunk *chunk);

// add a new byte to the collection of bytes
// in this chunk
void writeChunk(Chunk *chunk, uint8_t byte, int line);

// add a new constant to our chunk and return the
// index of that constatnt in the constants array
int addConstant(Chunk *chunk, Value value);

#endif /* CLOX_CHUNK_H */
