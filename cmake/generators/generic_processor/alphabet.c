// HTTP old generation (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

#include "alphabet.h"

#include <stdint.h>
#include <stdlib.h>

#include "options.h"
#include "print.h"

#define ALLOWED_BYTE_TEMPLATE "[%u] = true"

#define PRINT_ALLOWED_BYTE(byte) printf(ALLOWED_BYTE_TEMPLATE, (uint8_t)byte);

// -- inclusive --

static inline bool find_byte_in_ranges(char target_byte)
{
  for (size_t index = 0; index < HOG_ALPHABET_RANGES_LENGTH; index++) {
    hog_alphabet_range_t range = HOG_ALPHABET_RANGES[index];

    if (target_byte >= range.from && target_byte <= range.to) {
      return true;
    }
  }

  return false;
}

static inline void print_alphabet_including_bytes_into_ranges()
{
  INITIALIZE_SPACERS();

  size_t index;
  char   byte;

  for (index = 0; index < HOG_ALPHABET_RANGES_LENGTH; index++) {
    hog_alphabet_range_t range = HOG_ALPHABET_RANGES[index];

    for (byte = range.from; byte < range.to; byte++) {
      PRINT_SPACER();
      PRINT_ALLOWED_BYTE(byte);
    }

    PRINT_SPACER();
    PRINT_ALLOWED_BYTE(range.to);
  }

  for (index = 0; index < HOG_ALPHABET_LENGTH; index++) {
    byte = HOG_ALPHABET[index];

    if (!find_byte_in_ranges(byte)) {
      PRINT_SPACER();
      PRINT_ALLOWED_BYTE(byte);
    }
  }
}

// -- exclusive --

static inline bool find_byte_in_bytes(char target_byte)
{
  for (size_t index = 0; index < HOG_ALPHABET_LENGTH; index++) {
    char byte = HOG_ALPHABET[index];

    if (target_byte == byte) {
      return true;
    }
  }

  return false;
}

static inline void print_alphabet_excluding_bytes_from_ranges()
{
  INITIALIZE_SPACERS();

  size_t index;
  char   byte;

  for (index = 0; index < HOG_ALPHABET_RANGES_LENGTH; index++) {
    hog_alphabet_range_t range = HOG_ALPHABET_RANGES[index];

    for (byte = range.from; byte < range.to; byte++) {
      if (!find_byte_in_bytes(byte)) {
        PRINT_SPACER();
        PRINT_ALLOWED_BYTE(byte);
      }
    }

    byte = range.to;

    if (!find_byte_in_bytes(byte)) {
      PRINT_SPACER();
      PRINT_ALLOWED_BYTE(byte);
    }
  }
}

void print_allowed_bytes()
{
  if (HOG_ALPHABET_MODE == HOG_ALPHABET_INCLUDING_BYTES_INTO_RANGES) {
    print_alphabet_including_bytes_into_ranges();
  }
  else {
    print_alphabet_excluding_bytes_from_ranges();
  }

  PRINT_GLUE();
}
