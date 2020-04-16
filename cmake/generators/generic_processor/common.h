// HTTP old generation (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

#if !defined(COMMON_H)
#define COMMON_H

#include <stdio.h>

#include "options.h"

#define ALPHABET_RANGES HOG_ALPHABET_RANGES
#define ALPHABET_RANGES_LENGTH HOG_ALPHABET_RANGES_LENGTH

#define ALPHABET HOG_ALPHABET
#define ALPHABET_LENGTH HOG_ALPHABET_LENGTH

#define MIN_LENGTH HOG_MIN_LENGTH
#define MAX_LENGTH HOG_MAX_LENGTH

#define GLUE ";"

#define PRINT(string) fputs(string, stdout)
#define PRINT_ERROR(string) fputs(string, stderr)
#define PRINT_GLUE() PRINT(GLUE)

#endif // COMMON_H
