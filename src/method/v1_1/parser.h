// Old generation HTTP (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

// This file was generated, do not edit manually.

// It may not be possible to run generator while cross compiling.
// So generated file should be shipped with its template.

#if !defined(OGHTTP_METHOD_v1_1_PARSER_H)
#define OGHTTP_METHOD_v1_1_PARSER_H

#include <stdbool.h>
#include <stdlib.h>

#include "../../common.h"

// clang-format off

typedef uint8_t      oghttp_method_v1_1_parser_state_t;
typedef uint_fast8_t oghttp_method_v1_1_parser_state_fast_t;

// -- constants --

extern const char*  OGHTTP_METHOD_v1_1_PARSER_CONSTANTS[];
extern const size_t OGHTTP_METHOD_v1_1_PARSER_CONSTANTS_LENGTH;
extern const oghttp_method_v1_1_parser_state_fast_t OGHTTP_METHOD_v1_1_PARSER_INITIAL_STATE;

// -- alphabet --

extern const oghttp_symbol_t OGHTTP_METHOD_v1_1_PARSER_ALPHABET[];
extern const size_t          OGHTTP_METHOD_v1_1_PARSER_ALPHABET_LENGTH;
extern const size_t          OGHTTP_METHOD_v1_1_PARSER_ALPHABET_MAX_LENGTH;

extern const oghttp_symbol_fast_t OGHTTP_METHOD_v1_1_PARSER_UNDEFINED_SYMBOL;
extern const size_t               OGHTTP_METHOD_v1_1_PARSER_SYMBOL_BY_BYTES_LENGTH;
extern const oghttp_symbol_t      OGHTTP_METHOD_v1_1_PARSER_SYMBOL_BY_BYTES[];

// -- next state by last symbols --

extern const size_t OGHTTP_METHOD_v1_1_NEXT_STATE_BY_LAST_SYMBOLS_LENGTH;
extern const oghttp_method_v1_1_parser_state_t OGHTTP_METHOD_v1_1_NEXT_STATE_BY_LAST_SYMBOLS[];

// clang-format on

inline oghttp_method_v1_1_parser_state_fast_t oghttp_method_v1_1_get_next_state(
  oghttp_method_v1_1_parser_state_fast_t state, oghttp_symbol_fast_t byte)
{
  oghttp_symbol_fast_t symbol = OGHTTP_METHOD_v1_1_PARSER_SYMBOL_BY_BYTES[byte];
  if (OGHTTP_METHOD_v1_1_PARSER_ALPHABET_LENGTH != OGHTTP_METHOD_v1_1_PARSER_ALPHABET_MAX_LENGTH && symbol == OGHTTP_METHOD_v1_1_PARSER_UNDEFINED_SYMBOL) {
    return OGHTTP_METHOD_v1_1_PARSER_INITIAL_STATE;
  }

  return OGHTTP_METHOD_v1_1_NEXT_STATE_BY_LAST_SYMBOLS[state * OGHTTP_METHOD_v1_1_PARSER_ALPHABET_LENGTH + symbol];
}

inline bool oghttp_method_v1_1_is_finished(oghttp_method_v1_1_parser_state_fast_t state)
{
  return state < OGHTTP_METHOD_v1_1_PARSER_CONSTANTS_LENGTH;
}

#endif // OGHTTP_METHOD_v1_1_PARSER_H
