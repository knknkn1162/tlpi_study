#include <stdio.h>
#include <stdlib.h>

#include "tlpi_hdr.h"

int main(void) {
  int fd;
  // The characters X were replaced with random chars.
  char template[] = "/tmp/somestringXXXXXX";

  fd = mkstemp(template);
  if (fd == -1) {
    errExit("mkstemp");
  }

  printf("Generated filename was:%s \n", template);
  unlink(template);

  /* use file I/O system calls */

  if (close(fd) == -1) {
    errExit("close");
  }
}
