// HTTP old generation (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

// This file was generated, do not edit manually.

// It may not be possible to run generator while cross compiling.
// So generated file should be shipped with its template.

#if !defined(HOG_METHOD_v1_0_PARSER_H)
#define HOG_METHOD_v1_0_PARSER_H

#include <stdbool.h>
#include <stdlib.h>

#include "../../common.h"

// clang-format off

typedef uint8_t      hog_method_v1_0_parser_state_t;
typedef uint_fast8_t hog_method_v1_0_parser_state_fast_t;

// -- constants --

extern const char*  HOG_METHOD_v1_0_PARSER_CONSTANTS[];
extern const size_t HOG_METHOD_v1_0_PARSER_CONSTANTS_LENGTH;
extern const hog_method_v1_0_parser_state_fast_t HOG_METHOD_v1_0_PARSER_INITIAL_STATE;

// -- alphabet --

extern const hog_symbol_t HOG_METHOD_v1_0_PARSER_ALPHABET[];
extern const size_t       HOG_METHOD_v1_0_PARSER_ALPHABET_LENGTH;
extern const size_t       HOG_METHOD_v1_0_PARSER_ALPHABET_MAX_LENGTH;

extern const hog_symbol_fast_t HOG_METHOD_v1_0_PARSER_UNDEFINED_SYMBOL;
extern const size_t            HOG_METHOD_v1_0_PARSER_SYMBOL_BY_BYTES_LENGTH;
extern const hog_symbol_t      HOG_METHOD_v1_0_PARSER_SYMBOL_BY_BYTES[];

// -- next state by last symbols --

extern const size_t HOG_METHOD_v1_0_NEXT_STATE_BY_LAST_SYMBOLS_LENGTH;
extern const hog_method_v1_0_parser_state_t HOG_METHOD_v1_0_NEXT_STATE_BY_LAST_SYMBOLS[];

// clang-format on

inline hog_method_v1_0_parser_state_fast_t hog_method_v1_0_get_next_state(
  hog_method_v1_0_parser_state_fast_t state, hog_symbol_fast_t byte)
{
  hog_symbol_fast_t symbol = HOG_METHOD_v1_0_PARSER_SYMBOL_BY_BYTES[byte];
  if (HOG_METHOD_v1_0_PARSER_ALPHABET_LENGTH != HOG_METHOD_v1_0_PARSER_ALPHABET_MAX_LENGTH && symbol == HOG_METHOD_v1_0_PARSER_UNDEFINED_SYMBOL) {
    return HOG_METHOD_v1_0_PARSER_INITIAL_STATE;
  }

  return HOG_METHOD_v1_0_NEXT_STATE_BY_LAST_SYMBOLS[state * HOG_METHOD_v1_0_PARSER_ALPHABET_LENGTH + symbol];
}

inline bool hog_method_v1_0_is_finished(hog_method_v1_0_parser_state_fast_t state)
{
  return state < HOG_METHOD_v1_0_PARSER_CONSTANTS_LENGTH;
}

#endif // HOG_METHOD_v1_0_PARSER_H
