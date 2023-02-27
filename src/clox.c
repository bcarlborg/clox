#include "chunk.h"
#include "common.h"
#include "debug.h"

int main(int argc, const char *argv[]) {
  Chunk chunk;
  initChunk(&chunk);

  writeChunk(&chunk, OP_RETURN);

  int constant_index = addConstant(&chunk, 1.2);
  writeChunk(&chunk, OP_CONSTANT);
  writeChunk(&chunk, constant_index);

  disassembleChunk(&chunk, "test chunk");

  freeChunk(&chunk);
  return 0;
}
