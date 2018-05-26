#include <unistd.h>

#include "tlpi_hdr.h"

int main(int argc, char *argv[]) {
  printf("%ld\n", (long)getpid());
}
