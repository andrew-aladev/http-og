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

static inline void print_alphabet(size_t alphabet_length)
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

static inline void print_symbol_by_bytes(size_t alphabet_length)
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

// We need to check whether prefix doesn't equal to any constant.
static inline bool is_prefix(const char* constant, size_t prefix_length)
{
  for (size_t index = 0; index < CONSTANTS_LENGTH; index++) {
    const char* target_constant = CONSTANTS[index];

    if (strlen(target_constant) == prefix_length && strncmp(target_constant, constant, prefix_length) == 0) {
      return false;
    }
  }

  return true;
}

static inline bool has_prefix(const prefix_t* prefixes, size_t prefixes_length, const char* constant, size_t prefix_length)
{
  for (size_t index = 0; index < prefixes_length; index++) {
    const prefix_t* prefix = &prefixes[index];

    if (prefix->length == prefix_length && strncmp(prefix->constant, constant, prefix_length) == 0) {
      return true;
    }
  }

  return false;
}

static inline void add_prefix(prefix_t* prefixes, size_t* prefixes_length_ptr, const char* constant, size_t prefix_length)
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
      if (!is_prefix(constant, prefix_length)) {
        continue;
      }

      if (!has_prefix(prefixes, *prefixes_length_ptr, constant, prefix_length)) {
        add_prefix(prefixes, prefixes_length_ptr, constant, prefix_length);
      }
    }
  }

  free(prefixes);

  return 0;
}

// -- max state --

#define MAX_STATE_TEMPLATE "%zu"

static inline int print_max_state(size_t* max_state_ptr)
{
  size_t prefixes_length;

  int result = init_prefixes(&prefixes_length);
  if (result != 0) {
    return 1;
  }

  // Max state will be equal to constants + empty string (1) + prefixes - 1.
  *max_state_ptr = CONSTANTS_LENGTH + prefixes_length;
  printf(MAX_STATE_TEMPLATE, *max_state_ptr);

  return 0;
}

// -- min state bits --

static inline int print_min_state_bits(size_t max_state)
{
  char* min_state_bits;

  if (max_state <= UINT8_MAX) {
    min_state_bits = "8";
  }
  else if (max_state <= UINT16_MAX) {
    min_state_bits = "16";
  }
  else if (max_state <= UINT32_MAX) {
    min_state_bits = "32";
  }
  else {
    PRINT_ERROR("max state is too big\n");
    return 1;
  }

  PRINT(min_state_bits);

  return 0;
}

// -- next state by last symbols --

#define INITIAL_STATE CONSTANTS_LENGTH

#define NEXT_STATE_BY_LAST_SYMBOLS_PREFIX "    "
#define NEXT_STATE_BY_LAST_SYMBOLS_TEMPLATE "[%zu] = %zu"
#define NEXT_STATE_BY_LAST_SYMBOLS_TERMINATOR ",\n"

// We need to check whether current prefix matches constant.
static inline bool find_state_from_constants(size_t* state_ptr, const char* constant, size_t prefix_length)
{
  for (size_t index = 0; index < CONSTANTS_LENGTH; index++) {
    const char* target_constant = CONSTANTS[index];

    if (prefix_length == strlen(target_constant) && strncmp(constant, target_constant, prefix_length) == 0) {
      *state_ptr = index;
      return true;
    }
  }

  return false;
}

static inline int print_next_state_by_last_symbols(size_t alphabet_length, size_t max_state)
{
  // Each state has alphabet length of possible last symbols.
  size_t next_state_by_last_symbols_length = (max_state + 1) * alphabet_length;

  size_t* next_state_by_last_symbols = malloc(next_state_by_last_symbols_length * sizeof(size_t));
  if (next_state_by_last_symbols == NULL) {
    PRINT_ERROR("failed to allocate memory for next state by last symbols\n");
    return 1;
  }

  size_t index;

  // Initialize all next states with initial state.
  for (index = 0; index < next_state_by_last_symbols_length; index++) {
    next_state_by_last_symbols[index] = INITIAL_STATE;
  }

  size_t global_state = INITIAL_STATE;

  for (index = 0; index < CONSTANTS_LENGTH; index++) {
    // Starting with empty string and initial state.
    const char* constant = CONSTANTS[index];
    size_t      state    = INITIAL_STATE;

    for (size_t jndex = 0; jndex < strlen(constant); jndex++) {
      uint8_t last_symbol       = symbol_by_bytes[constant[jndex]];
      size_t  last_symbol_index = state * alphabet_length + last_symbol;
      size_t  last_symbol_state = next_state_by_last_symbols[last_symbol_index];

      if (last_symbol_state != INITIAL_STATE) {
        state = last_symbol_state;
        continue;
      }

      if (!find_state_from_constants(&state, constant, jndex + 1)) {
        if (global_state >= max_state) {
          PRINT_ERROR("global state should be less than max state\n");
          free(next_state_by_last_symbols);
          return 2;
        }

        state = ++global_state;
      }

      next_state_by_last_symbols[last_symbol_index] = state;
    }
  }

  if (global_state != max_state) {
    PRINT_ERROR("global state is not equal to max state\n");
    free(next_state_by_last_symbols);
    return 3;
  }

  bool first_state_printed = false;

  for (index = 0; index < next_state_by_last_symbols_length; index++) {
    size_t next_state = next_state_by_last_symbols[index];
    if (next_state == INITIAL_STATE) {
      continue;
    }

    if (first_state_printed) {
      PRINT(NEXT_STATE_BY_LAST_SYMBOLS_TERMINATOR);
      PRINT(NEXT_STATE_BY_LAST_SYMBOLS_PREFIX);
    }
    else {
      PRINT(NEXT_STATE_BY_LAST_SYMBOLS_PREFIX);
      first_state_printed = true;
    }

    printf(NEXT_STATE_BY_LAST_SYMBOLS_TEMPLATE, index, next_state);
  }

  free(next_state_by_last_symbols);

  return 0;
}

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

  // -- max state --

  size_t max_state;

  int result = print_max_state(&max_state);
  if (result != 0) {
    return 1;
  }

  PRINT(GLUE);

  // -- min state bits --

  result = print_min_state_bits(max_state);
  if (result != 0) {
    return 2;
  }

  PRINT(GLUE);

  // -- next state by last symbols --

  result = print_next_state_by_last_symbols(alphabet_length, max_state);
  if (result != 0) {
    return 3;
  }

  return 0;
}
