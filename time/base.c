#include <stdio.h>
#include <sys/time.h>
#include <time.h>

#define TIME_SIZE 100

int main(int argc, char *argv[]) {
  struct timeval tv;
  time_t tm;
  char res = gettimeofday(&tv, NULL);
  struct tm *localtm;
  printf("start: %ld CLOCKS_PER_SEC: %ld\n", clock(), (long)CLOCKS_PER_SEC);
  tm = time(NULL);

  printf("tv_sec: %ld, tv_usec: %d => return : %d\n", tv.tv_sec, tv.tv_usec,
         res);
  printf("time: %ld\n", tm);
  printf("ctime: %s\n", ctime(&tm));

  localtm = localtime(&tm);
  printf("%d:%d:%d\n", localtm->tm_hour, localtm->tm_min, localtm->tm_sec);

  tm = mktime(localtm);
  printf("asctime: %s\n", asctime(localtm));
  printf("%ld\n", tm);
  printf("end: %ld\n", clock());
}
