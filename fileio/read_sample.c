#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

#include "tlpi_hdr.h"

#define MAX_READ 10

int main(void) {
  char buffer[MAX_READ + 1];
  int numRead = read(STDIN_FILENO, buffer, MAX_READ);
  if (numRead == -1) {
    errExit("read");
  }

  buffer[numRead] = '\0';
  printf("%s\n", buffer);
}
