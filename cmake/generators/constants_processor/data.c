// HTTP old generation (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

#include "data.h"

#include "common.h"

#define LENGTH_TEMPLATE "%zu"

void print_data()
{
  printf(LENGTH_TEMPLATE, CONSTANTS_LENGTH);
  PRINT_GLUE();
}
