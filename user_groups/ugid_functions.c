#include <ctype.h>
#include <grp.h>
#include <pwd.h>
// in macOS, there doesn't exist shadow password file.
// Try also `ls /etc | grep shadow`.
//#include <shadow.h>
#include <sys/types.h>

#include "tlpi_hdr.h"

char *userNameFromId(uid_t uid) {
  struct passwd *pwd;

  pwd = getpwuid(uid);
  printf("%s\n", pwd->pw_passwd);
  return (pwd == NULL) ? NULL : pwd->pw_name;
}

uid_t userIdFromName(const char *name) {
  struct passwd *pwd;
  uid_t u;
  char *endptr;

  if (name == NULL || *name == '\0') {
    return -1;
  }

  u = strtol(name, &endptr, 10);
  if (*endptr == '\0') {
    return u;
  }

  pwd = getpwnam(name);
  if (pwd == NULL) {
    return -1;
  }

  return pwd->pw_uid;
}

char *groupNameFromId(gid_t gid) {
  struct group *grp;
  grp = getgrgid(gid);
  return (grp == NULL) ? NULL : grp->gr_name;
}

gid_t groupIdFromName(const char *name) {
  struct group *grp;
  gid_t g;
  char *endptr;

  if (name == NULL || *name == '\0') {
    return -1;
  }

  g = strtol(name, &endptr, 10);
  if (*endptr == '\0') {
    return g;
  }

  grp = getgrnam(name);

  if (grp == NULL) {
    return -1;
  }

  return grp->gr_gid;
}

int main(int argc, char *argv[]) {
  int id = getInt(argv[1], GN_NONNEG, "uid");
  char *name = userNameFromId(id);
  char *groupName = groupNameFromId(id);

  struct passwd *pw;

  printf("name: %s\n", name);
  printf("group name: %s\n", groupName);
  printf("+ passwd list\n");

  while ((pw = getpwent()) != NULL) {
    printf("%d:%s -> password: %s\n", pw->pw_uid, pw->pw_name, pw->pw_passwd);
  }
  endpwent();
}
