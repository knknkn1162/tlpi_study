#include <fcntl.h>
#include <sys/stat.h>

#include "tlpi_hdr.h"

int main(int argc, char* argv[]) {
  int newfd;
  ssize_t numWritten;
  if (close(2) == -1) {
    errExit("close error");
  }
  // duplicate file descripter #1(STDOUT) to #2.
  // Indeed, replace STDERR with STDOUT.
  newfd = dup2(1, 2);  // or dup(1);
  if (newfd == -1) {
    printf("dup2");
    errExit("dd");
  }
  numWritten =
      write(newfd, &argv[1][0], strlen(&argv[1][0]));  // STDERR -> STDOUT
  if (numWritten == -1) {
    errExit("dup");
  }
  printf("%ld bytes is written\n", (long)numWritten);  // STDOUT
}
