#include <stdio.h>
#include <stdlib.h>
#include "tlpi_hdr.h"

extern char **environ;

int main(int argc, char *argv[]) {
  char **ep;
  char *session_id = getenv(&argv[1][0]);
  for (ep = environ; *ep != NULL; ep++) {
    puts(*ep);
  }
  puts(session_id);

  exit(EXIT_SUCCESS);
}
