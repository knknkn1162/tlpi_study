# TLPI(The Linux Programming Interface) for MacOSX

This is my reminder for the book TLPI with MacOSX (High Sierra). This code of the repository is suitable for MacOS, which is based on http://man7.org/tlpi/code/index.html.

## Usage

1. `git clone git@github.com:knknkn1162/tlpi_study.git`.

2. Execute the below commands to create `libtlpi.a`, which is static library.

```bash
# lib directory contains error-handling functions & the functions for parsing command-line arguments
cd lib
# Remove CC option in the Makefile.inc if you want to compile codes with gcc.
make # generate libtlpi.a in the parent directory
```

3. If you compile each C code, return to the parent directory and take the below command.

```
# make sure that the `-L` option to indicate the directory of the static library, which is in the root directory.
clang -o copy -L. -ltlpi -Ilib fileio/copy.c # you can replace clang with gcc.
```

## Licence

Each file is licensed under the either GNU General Public License (Version 3) (most files) or the GNU Lesser General Public License (Version 3) (library code); see the individual files for details.
