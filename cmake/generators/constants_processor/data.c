// HTTP old generation (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

#include "data.h"

#include "common.h"

#define CONSTANTS_PREFIX "  "
#define CONSTANTS_TEMPLATE "\"%s\""
#define CONSTANTS_TERMINATOR ",\n"

void print_data()
{
  for (size_t index = 0; index < CONSTANTS_LENGTH; index++) {
    if (index == 0) {
      PRINT(CONSTANTS_PREFIX);
    }
    else {
      PRINT(CONSTANTS_TERMINATOR);
      PRINT(CONSTANTS_PREFIX);
    }

    printf(CONSTANTS_TEMPLATE, CONSTANTS[index]);
  }

  PRINT_GLUE();
}
