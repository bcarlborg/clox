#ifndef clox_chunk_h
#define clox_chunk_h

#include "common.h"

typedef enum {
	OP_RETURN,
} OpCode;

typedef struct {
	int count;
	int capacity;
	uint8_t* code; // pointer to an array
} Chunk;

void initChunk(Chunk *chunk);

void freeChunk(Chunk *chunk);

// add a new byte to the collection of bytes
// in this chunk
void writeChunk(Chunk *chunk, uint8_t byte);

#endif
