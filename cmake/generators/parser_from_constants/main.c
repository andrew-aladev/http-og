#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "constants.h"

#define GLUE ";"

#define PRINT(string) fputs(string, stdout)
#define PRINT_ERROR(string) fputs(string, stderr)

// -- constants --

#define CONSTANTS OGHTTP_CONSTANTS
#define CONSTANTS_LENGTH sizeof(CONSTANTS) / sizeof(CONSTANTS[0])
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

    printf(CONSTANT_TEMPLATE, CONSTANTS[index]);
  }
}

// -- alphabet --

#define ALPHABET_MAX_LENGTH UINT8_MAX + 1

uint8_t alphabet[ALPHABET_MAX_LENGTH];

#define SYMBOL_BY_BYTES_LENGTH ALPHABET_MAX_LENGTH
#define UNDEFINED_SYMBOL SYMBOL_BY_BYTES_LENGTH - 1

uint8_t symbol_by_bytes[SYMBOL_BY_BYTES_LENGTH] = {
  [0 ... SYMBOL_BY_BYTES_LENGTH - 1] = UNDEFINED_SYMBOL};

static inline bool has_symbol_for_byte(const uint8_t byte)
{
  return symbol_by_bytes[byte] != UNDEFINED_SYMBOL;
}

static inline void add_symbol(size_t* alphabet_length_ptr, const uint8_t byte)
{
  const uint8_t symbol = *alphabet_length_ptr;
  (*alphabet_length_ptr)++;

  alphabet[symbol]      = byte;
  symbol_by_bytes[byte] = symbol;
}

static inline bool is_alphabet_full(const size_t alphabet_length)
{
  return alphabet_length == ALPHABET_MAX_LENGTH;
}

static inline void init_alphabet(size_t* alphabet_length_ptr)
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

static inline void print_alphabet(const size_t alphabet_length)
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

static inline void print_symbol_by_bytes(const size_t alphabet_length)
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

// -- prefixes --

typedef struct {
  const char* constant;
  size_t      length;
} prefix_t;

static inline bool has_prefix(const prefix_t* prefixes, const size_t prefixes_length, const char* constant, const size_t prefix_length)
{
  for (size_t index = 0; index < prefixes_length; index++) {
    const prefix_t* prefix = &prefixes[index];

    if (prefix->length == prefix_length && strncmp(prefix->constant, constant, prefix_length) == 0) {
      return true;
    }
  }

  return false;
}

static inline void add_prefix(prefix_t* prefixes, size_t* prefixes_length_ptr, const char* constant, const size_t prefix_length)
{
  prefix_t* prefix = &prefixes[*prefixes_length_ptr];
  (*prefixes_length_ptr)++;

  prefix->constant = constant;
  prefix->length   = prefix_length;
}

static inline int init_prefixes(size_t* prefixes_length_ptr)
{
  // We can limit max possible prefixes length.
  size_t max_prefixes_length = 0;

  for (size_t index = 0; index < CONSTANTS_LENGTH; index++) {
    max_prefixes_length += strlen(CONSTANTS[index]) - 1;
  }

  prefix_t* prefixes = malloc(max_prefixes_length * sizeof(prefix_t));
  if (prefixes == NULL) {
    PRINT_ERROR("failed to allocate memory for prefixes\n");
    return 1;
  }

  *prefixes_length_ptr = 0;

  for (size_t index = 0; index < CONSTANTS_LENGTH; index++) {
    const char* constant = CONSTANTS[index];

    for (size_t prefix_length = 1; prefix_length < strlen(constant); prefix_length++) {
      if (!has_prefix(prefixes, *prefixes_length_ptr, constant, prefix_length)) {
        add_prefix(prefixes, prefixes_length_ptr, constant, prefix_length);
      }
    }
  }

  free(prefixes);

  return 0;
}

// -- next state by last symbols --

int main()
{
  // -- constants --

  print_constants();
  PRINT(GLUE);

  // -- alphabet --

  size_t alphabet_length;
  init_alphabet(&alphabet_length);

  print_alphabet(alphabet_length);
  PRINT(GLUE);

  print_symbol_by_bytes(alphabet_length);
  PRINT(GLUE);

  // -- prefixes --

  size_t prefixes_length;
  if (init_prefixes(&prefixes_length) != 0) {
    return 1;
  }

  // -- next state by last symbols --

  // -- min state bits --

  PRINT("8");

  return 0;
}
