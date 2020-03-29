// HTTP old generation (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

// This file was generated, do not edit manually.

// It may not be possible to run generator while cross compiling.
// So generated file should be shipped with its template.

#if !defined(HOG_METHOD_v0_9_PARSER_H)
#define HOG_METHOD_v0_9_PARSER_H

#include <stdbool.h>
#include <stdlib.h>

#include "../../common.h"

// clang-format off

typedef uint_fast8_t hog_method_v0_9_parser_state_fast_t;

// -- constant --

extern const char*  HOG_METHOD_v0_9_PARSER_CONSTANT;
extern const size_t HOG_METHOD_v0_9_PARSER_CONSTANT_LENGTH;
extern const hog_method_v0_9_parser_state_fast_t HOG_METHOD_v0_9_PARSER_INITIAL_STATE;

// clang-format on

inline hog_method_v0_9_parser_state_fast_t hog_method_v0_9_get_next_state(
  hog_method_v0_9_parser_state_fast_t state, hog_symbol_fast_t byte)
{
  if (HOG_METHOD_v0_9_PARSER_CONSTANT[state] != byte) {
    return HOG_METHOD_v0_9_PARSER_INITIAL_STATE;
  }

  return state + 1;
}

inline bool hog_method_v0_9_is_finished(hog_method_v0_9_parser_state_fast_t state)
{
  return state == HOG_METHOD_v0_9_PARSER_CONSTANT_LENGTH;
}

#endif // HOG_METHOD_v0_9_PARSER_H
