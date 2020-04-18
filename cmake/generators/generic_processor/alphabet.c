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

// -- inclusive --

static inline bool find_byte_in_ranges(char target_byte)
{
  for (size_t index = 0; index < ALPHABET_RANGES_LENGTH; index++) {
    alphabet_range_t range = ALPHABET_RANGES[index];

    if (target_byte >= range.from && target_byte <= range.to) {
      return true;
    }
  }

  return false;
}

static inline void print_alphabet_including_bytes_into_ranges()
{
  size_t index;
  char   byte;
  bool   first_byte_printed = false;

  for (index = 0; index < ALPHABET_RANGES_LENGTH; index++) {
    alphabet_range_t range = ALPHABET_RANGES[index];

    for (byte = range.from; byte < range.to; byte++) {
      print_allowed_byte(&first_byte_printed, byte);
    }

    byte = range.to;
    print_allowed_byte(&first_byte_printed, byte);
  }

  for (index = 0; index < ALPHABET_LENGTH; index++) {
    byte = ALPHABET[index];

    if (!find_byte_in_ranges(byte)) {
      print_allowed_byte(&first_byte_printed, byte);
    }
  }
}

// -- exclusive --

static inline bool find_byte_in_bytes(char target_byte)
{
  for (size_t index = 0; index < ALPHABET_LENGTH; index++) {
    char byte = ALPHABET[index];

    if (target_byte == byte) {
      return true;
    }
  }

  return false;
}

static inline void print_alphabet_excluding_bytes_from_ranges()
{
  size_t index;
  char   byte;
  bool   first_byte_printed = false;

  for (index = 0; index < ALPHABET_RANGES_LENGTH; index++) {
    alphabet_range_t range = ALPHABET_RANGES[index];

    for (byte = range.from; byte < range.to; byte++) {
      if (!find_byte_in_bytes(byte)) {
        print_allowed_byte(&first_byte_printed, byte);
      }
    }

    byte = range.to;

    if (!find_byte_in_bytes(byte)) {
      print_allowed_byte(&first_byte_printed, byte);
    }
  }
}

void print_allowed_bytes()
{
  if (ALPHABET_MODE == ALPHABET_INCLUDING_BYTES_INTO_RANGES) {
    print_alphabet_including_bytes_into_ranges();
  }
  else {
    print_alphabet_excluding_bytes_from_ranges();
  }

  PRINT_GLUE();
}
