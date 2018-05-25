#include <ctype.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "tlpi_hdr.h"

int main(int argc, char *argv[]) {
  int flags, accessMode;
  int fd = open(argv[1], O_WRONLY);
  flags = fcntl(fd, F_GETFL);
  accessMode = flags & O_ACCMODE;
  printf("%d\n", flags);
  if (flags == -1) {
    errExit("fcntl1");
  }
  if (accessMode == O_WRONLY || accessMode == O_RDWR) {
    printf("file is writable\n");
  }
  if (flags & O_SYNC) {
    printf("writes are synchronized\n");
  }
}
