// Old generation HTTP (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

#include "data.h"

#include <stdlib.h>

#include "common.h"

#define CONSTANT_PREFIX "  "
#define CONSTANT_TEMPLATE "\"%s\""
#define CONSTANT_TERMINATOR ",\n"

void print_data()
{
  for (size_t index = 0; index < CONSTANTS_LENGTH; index++) {
    if (index == 0) {
      PRINT(CONSTANT_PREFIX);
    }
    else {
      PRINT(CONSTANT_TERMINATOR);
      PRINT(CONSTANT_PREFIX);
    }

    printf(CONSTANT_TEMPLATE, CONSTANTS[index]);
  }

  PRINT_GLUE();
}
