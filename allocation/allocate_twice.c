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
  // The error occurs when invoking free more than once!
  // res(10084,0x7fff8e5e1340) malloc: *** error for object 0x10c26f000: pointer
  // being freed was not allocated
  // *** set a breakpoint in malloc_error_break to debug */
  // zsh: abort      ./res
  // free(str);
}
