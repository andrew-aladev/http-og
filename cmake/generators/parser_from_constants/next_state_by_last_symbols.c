// Old generation HTTP (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

#include "next_state_by_last_symbols.h"

#include <stdbool.h>
#include <string.h>

#include "common.h"

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

#define INITIAL_STATE CONSTANTS_LENGTH

#define NEXT_STATE_BY_LAST_SYMBOLS_PREFIX "    "
#define NEXT_STATE_BY_LAST_SYMBOLS_TEMPLATE "[%zu] = %zu"
#define NEXT_STATE_BY_LAST_SYMBOLS_TERMINATOR ",\n"

int print_next_state_by_last_symbols(const uint8_t* alphabet_ptr, const uint8_t* symbol_by_bytes_ptr, size_t alphabet_length, size_t max_state)
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
