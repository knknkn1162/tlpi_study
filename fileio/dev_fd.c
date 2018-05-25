#include <fcntl.h>
#include <sys/stat.h>

#include "tlpi_hdr.h"

int main(int argc, char *argv[]) {
  int fd = open("/dev/fd/1", O_WRONLY);
  printf("%d", fd);
}
