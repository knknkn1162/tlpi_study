#include <stdlib.h>
#include "tlpi_hdr.h"

int main(void) {
  int s;
  void *memptr;

  // `memalign` doesn't exist mac OS. Use `posix_memalign`
  s = posix_memalign(&memptr, 1024 * sizeof(void *), 65536);
  if (s != 0) {
    errExit("posix_memalign");
  }
}
