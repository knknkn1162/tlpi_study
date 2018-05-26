#include <stdio.h>
#include "tlpi_hdr.h"

int main(void) {
  int i;
  char* str;
  printf("Initial program break: %10p\n", sbrk(0));
#define SIZE 1000
  str = malloc(1000000);
  for (i = 0; i < SIZE; i++) {
    str[i] = 'a' + i % 20;
  }
  str[SIZE] = '\0';
  printf("str: %s\n", str);
  // same as initial program break
  printf("After program break: %10p\n", sbrk(0));
  free(str);
}
