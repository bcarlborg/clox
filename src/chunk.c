#include <stdlib.h>

#include "chunk.h"
#include "memory.h"

void initChunk(Chunk *chunk) {
  chunk->count = 0;
  chunk->capacity = 0;
  chunk->code = NULL;
  chunk->lines = NULL;
  initValueArray(&chunk->constants);
}

void freeChunk(Chunk *chunk) {
  // free all the data we allocated in our chunk
  FREE_ARRAY(uint8_t, chunk->code, chunk->capacity);
  FREE_ARRAY(int, chunk->lines, chunk->capacity);

  // also free any constants in our chunk
  freeValueArray(&chunk->constants);

  // zero out the values in the chunk
  initChunk(chunk);
}

void writeChunk(Chunk *chunk, uint8_t byte, int line) {
  // if our new count of bytes in this chunk
  // will be greater than our capacity, we will
  // all grow our chunk array before adding our
  // new byte
  if (chunk->count + 1 > chunk->capacity) {
    int oldCapacity = chunk->capacity;
    chunk->capacity = GROW_CAPACITY(oldCapacity);
    chunk->code =
        GROW_ARRAY(uint8_t, chunk->code, oldCapacity, chunk->capacity);
    chunk->lines = GROW_ARRAY(int, chunk->lines, oldCapacity, chunk->capacity);
  }

  // add the new byte to the chunk and add its associated line number
  chunk->code[chunk->count] = byte;
  chunk->lines[chunk->count] = line;
  chunk->count++;
}

int addConstant(Chunk *chunk, Value value) {
  writeValueArray(&chunk->constants, value);
  return chunk->constants.count - 1;
}

