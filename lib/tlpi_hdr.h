#ifndef TLPI_HDR_H
#define TLPI_HDR_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

#include <errno.h>
#include <string.h>
#include <unistd.h>

#include "error_functions.h"
#include "get_num.h"

#ifndef HAS_BOOLEAN
typedef enum { FALSE, TRUE } Boolean;
#endif

#define min(m, n) ((m) < (n) ? (m) : (n))
#define max(m, n) ((m) > (n) ? (m) : (n))

#endif
