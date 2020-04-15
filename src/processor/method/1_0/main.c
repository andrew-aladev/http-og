// HTTP old generation (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

// This file was generated, do not edit manually.

// It may not be possible to run generator while cross compiling.
// So generated file should be shipped with its template.

#include "main.h"

const size_t HOG_PROCESSOR_METHOD_1_0_CONSTANTS_LENGTH = 3;

const hog_processor_state_fast_t HOG_PROCESSOR_METHOD_1_0_INITIAL_STATE = HOG_PROCESSOR_METHOD_1_0_CONSTANTS_LENGTH;

const size_t HOG_PROCESSOR_METHOD_1_0_ALPHABET_LENGTH     = 9;
const size_t HOG_PROCESSOR_METHOD_1_0_ALPHABET_MAX_LENGTH = HOG_MAX_SYMBOL + 1;

const hog_symbol_fast_t HOG_PROCESSOR_METHOD_1_0_UNDEFINED_SYMBOL = HOG_MAX_SYMBOL;

#define SYMBOL_BY_BYTES_LENGTH HOG_MAX_SYMBOL + 1

// clang-format off

const hog_symbol_t HOG_PROCESSOR_METHOD_1_0_SYMBOL_BY_BYTES[SYMBOL_BY_BYTES_LENGTH] = {
  [0 ... SYMBOL_BY_BYTES_LENGTH - 1] = HOG_PROCESSOR_METHOD_1_0_UNDEFINED_SYMBOL,
  [71] = 0,
  [69] = 1,
  [84] = 2,
  [72] = 3,
  [65] = 4,
  [68] = 5,
  [80] = 6,
  [79] = 7,
  [83] = 8};

// clang-format on

#define NEXT_STATE_BY_LAST_SYMBOLS_LENGTH (11 + 1) * HOG_PROCESSOR_METHOD_1_0_ALPHABET_LENGTH

// clang-format off

const hog_processor_method_1_0_state_t HOG_PROCESSOR_METHOD_1_0_NEXT_STATE_BY_LAST_SYMBOLS[NEXT_STATE_BY_LAST_SYMBOLS_LENGTH] = {
  [0 ... NEXT_STATE_BY_LAST_SYMBOLS_LENGTH - 1] = HOG_PROCESSOR_METHOD_1_0_INITIAL_STATE,
  [27] = 4,
  [30] = 6,
  [33] = 9,
  [37] = 5,
  [47] = 0,
  [55] = 7,
  [67] = 8,
  [77] = 1,
  [88] = 10,
  [98] = 11,
  [101] = 2};

// clang-format on

extern inline hog_processor_state_fast_t hog_processor_method_1_0_get_next_state(
  hog_processor_state_fast_t state, hog_symbol_fast_t byte);

extern inline bool hog_processor_method_1_0_is_finished(hog_processor_state_fast_t state);
