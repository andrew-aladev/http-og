// Old generation HTTP (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

// This file was generated, do not edit manually.

// It may not be possible to run generator while cross compiling.
// So generated file should be shipped with its template.

#include "parser.h"

// clang-format off

// -- constant --

const char*  OGHTTP_METHOD_v0_9_PARSER_CONSTANT        = "GET";
const size_t OGHTTP_METHOD_v0_9_PARSER_CONSTANT_LENGTH = 3;

const oghttp_method_v0_9_parser_state_fast_t OGHTTP_METHOD_v0_9_PARSER_INITIAL_STATE = 0;

// clang-format on

extern inline oghttp_method_v0_9_parser_state_fast_t oghttp_method_v0_9_get_next_state(
  oghttp_method_v0_9_parser_state_fast_t state, oghttp_symbol_fast_t byte);

extern inline bool oghttp_method_v0_9_is_finished(oghttp_method_v0_9_parser_state_fast_t state);
