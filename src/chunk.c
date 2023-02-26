#include <stdlib.h>

#include "chunk.h"
#include "memory.h"

void initChunk(Chunk *chunk) {
  chunk->count = 0;
  chunk->capacity = 0;
  chunk->code = NULL;
}

void freeChunk(Chunk *chunk) {
  // free all the data we allocated in the array
  FREE_ARRAY(uint8_t, chunk->code, chunk->capacity);

  // zero out the values in the chunk
  initChunk(chunk);
}

void writeChunk(Chunk *chunk, uint8_t byte) {
  // if our new count of bytes in this chunk
  // will be greater than our capacity, we will
  // all grow our chunk array before adding our
  // new byte
  if (chunk->count + 1 > chunk->capacity) {
    int oldCapacity = chunk->capacity;
    chunk->capacity = GROW_CAPACITY(oldCapacity);
    chunk->code =
        GROW_ARRAY(uint8_t, chunk->code, oldCapacity, chunk->capacity);
  }

  // add the new byte to the chunk
  chunk->code[chunk->count] = byte;
  chunk->count++;
}
