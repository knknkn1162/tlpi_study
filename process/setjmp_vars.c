#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>

static jmp_buf env;

static void doJump(int nvar, int rvar, int vvar) {
  printf("Inside dojump: nvar=%d, rvar=%d, vvar=%d\n", nvar, rvar, vvar);
  longjmp(env, 1);
}

int main(int argc, char *argv[]) {
  volatile int nvar;
  volatile int rvar;
  volatile int vvar;

  nvar = 111;
  rvar = 222;
  vvar = 333;

  if (setjmp(env) == 0) {
    nvar = 777;
    rvar = 888;
    vvar = 999;

    doJump(nvar, rvar, vvar);
  } else {
    // Without volatile, The result is `After longjmp: nvar=111, rvar=222,
    // vvar=333` if `clang -O -o res -L. -ltlpi -Ilib ./process/setjmp_vars.c`
    printf("After longjmp: nvar=%d, rvar=%d, vvar=%d\n", nvar, rvar, vvar);
  }

  exit(EXIT_SUCCESS);
}
