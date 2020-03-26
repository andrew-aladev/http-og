// Old generation HTTP (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

// This file was generated, do not edit manually.

// It may not be possible to run generator while cross compiling.
// So generated file should be shipped with its template.

#if !defined(OGHTTP_METHOD_v0_9_PARSER_H)
#define OGHTTP_METHOD_v0_9_PARSER_H

#include <stdbool.h>
#include <string.h>

#include "../../common.h"

// clang-format off

typedef uint_fast8_t oghttp_method_v0_9_parser_state_fast_t;

// -- constant --

extern const char* OGHTTP_METHOD_v0_9_PARSER_CONSTANT;
extern const oghttp_method_v0_9_parser_state_fast_t OGHTTP_METHOD_v0_9_PARSER_INITIAL_STATE;

// clang-format on

inline oghttp_method_v0_9_parser_state_fast_t oghttp_method_v0_9_get_next_state(
  oghttp_method_v0_9_parser_state_fast_t state, oghttp_symbol_fast_t byte)
{
  if (OGHTTP_METHOD_v0_9_PARSER_CONSTANT[state] != byte) {
    return OGHTTP_METHOD_v0_9_PARSER_INITIAL_STATE;
  }

  return state + 1;
}

inline bool oghttp_method_v0_9_is_finished(oghttp_method_v0_9_parser_state_fast_t state)
{
  return state == strlen(OGHTTP_METHOD_v0_9_PARSER_CONSTANT);
}

#endif // OGHTTP_METHOD_v0_9_PARSER_H
