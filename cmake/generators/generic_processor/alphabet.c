// HTTP old generation (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

#include "alphabet.h"

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#include "common.h"

#define ALLOWED_BYTES_PREFIX "  "
#define ALLOWED_BYTES_TEMPLATE "[%u] = true"
#define ALLOWED_BYTES_TERMINATOR ",\n"

static inline void print_allowed_byte(bool* first_byte_printed_ptr, char byte)
{
  if (*first_byte_printed_ptr) {
    PRINT(ALLOWED_BYTES_TERMINATOR);
    PRINT(ALLOWED_BYTES_PREFIX);
  }
  else {
    PRINT(ALLOWED_BYTES_PREFIX);
    *first_byte_printed_ptr = true;
  }

  printf(ALLOWED_BYTES_TEMPLATE, (uint8_t)byte);
}

void print_allowed_bytes()
{
  size_t index;
  bool   first_byte_printed = false;

  for (index = 0; index < HOG_ALPHABET_RANGES_LENGTH; index++) {
    hog_alphabet_range alphabet_range = HOG_ALPHABET_RANGES[index];

    for (char byte = alphabet_range.from; byte < alphabet_range.to; byte++) {
      print_allowed_byte(&first_byte_printed, byte);
    }

    print_allowed_byte(&first_byte_printed, alphabet_range.to);
  }

  for (index = 0; index < ALPHABET_LENGTH; index++) {
    print_allowed_byte(&first_byte_printed, ALPHABET[index]);
  }

  PRINT_GLUE();
}
