// HTTP old generation (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

#include "data.h"

#include <stdint.h>
#include <string.h>

#include "options.h"
#include "print.h"

#define SYMBOL_PREFIX "  "
#define SYMBOL_TEMPLATE "0x%02x"
#define SYMBOL_TERMINATOR ",\n"

#define LENGTH_TEMPLATE "%zu"

void print_data()
{
  for (size_t index = 0; index < strlen(HOG_CONSTANT); index++) {
    if (index == 0) {
      PRINT(SYMBOL_PREFIX);
    }
    else {
      PRINT(SYMBOL_TERMINATOR);
      PRINT(SYMBOL_PREFIX);
    }

    printf(SYMBOL_TEMPLATE, (uint8_t)HOG_CONSTANT[index]);
  }

  PRINT_GLUE();

  printf(LENGTH_TEMPLATE, strlen(HOG_CONSTANT));
  PRINT_GLUE();
}
