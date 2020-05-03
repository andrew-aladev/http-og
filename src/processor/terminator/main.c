// HTTP old generation (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

// This file was generated, do not edit manually.

// It may not be possible to run generator while cross compiling.
// So generated file should be shipped with its template.

#include "main.h"

const hog_processor_state_fast_t HOG_PROCESSOR_TERMINATOR_CONSTANTS_LENGTH = 2;

const hog_processor_state_fast_t HOG_PROCESSOR_TERMINATOR_INITIAL_STATE = HOG_PROCESSOR_TERMINATOR_CONSTANTS_LENGTH;

const uint_fast16_t HOG_PROCESSOR_TERMINATOR_ALPHABET_LENGTH     = 2;
const uint_fast16_t HOG_PROCESSOR_TERMINATOR_ALPHABET_MAX_LENGTH = HOG_MAX_SYMBOL + 1;

const hog_symbol_fast_t HOG_PROCESSOR_TERMINATOR_UNDEFINED_SYMBOL = HOG_MAX_SYMBOL;

#define SYMBOL_BY_BYTES_LENGTH HOG_PROCESSOR_TERMINATOR_ALPHABET_MAX_LENGTH

// clang-format off

const hog_symbol_t HOG_PROCESSOR_TERMINATOR_SYMBOL_BY_BYTES[SYMBOL_BY_BYTES_LENGTH] = {
  [0 ... SYMBOL_BY_BYTES_LENGTH - 1] = HOG_PROCESSOR_TERMINATOR_UNDEFINED_SYMBOL,
  [10] = 0,
  [13] = 1};

// clang-format on

#define NEXT_STATE_BY_LAST_SYMBOLS_LENGTH (3 + 1) * HOG_PROCESSOR_TERMINATOR_ALPHABET_LENGTH

// clang-format off

const hog_processor_terminator_state_t HOG_PROCESSOR_TERMINATOR_NEXT_STATE_BY_LAST_SYMBOLS[NEXT_STATE_BY_LAST_SYMBOLS_LENGTH] = {
  [0 ... NEXT_STATE_BY_LAST_SYMBOLS_LENGTH - 1] = HOG_PROCESSOR_TERMINATOR_INITIAL_STATE,
  [4] = 0,
  [5] = 3,
  [6] = 1};

// clang-format on

extern inline hog_processor_state_fast_t hog_processor_terminator_get_next_state(
  hog_processor_state_fast_t state, hog_symbol_fast_t byte);

extern inline bool hog_processor_terminator_is_valid(hog_processor_state_fast_t state);
