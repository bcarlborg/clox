#ifndef CLOX_DEBUG_H
#define CLOX_DEBUG_H

#include "chunk.h"

// disassemble all bytes in a chunk
void disassembleChunk(Chunk *chunk, const char *name);

// disassemble a single instruction in a chunk
// returns the offset of the start of the next instruction
int disassembleInstruction(Chunk *chunk, int offset);

#endif /* CLOX_DEBUG_H */
