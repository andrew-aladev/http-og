// HTTP old generation (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

// This file was generated, do not edit manually.

// It may not be possible to run generator while cross compiling.
// So generated file should be shipped with its template.

#include "main.h"

const size_t HOG_PROCESSOR_STATUS_CODE_1_1_CONSTANTS_LENGTH = 0;

const hog_processor_state_fast_t HOG_PROCESSOR_STATUS_CODE_1_1_INITIAL_STATE = HOG_PROCESSOR_STATUS_CODE_1_1_CONSTANTS_LENGTH;

const size_t HOG_PROCESSOR_STATUS_CODE_1_1_ALPHABET_LENGTH     = 0;
const size_t HOG_PROCESSOR_STATUS_CODE_1_1_ALPHABET_MAX_LENGTH = HOG_MAX_SYMBOL + 1;

const hog_symbol_fast_t HOG_PROCESSOR_STATUS_CODE_1_1_UNDEFINED_SYMBOL = HOG_MAX_SYMBOL;

#define SYMBOL_BY_BYTES_LENGTH HOG_MAX_SYMBOL + 1

// clang-format off

const hog_symbol_t HOG_PROCESSOR_STATUS_CODE_1_1_SYMBOL_BY_BYTES[SYMBOL_BY_BYTES_LENGTH] = {
  [0 ... SYMBOL_BY_BYTES_LENGTH - 1] = HOG_PROCESSOR_STATUS_CODE_1_1_UNDEFINED_SYMBOL,
};

// clang-format on

#define NEXT_STATE_BY_LAST_SYMBOLS_LENGTH (0 + 1) * HOG_PROCESSOR_STATUS_CODE_1_1_ALPHABET_LENGTH

// clang-format off

const hog_processor_status_code_1_1_state_t HOG_PROCESSOR_STATUS_CODE_1_1_NEXT_STATE_BY_LAST_SYMBOLS[NEXT_STATE_BY_LAST_SYMBOLS_LENGTH] = {
  [0 ... NEXT_STATE_BY_LAST_SYMBOLS_LENGTH - 1] = HOG_PROCESSOR_STATUS_CODE_1_1_INITIAL_STATE,
};

// clang-format on

extern inline hog_processor_state_fast_t hog_processor_status_code_1_1_get_next_state(
  hog_processor_state_fast_t state, hog_symbol_fast_t byte);

extern inline bool hog_processor_status_code_1_1_is_finished(hog_processor_state_fast_t state);
