// Old generation HTTP (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

#if !defined(COMMON_H)
#define COMMON_H

#include <stdio.h>

#include "constant.h"

#define CONSTANT OGHTTP_CONSTANT
#define GLUE ";"

#define PRINT(string) fputs(string, stdout)
#define PRINT_GLUE() PRINT(GLUE)
#define PRINT_ERROR(string) fputs(string, stderr)

#endif // COMMON_H
