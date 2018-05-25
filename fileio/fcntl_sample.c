#include <ctype.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "tlpi_hdr.h"

int main(int argc, char* argv[]) {
  int flags, accMode;
  ssize_t numWritten;
  int fd = open(argv[1], O_WRONLY);
  flags = fcntl(fd, F_GETFL);

  if (flags == -1) {
    errExit("fcntl");
  }

  flags |= O_APPEND;
  if (fcntl(fd, F_SETFL, flags) == -1) {
    errExit("fcntl");
  }
  numWritten = write(fd, &argv[2][0], strlen(&argv[2][0]));
  if (numWritten == -1) {
    errExit("write");
  }
  printf("%s: wrote %ld bytes\n", argv[2], (long)numWritten);
}
