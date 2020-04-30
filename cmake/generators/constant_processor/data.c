// HTTP old generation (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

#include "data.h"

#include <stdint.h>
#include <string.h>

#include "options.h"
#include "print.h"

#define BYTE_TEMPLATE "0x%02x"

#define PRINT_BYTE(byte) printf(BYTE_TEMPLATE, byte);

void print_data()
{
  INITIALIZE_SPACERS();

  for (size_t index = 0; index < strlen(HOG_CONSTANT); index++) {
    uint8_t byte = HOG_CONSTANT[index];

    PRINT_SPACER();
    PRINT_BYTE(byte);
  }

  PRINT_GLUE();

  PRINT_LENGTH(strlen(HOG_CONSTANT));
  PRINT_GLUE();
}
