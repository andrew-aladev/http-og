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

#define UNDEFINED_SYMBOL UINT8_MAX

uint8_t symbol_by_bytes[ALPHABET_MAX_LENGTH] = {
  [0 ... UINT8_MAX] = UNDEFINED_SYMBOL};

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

static inline void print_alphabet()
{
  init_alphabet();
}

int main()
{
  print_constants();
  PRINT(GLUE);

  // print_alphabet();
  // PRINT(GLUE);

  PRINT("8");

  return 0;
}
