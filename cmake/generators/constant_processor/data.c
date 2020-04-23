// HTTP old generation (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

#include "data.h"

#include <stdint.h>
#include <string.h>

#include "options.h"
#include "print.h"

#define BYTE_PREFIX "  "
#define BYTE_TEMPLATE "0x%02x"
#define BYTE_TERMINATOR ",\n"

#define LENGTH_TEMPLATE "%zu"

void print_data()
{
  for (size_t index = 0; index < strlen(HOG_CONSTANT); index++) {
    if (index == 0) {
      PRINT(BYTE_PREFIX);
    }
    else {
      PRINT(BYTE_TERMINATOR);
      PRINT(BYTE_PREFIX);
    }

    uint8_t byte = HOG_CONSTANT[index];
    printf(BYTE_TEMPLATE, byte);
  }

  PRINT_GLUE();

  printf(LENGTH_TEMPLATE, strlen(HOG_CONSTANT));
  PRINT_GLUE();
}
