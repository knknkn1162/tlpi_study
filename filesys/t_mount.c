#include <sys/mount.h>
#include <sys/statvfs.h>
#define HAS_BOOLEAN
#include "tlpi_hdr.h"

int main(int argc, char *argv[]) {
  unsigned long flags;
  char *data, *fstype;
  struct statvfs statvfsbuf;

  int res = statvfs(argv[1], &statvfsbuf);
  if (res == -1) {
    errExit("statvfs");
  }
  printf("%lu\n", statvfsbuf.f_bsize);
  printf("%u\n", statvfsbuf.f_files);
  printf("%u\n", statvfsbuf.f_ffree);
  printf("%lu\n", statvfsbuf.f_fsid);
  printf("%lu\n", statvfsbuf.f_flag);

  /* int j, opt; */

  /* flags = 0; */
  /* data = NULL; */
  /* fstype = NULL; */

  /* while ((opt = getopt(argc, argv, "o:t:f:")) != -1) { */
  /* switch (opt) { */
  /* case 'o': */
  /* data = optarg; */
  /* break; */
  /* case 't': */
  /* fstype = optarg; */
  /* break; */
  /* case 'f': */
  /* for (j = 0; j < strlen(optarg); j++) { */
  /* switch (optarg[j]) { */
  /* case 'b': */
  /* flags |= MS_BIND; */
  /* break; */
  /* } */
  /* } */
  /* break; */
  /* default: */
  /* errExit("optget"); */
  /* } */
  /* } */

  /* if (argc != optind + 2) { */
  /* usageError(argv[0], "Wrong number of arguments\n"); */
  /* } */

  /* if (mount(argv[optind + 1], fstype, flags, data) == -1) { */
  /* errExit("mount"); */
  /* } */

  exit(EXIT_SUCCESS);
}
