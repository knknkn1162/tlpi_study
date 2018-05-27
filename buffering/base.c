#include <stdio.h>

int main(int argc, char *argv[]) {
  printf("%d", BUFSIZ);  // 1024 in MacOS
  fflush(NULL);
}
