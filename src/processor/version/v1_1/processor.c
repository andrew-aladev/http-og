// HTTP old generation (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

// This file was generated, do not edit manually.

// It may not be possible to run generator while cross compiling.
// So generated file should be shipped with its template.

#include "processor.h"

const char* HOG_PROCESSOR_VERSION_v1_1_CONSTANTS = {
  "HTTP/1.0",
  "HTTP/1.1"};

const size_t HOG_PROCESSOR_VERSION_v1_1_CONSTANTS_LENGTH = sizeof(HOG_PROCESSOR_VERSION_v1_1_CONSTANTS) / sizeof(HOG_PROCESSOR_VERSION_v1_1_CONSTANTS[0]);

const hog_processor_state_fast_t HOG_PROCESSOR_VERSION_v1_1_INITIAL_STATE = HOG_PROCESSOR_VERSION_v1_1_CONSTANTS_LENGTH;

const size_t HOG_PROCESSOR_VERSION_v1_1_ALPHABET_LENGTH     = 7;
const size_t HOG_PROCESSOR_VERSION_v1_1_ALPHABET_MAX_LENGTH = HOG_MAX_SYMBOL + 1;

const hog_symbol_fast_t HOG_PROCESSOR_VERSION_v1_1_UNDEFINED_SYMBOL = HOG_MAX_SYMBOL;

#define SYMBOL_BY_BYTES_LENGTH HOG_MAX_SYMBOL + 1

// clang-format off

const hog_symbol_t HOG_PROCESSOR_VERSION_v1_1_SYMBOL_BY_BYTES[SYMBOL_BY_BYTES_LENGTH] = {
  [0 ... SYMBOL_BY_BYTES_LENGTH - 1] = HOG_PROCESSOR_VERSION_v1_1_UNDEFINED_SYMBOL,
  [72] = 0,
  [84] = 1,
  [80] = 2,
  [47] = 3,
  [49] = 4,
  [46] = 5,
  [48] = 6};

// clang-format on

#define NEXT_STATE_BY_LAST_SYMBOLS_LENGTH (9 + 1) * HOG_PROCESSOR_VERSION_v1_1_ALPHABET_LENGTH

// clang-format off

const hog_processor_version_v1_1_state_t HOG_PROCESSOR_VERSION_v1_1_NEXT_STATE_BY_LAST_SYMBOLS[NEXT_STATE_BY_LAST_SYMBOLS_LENGTH] = {
  [0 ... NEXT_STATE_BY_LAST_SYMBOLS_LENGTH - 1] = HOG_PROCESSOR_VERSION_v1_1_INITIAL_STATE,
  [14] = 3,
  [22] = 4,
  [29] = 5,
  [37] = 6,
  [45] = 7,
  [53] = 8,
  [61] = 9,
  [67] = 1,
  [69] = 0};

// clang-format on

extern inline hog_processor_state_fast_t hog_processor_version_v1_1_get_next_state(
  hog_processor_state_fast_t state, hog_symbol_fast_t byte);

extern inline bool hog_processor_version_v1_1_is_finished(hog_processor_state_fast_t state);

extern inline const char* hog_processor_version_v1_1_get_data(hog_processor_state_fast_t state);
