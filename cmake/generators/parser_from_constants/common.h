// Old generation HTTP (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

#if !defined(COMMON_H)
#define COMMON_H

#include <stdio.h>

#include "constants.h"

#define CONSTANTS OGHTTP_CONSTANTS
#define CONSTANTS_LENGTH sizeof(CONSTANTS) / sizeof(CONSTANTS[0])
#define GLUE ";"

#define PRINT(string) fputs(string, stdout)
#define PRINT_ERROR(string) fputs(string, stderr)
#define PRINT_GLUE() PRINT(GLUE)

#endif // COMMON_H
