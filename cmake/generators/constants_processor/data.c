// HTTP old generation (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

#include "data.h"

#include <stdlib.h>

#include "common.h"

#define CONSTANTS_LENGTH_TEMPLATE "%zu"

void print_data()
{
  printf(CONSTANTS_LENGTH_TEMPLATE, CONSTANTS_LENGTH);
  PRINT_GLUE();
}
