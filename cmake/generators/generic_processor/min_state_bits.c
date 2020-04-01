// HTTP old generation (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

#include "min_state_bits.h"

#include <stdint.h>
#include <stdlib.h>

#include "common.h"

int print_min_state_bits()
{
  char* min_state_bits;

  if (MAX_LENGTH <= UINT8_MAX) {
    min_state_bits = "8";
  }
  else if (MAX_LENGTH <= UINT16_MAX) {
    min_state_bits = "16";
  }
  else if (MAX_LENGTH <= UINT32_MAX) {
    min_state_bits = "32";
  }
  else {
    PRINT_ERROR("max length is too big\n");
    return 1;
  }

  PRINT(min_state_bits);
  PRINT_GLUE();

  return 0;
}
