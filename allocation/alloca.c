#include <alloca.h>
#include "tlpi_hdr.h"

int main(int argc, char* argv[]) {
  void* y;
  size_t alloca_size = getLong(argv[1], GN_GT_0, "alloc");
  printf("Initial program break: %10p\n", sbrk(0));
  y = alloca(alloca_size);
  printf("After alloca; program break: %10p\n", sbrk(0));
}
