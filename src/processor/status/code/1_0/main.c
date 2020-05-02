// HTTP old generation (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

// This file was generated, do not edit manually.

// It may not be possible to run generator while cross compiling.
// So generated file should be shipped with its template.

#include "main.h"

const size_t HOG_PROCESSOR_STATUS_CODE_1_0_CONSTANTS_LENGTH = 15;

const hog_processor_state_fast_t HOG_PROCESSOR_STATUS_CODE_1_0_INITIAL_STATE = HOG_PROCESSOR_STATUS_CODE_1_0_CONSTANTS_LENGTH;

const size_t HOG_PROCESSOR_STATUS_CODE_1_0_ALPHABET_LENGTH     = 6;
const size_t HOG_PROCESSOR_STATUS_CODE_1_0_ALPHABET_MAX_LENGTH = HOG_MAX_SYMBOL + 1;

const hog_symbol_fast_t HOG_PROCESSOR_STATUS_CODE_1_0_UNDEFINED_SYMBOL = HOG_MAX_SYMBOL;

#define SYMBOL_BY_BYTES_LENGTH HOG_PROCESSOR_STATUS_CODE_1_0_ALPHABET_MAX_LENGTH

// clang-format off

const hog_symbol_t HOG_PROCESSOR_STATUS_CODE_1_0_SYMBOL_BY_BYTES[SYMBOL_BY_BYTES_LENGTH] = {
  [0 ... SYMBOL_BY_BYTES_LENGTH - 1] = HOG_PROCESSOR_STATUS_CODE_1_0_UNDEFINED_SYMBOL,
  [50] = 0,
  [48] = 1,
  [49] = 2,
  [52] = 3,
  [51] = 4,
  [53] = 5};

// clang-format on

#define NEXT_STATE_BY_LAST_SYMBOLS_LENGTH (26 + 1) * HOG_PROCESSOR_STATUS_CODE_1_0_ALPHABET_LENGTH

// clang-format off

const hog_processor_status_code_1_0_state_t HOG_PROCESSOR_STATUS_CODE_1_0_NEXT_STATE_BY_LAST_SYMBOLS[NEXT_STATE_BY_LAST_SYMBOLS_LENGTH] = {
  [0 ... NEXT_STATE_BY_LAST_SYMBOLS_LENGTH - 1] = HOG_PROCESSOR_STATUS_CODE_1_0_INITIAL_STATE,
  [90] = 16,
  [93] = 23,
  [94] = 21,
  [95] = 25,
  [97] = 17,
  [103] = 0,
  [104] = 18,
  [105] = 2,
  [108] = 19,
  [115] = 20,
  [120] = 1,
  [127] = 22,
  [132] = 5,
  [133] = 3,
  [134] = 4,
  [135] = 6,
  [139] = 24,
  [145] = 7,
  [146] = 8,
  [147] = 10,
  [148] = 9,
  [151] = 26,
  [156] = 13,
  [157] = 11,
  [158] = 12,
  [160] = 14};

// clang-format on

extern inline hog_processor_state_fast_t hog_processor_status_code_1_0_get_next_state(
  hog_processor_state_fast_t state, hog_symbol_fast_t byte);

extern inline bool hog_processor_status_code_1_0_is_valid(hog_processor_state_fast_t state);
