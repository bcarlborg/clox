#include "chunk.h"
#include "common.h"
#include "debug.h"
#include "vm.h"

int main(int argc, const char *argv[]) {
  int constant_index;
  initVM();

  Chunk chunk;
  initChunk(&chunk);

  constant_index = addConstant(&chunk, 99.99);
  writeChunk(&chunk, OP_CONSTANT, 122);
  writeChunk(&chunk, constant_index, 123);

  constant_index = addConstant(&chunk, 1.2);
  writeChunk(&chunk, OP_CONSTANT, 123);
  writeChunk(&chunk, constant_index, 123);

  writeChunk(&chunk, OP_RETURN, 123);

  interpret(&chunk);

  freeVM();
  freeChunk(&chunk);
  return 0;
}
