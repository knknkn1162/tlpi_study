#include <fcntl.h>
#include <sys/stat.h>
#include <sys/uio.h>

#include "tlpi_hdr.h"

int main(int argc, char* argv[]) {
  int fd;
  struct iovec iov[3];

#define STR_SIZE 7
  char str1[STR_SIZE];
  char str2[STR_SIZE * 3];
  char x;
  int i;
  ssize_t numRead, totRequired;

  if (argc != 2 || strcmp(argv[1], "--help") == 0) {
    usageErr("%s file\n", argv[0]);
  }

  fd = open(argv[1], O_RDONLY);
  if (fd == -1) {
    errExit("open");
  }

  totRequired = 0;

  iov[0].iov_base = str1;
  iov[0].iov_len = STR_SIZE - 1;
  totRequired += iov[0].iov_len;

  iov[1].iov_base = &x;
  iov[1].iov_len = 1;
  totRequired += iov[1].iov_len;

  iov[2].iov_base = str2;
  iov[2].iov_len = STR_SIZE * 3 - 1;
  totRequired += iov[2].iov_len;

  numRead = readv(fd, iov, 3);
  if (numRead == -1) {
    errExit("readv");
  }

  if (numRead < totRequired) {
    errExit("readv");
  }
  str1[STR_SIZE - 1] = '\0';
  str2[STR_SIZE * 3 - 1] = '\0';

  printf("total bytes requested: %ld; bytes read; %ld\n", (long)totRequired,
         (long)numRead);
  printf("iov[0]:\n%s\n", str1);
  printf("iov[1]:\n%c\n", x);
  printf("iov[2]:\n%s\n", str2);
  exit(EXIT_SUCCESS);
}
