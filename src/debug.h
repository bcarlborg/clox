#ifndef clox_debug_h
#define clox_debug_h

#include "chunk.h"

// disassemble all bytes in a chunk
void disassembleChunk(Chunk *chunk, const char *name);

// disassemble a single instruction in a chunk
// returns the offset of the start of the next instruction
int disassembleInstruction(Chunk *chunk, int offset);

#endif
