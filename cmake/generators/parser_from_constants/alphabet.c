// Old generation HTTP (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

#include "alphabet.h"

#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#include "common.h"

#define ALPHABET_MAX_LENGTH UINT8_MAX + 1

uint8_t alphabet[ALPHABET_MAX_LENGTH];

#define SYMBOL_BY_BYTES_LENGTH ALPHABET_MAX_LENGTH
#define UNDEFINED_SYMBOL SYMBOL_BY_BYTES_LENGTH - 1

uint8_t symbol_by_bytes[SYMBOL_BY_BYTES_LENGTH] = {
  [0 ... SYMBOL_BY_BYTES_LENGTH - 1] = UNDEFINED_SYMBOL};

static inline bool has_symbol_for_byte(uint8_t byte)
{
  return symbol_by_bytes[byte] != UNDEFINED_SYMBOL;
}

static inline void add_symbol(size_t* alphabet_length_ptr, uint8_t byte)
{
  uint8_t symbol = *alphabet_length_ptr;
  (*alphabet_length_ptr)++;

  alphabet[symbol]      = byte;
  symbol_by_bytes[byte] = symbol;
}

static inline bool is_alphabet_full(size_t alphabet_length)
{
  return alphabet_length == ALPHABET_MAX_LENGTH;
}

void init_alphabet(size_t* alphabet_length_ptr)
{
  *alphabet_length_ptr = 0;

  for (size_t index = 0; index < CONSTANTS_LENGTH; index++) {
    const char* constant = CONSTANTS[index];

    for (size_t jndex = 0; jndex < strlen(constant); jndex++) {
      uint8_t byte = constant[jndex];

      if (!has_symbol_for_byte(byte)) {
        add_symbol(alphabet_length_ptr, byte);

        if (is_alphabet_full(*alphabet_length_ptr)) {
          // We don't need other constants, alphabet is already full.
          return;
        }
      }
    }
  }
}

#define ALPHABET_PREFIX "    "
#define ALPHABET_TEMPLATE "%u"
#define ALPHABET_TERMINATOR ",\n"

void print_alphabet(size_t alphabet_length)
{
  for (size_t index = 0; index < alphabet_length; index++) {
    if (index == 0) {
      PRINT(ALPHABET_PREFIX);
    }
    else {
      PRINT(ALPHABET_TERMINATOR);
      PRINT(ALPHABET_PREFIX);
    }

    printf(ALPHABET_TEMPLATE, alphabet[index]);
  }

  PRINT_GLUE();
}

#define SYMBOL_BY_BYTE_PREFIX "    "
#define SYMBOL_BY_BYTE_TEMPLATE "[%u] = %u"
#define SYMBOL_BY_BYTE_TERMINATOR ",\n"

void print_symbol_by_bytes(size_t alphabet_length)
{
  for (size_t index = 0; index < alphabet_length; index++) {
    if (index == 0) {
      PRINT(SYMBOL_BY_BYTE_PREFIX);
    }
    else {
      PRINT(SYMBOL_BY_BYTE_TERMINATOR);
      PRINT(SYMBOL_BY_BYTE_PREFIX);
    }

    uint8_t byte = alphabet[index];
    printf(SYMBOL_BY_BYTE_TEMPLATE, byte, symbol_by_bytes[byte]);
  }

  PRINT_GLUE();
}
