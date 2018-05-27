#include <sys/utsname.h>
#include "tlpi_hdr.h"

int main(int argc, char *argv[]) {
  struct utsname uts;
  if (uname(&uts) == -1) {
    errExit("uname");
  }
  /* Node name: MOB18006.local */
  /* System name Darwin */
  /* Release 17.4.0 */
  /* Version Darwin Kernel Version 17.4.0: Sun Dec 17 09:19:54 PST 2017;
   * root:xnu-4570.41.2~1/RELEASE_X86_64 */
  /* Machine x86_64 */
  printf("Node name: %s\n", uts.nodename);
  printf("System name %s\n", uts.sysname);
  printf("Release %s\n", uts.release);
  printf("Version %s\n", uts.version);
  printf("Machine %s\n", uts.machine);
}
