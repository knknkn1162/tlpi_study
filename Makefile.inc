# Makefile.inc - common definitions used by all makefiles

TLPI_DIR = ..
TLPI_LIB = ${TLPI_DIR}/libtlpi.a
TLPI_INCL_DIR = ${TLPI_DIR}/lib

CC = clang

IMPL_CFLAGS = -g -I${TLPI_INCL_DIR}

CFLAGS = ${IMPL_CFLAGS}

IMPL_LDLIBS = ${TLPI_LIB} -lm

LDLIBS = ${IMPL_LDLIBS}

RM = rm -f
