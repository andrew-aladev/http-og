// Old generation HTTP (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

#include "data.h"

#include <string.h>

#include "common.h"

#define CONSTANT_LENGTH "%zu"

void print_data()
{
  PRINT(CONSTANT);
  PRINT_GLUE();

  printf(CONSTANT_LENGTH, strlen(CONSTANT));
  PRINT_GLUE();
}
