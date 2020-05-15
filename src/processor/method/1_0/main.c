// Old generation HTTP (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

// This file was generated, do not edit manually.

// It may not be possible to run generator while cross compiling.
// So generated file should be distributed with its template.

#include "main.h"

const ogh_processor_state_fast_t OGH_PROCESSOR_METHOD_1_0_CONSTANTS_LENGTH = 3;

const ogh_processor_state_fast_t OGH_PROCESSOR_METHOD_1_0_INITIAL_STATE = OGH_PROCESSOR_METHOD_1_0_CONSTANTS_LENGTH;

const uint_fast16_t OGH_PROCESSOR_METHOD_1_0_ALPHABET_LENGTH     = 9;
const uint_fast16_t OGH_PROCESSOR_METHOD_1_0_ALPHABET_MAX_LENGTH = OGH_MAX_SYMBOL + 1;

const ogh_symbol_fast_t OGH_PROCESSOR_METHOD_1_0_UNDEFINED_SYMBOL = OGH_MAX_SYMBOL;

#define SYMBOL_BY_BYTES_LENGTH OGH_PROCESSOR_METHOD_1_0_ALPHABET_MAX_LENGTH

// clang-format off

const ogh_symbol_t OGH_PROCESSOR_METHOD_1_0_SYMBOL_BY_BYTES[SYMBOL_BY_BYTES_LENGTH] = {
  [0 ... SYMBOL_BY_BYTES_LENGTH - 1] = OGH_PROCESSOR_METHOD_1_0_UNDEFINED_SYMBOL,
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

#define NEXT_STATE_BY_LAST_SYMBOLS_LENGTH (11 + 1) * OGH_PROCESSOR_METHOD_1_0_ALPHABET_LENGTH

// clang-format off

const ogh_processor_method_1_0_state_t OGH_PROCESSOR_METHOD_1_0_NEXT_STATE_BY_LAST_SYMBOLS[NEXT_STATE_BY_LAST_SYMBOLS_LENGTH] = {
  [0 ... NEXT_STATE_BY_LAST_SYMBOLS_LENGTH - 1] = OGH_PROCESSOR_METHOD_1_0_INITIAL_STATE,
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

extern inline ogh_processor_state_fast_t ogh_processor_method_1_0_get_next_state(
  ogh_processor_state_fast_t state, ogh_symbol_fast_t byte);

extern inline bool ogh_processor_method_1_0_is_valid(ogh_processor_state_fast_t state);
