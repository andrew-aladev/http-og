// HTTP old generation (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

#include "data.h"

#include <string.h>

#include "common.h"

#define CONSTANT_LENGTH_TEMPLATE "%zu"

void print_data()
{
  PRINT(CONSTANT);
  PRINT_GLUE();

  printf(CONSTANT_LENGTH_TEMPLATE, strlen(CONSTANT));
  PRINT_GLUE();
}
