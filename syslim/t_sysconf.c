#include <stdio.h>
#include <unistd.h>

#include "tlpi_hdr.h"

static void sysConfPrint(const char* msg, int name) {
  long lim;
  errno = 0;

  lim = sysconf(name);

  if (lim != -1) {
    printf("%s %ld\n", msg, lim);
  } else {
    if (errno == 0) {
      printf("%s (indeterminate)\n", msg);
    } else {
      errExit("sysconf %s", msg);
    }
  }
}

static void fpathconfPrint(const char* msg, int fd, int name) {
  long lim;
  errno = 0;

  lim = fpathconf(fd, name);

  if (lim != -1) {
    printf("%s %ld\n", msg, lim);
  } else {
    if (errno == 0) {
      printf("%s (indeterminate)\n", msg);
    } else {
      errExit("fpathconf %s", msg);
    }
  }
}
// exec as `./res < .`
int main(int argc, char* argv[]) {
  sysConfPrint("_SC_ARG_MAX", _SC_ARG_MAX);
  sysConfPrint("_SC_CLK_TCK", _SC_CLK_TCK);
  sysConfPrint("_SC_LOGIN_NAME_MAX", _SC_LOGIN_NAME_MAX);
  sysConfPrint("_SC_OPEN_MAX", _SC_OPEN_MAX);
  sysConfPrint("_SC_NGROUPS_MAX", _SC_NGROUPS_MAX);
  sysConfPrint("_SC_PAGESIZE", _SC_PAGESIZE);
  sysConfPrint("_SC_RTSIG_MAX", _SC_RTSIG_MAX);
  sysConfPrint("_SC_SIGQUEUE_MAX", _SC_SIGQUEUE_MAX);
  sysConfPrint("_SC_MQ_PRIO_MAX", _SC_MQ_PRIO_MAX);
  sysConfPrint("_SC_STREAM_MAX", _SC_STREAM_MAX);
  sysConfPrint("_PC_NAME_MAX", _PC_NAME_MAX);
  sysConfPrint("_PC_PATH_MAX", _PC_PATH_MAX);
  sysConfPrint("_PC_PIPE_BUF", _PC_PIPE_BUF);

  fpathconfPrint("_PC_NAME_MAX", STDIN_FILENO, _PC_NAME_MAX);
  fpathconfPrint("_PC_PATH_MAX", STDIN_FILENO, _PC_PATH_MAX);
  fpathconfPrint("_PC_PIPE_BUF", STDIN_FILENO, _PC_PIPE_BUF);
}
