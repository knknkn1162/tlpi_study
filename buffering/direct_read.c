#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "tlpi_hdr.h"

int main(int argc, char *argv[]) {
  int fd, s;
  ssize_t numRead;
  size_t length, alignment;
  off_t offset;
  void *buf;

  if (argc < 3 || strcmp(argv[1], "--help") == 0) {
    usageErr("%s file length [offset [alignment]]\n", argv[0]);
  }

  length = getLong(argv[2], GN_ANY_BASE, "length");
  offset = (argc > 3) ? getLong(argv[3], GN_ANY_BASE, "offset") : 0;
  alignment = (argc > 4) ? getLong(argv[4], GN_ANY_BASE, "alignment") : 4096;

  fd = open(argv[1], O_RDONLY);
  fcntl(fd, F_NOCACHE, 1);

  if (fd == -1) {
    errExit("open");
  }
  printf("alignment: %zu\n", alignment);
  printf("_PR_REC_XFER_ALIGN: %ld\n", pathconf("./", (long)_PC_REC_XFER_ALIGN));
  s = posix_memalign(&buf, alignment * 2, length + alignment);
  buf = (char *)buf + alignment;
  if (s != 0) {
    errExit("memalign");
  }

  if (lseek(fd, offset, SEEK_SET) == -1) {
    errExit("lseek");
  }

  numRead = read(fd, buf, length);
  if (numRead == -1) {
    errExit("read");
  }

  printf("Read %ld bytes\n", (long)numRead);

  exit(EXIT_SUCCESS);
}
