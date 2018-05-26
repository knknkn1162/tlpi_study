// In MacOX, use the below header instead of declaring `extern char etext,
// edata, end`.
// See also https://stackoverflow.com/a/9187099/8774173
#include <mach-o/getsect.h>
#include <stdio.h>
#include <unistd.h>

int main(void) {
  void *brk = (void *)sbrk(0);
  void *end = (void *)get_end();
  /* end: 0x100003000, brk: 0x1008ed000 */
  /* size: (9347072) */
  printf("end: %p, brk: %p\nsize: (%ld)\n", end, brk, (brk - end));
}
