// In MacOX, use the below header instead of declaring `extern char etext,
// edata, end`.
// See also https://stackoverflow.com/a/9187099/8774173
#include <mach-o/getsect.h>
#include <stdio.h>
#include <unistd.h>

int main(void) {
  void *brk = sbrk(0);
  /* % ./res */
  /* end: 0x100003000, brk: 0x10994f000 */
  /* MOB18006:clang % ./res */
  /* end: 0x100003000, brk: 0x107393000 */
  /* MOB18006:clang % ./res */
  /* end: 0x100003000, brk: 0x1057bf000 */
  printf("end: %p, brk: %p\n", (void *)get_end(), brk);
}
