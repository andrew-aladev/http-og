// HTTP old generation (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

// This file was generated, do not edit manually.

// It may not be possible to run generator while cross compiling.
// So generated file should be shipped with its template.

#include "main.h"

const size_t HOG_PROCESSOR_STATUS_CODE_1_1_CONSTANTS_LENGTH = 43;

const hog_processor_state_fast_t HOG_PROCESSOR_STATUS_CODE_1_1_INITIAL_STATE = HOG_PROCESSOR_STATUS_CODE_1_1_CONSTANTS_LENGTH;

const size_t HOG_PROCESSOR_STATUS_CODE_1_1_ALPHABET_LENGTH     = 10;
const size_t HOG_PROCESSOR_STATUS_CODE_1_1_ALPHABET_MAX_LENGTH = HOG_MAX_SYMBOL + 1;

const hog_symbol_fast_t HOG_PROCESSOR_STATUS_CODE_1_1_UNDEFINED_SYMBOL = HOG_MAX_SYMBOL;

#define SYMBOL_BY_BYTES_LENGTH HOG_MAX_SYMBOL + 1

// clang-format off

const hog_symbol_t HOG_PROCESSOR_STATUS_CODE_1_1_SYMBOL_BY_BYTES[SYMBOL_BY_BYTES_LENGTH] = {
  [0 ... SYMBOL_BY_BYTES_LENGTH - 1] = HOG_PROCESSOR_STATUS_CODE_1_1_UNDEFINED_SYMBOL,
  [49] = 0,
  [48] = 1,
  [50] = 2,
  [51] = 3,
  [52] = 4,
  [53] = 5,
  [54] = 6,
  [55] = 7,
  [56] = 8,
  [57] = 9};

// clang-format on

#define NEXT_STATE_BY_LAST_SYMBOLS_LENGTH (55 + 1) * HOG_PROCESSOR_STATUS_CODE_1_1_ALPHABET_LENGTH

// clang-format off

const hog_processor_status_code_1_1_state_t HOG_PROCESSOR_STATUS_CODE_1_1_NEXT_STATE_BY_LAST_SYMBOLS[NEXT_STATE_BY_LAST_SYMBOLS_LENGTH] = {
  [0 ... NEXT_STATE_BY_LAST_SYMBOLS_LENGTH - 1] = HOG_PROCESSOR_STATUS_CODE_1_1_INITIAL_STATE,
  [430] = 44,
  [432] = 46,
  [433] = 48,
  [434] = 50,
  [435] = 54,
  [441] = 45,
  [450] = 1,
  [451] = 0,
  [461] = 47,
  [470] = 3,
  [471] = 2,
  [472] = 4,
  [473] = 5,
  [474] = 6,
  [475] = 7,
  [476] = 8,
  [481] = 49,
  [490] = 10,
  [491] = 9,
  [492] = 11,
  [493] = 12,
  [494] = 13,
  [495] = 14,
  [496] = 15,
  [497] = 16,
  [498] = 17,
  [500] = 52,
  [501] = 51,
  [502] = 53,
  [510] = 19,
  [511] = 18,
  [512] = 20,
  [513] = 21,
  [514] = 22,
  [515] = 23,
  [516] = 24,
  [517] = 25,
  [518] = 26,
  [519] = 27,
  [520] = 29,
  [521] = 28,
  [522] = 30,
  [523] = 31,
  [524] = 32,
  [525] = 33,
  [526] = 34,
  [527] = 35,
  [536] = 36,
  [541] = 55,
  [550] = 38,
  [551] = 37,
  [552] = 39,
  [553] = 40,
  [554] = 41,
  [555] = 42};

// clang-format on

extern inline hog_processor_state_fast_t hog_processor_status_code_1_1_get_next_state(
  hog_processor_state_fast_t state, hog_symbol_fast_t byte);

extern inline bool hog_processor_status_code_1_1_is_finished(hog_processor_state_fast_t state);
