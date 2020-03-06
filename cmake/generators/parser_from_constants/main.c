#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "constants.h"

#define GLUE ";"

#define PRINT(string) fputs(string, stdout)

// -- constants --

#define CONSTANTS_LENGTH sizeof(OGHTTP_CONSTANTS) / sizeof(OGHTTP_CONSTANTS[0])
#define CONSTANT_PREFIX "    "
#define CONSTANT_TEMPLATE "\"%s\""
#define CONSTANT_TERMINATOR ",\n"

static inline void print_constants()
{
  for (size_t index = 0; index < CONSTANTS_LENGTH; index++) {
    if (index == 0) {
      PRINT(CONSTANT_PREFIX);
    }
    else {
      PRINT(CONSTANT_TERMINATOR);
      PRINT(CONSTANT_PREFIX);
    }

    printf(CONSTANT_TEMPLATE, OGHTTP_CONSTANTS[index]);
  }
}

// -- alphabet --

#define ALPHABET_MAX_LENGTH UINT8_MAX + 1

uint8_t alphabet[ALPHABET_MAX_LENGTH];
size_t  alphabet_length = 0;

#define SYMBOL_BY_BYTES_LENGTH ALPHABET_MAX_LENGTH
#define UNDEFINED_SYMBOL SYMBOL_BY_BYTES_LENGTH - 1

uint8_t symbol_by_bytes[SYMBOL_BY_BYTES_LENGTH] = {
  [0 ... SYMBOL_BY_BYTES_LENGTH - 1] = UNDEFINED_SYMBOL};

static inline bool is_alphabet_full()
{
  return alphabet_length == ALPHABET_MAX_LENGTH;
}

static inline void init_alphabet()
{
  for (size_t index = 0; index < CONSTANTS_LENGTH; index++) {
    const char* constant = OGHTTP_CONSTANTS[index];

    for (size_t jndex = 0; jndex < strlen(constant); jndex++) {
      uint8_t byte = constant[jndex];

      uint8_t symbol = symbol_by_bytes[byte];
      if (symbol == UNDEFINED_SYMBOL) {
        symbol = alphabet_length;
        alphabet_length++;

        alphabet[symbol]      = byte;
        symbol_by_bytes[byte] = symbol;

        if (is_alphabet_full()) {
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

static inline void print_alphabet()
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
}

#define SYMBOL_BY_BYTE_PREFIX "    "
#define SYMBOL_BY_BYTE_TEMPLATE "[%u] = %u"
#define SYMBOL_BY_BYTE_TERMINATOR ",\n"

static inline void print_symbol_by_bytes()
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
}

int main()
{
  print_constants();
  PRINT(GLUE);

  init_alphabet();

  print_alphabet();
  PRINT(GLUE);

  print_symbol_by_bytes();
  PRINT(GLUE);

  PRINT("8");

  return 0;
}
