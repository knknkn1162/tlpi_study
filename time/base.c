#include <stdio.h>
#include <sys/time.h>
#include <time.h>

int main(int argc, char *argv[]) {
  struct timeval tv;
  int res;
  time_t tm;
  res = gettimeofday(&tv, NULL);

  tm = time(NULL);
  printf("tv_sec: %ld, tv_usec: %d => return : %d\n", tv.tv_sec, tv.tv_usec,
         res);
  printf("time: %ld\n", tm);
}
