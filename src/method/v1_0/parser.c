// Old generation HTTP (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

// This file was generated, do not edit manually.

// It may not be possible to run generator while cross compiling.
// So generated file should be shipped with its template.

#include "parser.h"

// clang-format off

// -- constants --

const char* OGHTTP_METHOD_v1_0_PARSER_CONSTANTS[] = {
  "GET",
  "HEAD",
  "POST"};

const size_t OGHTTP_METHOD_v1_0_PARSER_CONSTANTS_LENGTH = sizeof(OGHTTP_METHOD_v1_0_PARSER_CONSTANTS) / sizeof(OGHTTP_METHOD_v1_0_PARSER_CONSTANTS[0]);
const oghttp_method_v1_0_parser_state_fast_t OGHTTP_METHOD_v1_0_PARSER_INITIAL_STATE = OGHTTP_METHOD_v1_0_PARSER_CONSTANTS_LENGTH;

// -- alphabet --

const oghttp_symbol_t OGHTTP_METHOD_v1_0_PARSER_ALPHABET[] = {
  71,
  69,
  84,
  72,
  65,
  68,
  80,
  79,
  83};

const size_t OGHTTP_METHOD_v1_0_PARSER_ALPHABET_LENGTH     = sizeof(OGHTTP_METHOD_v1_0_PARSER_ALPHABET) / sizeof(OGHTTP_METHOD_v1_0_PARSER_ALPHABET[0]);
const size_t OGHTTP_METHOD_v1_0_PARSER_ALPHABET_MAX_LENGTH = OGHTTP_MAX_SYMBOL + 1;

const oghttp_symbol_fast_t OGHTTP_METHOD_v1_0_PARSER_UNDEFINED_SYMBOL       = OGHTTP_MAX_SYMBOL;
const size_t               OGHTTP_METHOD_v1_0_PARSER_SYMBOL_BY_BYTES_LENGTH = OGHTTP_MAX_SYMBOL + 1;

const oghttp_symbol_t OGHTTP_METHOD_v1_0_PARSER_SYMBOL_BY_BYTES[OGHTTP_METHOD_v1_0_PARSER_SYMBOL_BY_BYTES_LENGTH] = {
  [0 ... OGHTTP_METHOD_v1_0_PARSER_SYMBOL_BY_BYTES_LENGTH - 1] = OGHTTP_METHOD_v1_0_PARSER_UNDEFINED_SYMBOL,
  [71] = 0,
  [69] = 1,
  [84] = 2,
  [72] = 3,
  [65] = 4,
  [68] = 5,
  [80] = 6,
  [79] = 7,
  [83] = 8};

// -- next state by last symbols --

const size_t OGHTTP_METHOD_v1_0_NEXT_STATE_BY_LAST_SYMBOLS_LENGTH = (11 + 1) * OGHTTP_METHOD_v1_0_PARSER_ALPHABET_LENGTH;

const oghttp_method_v1_0_parser_state_t OGHTTP_METHOD_v1_0_NEXT_STATE_BY_LAST_SYMBOLS[OGHTTP_METHOD_v1_0_NEXT_STATE_BY_LAST_SYMBOLS_LENGTH] = {
  [0 ... OGHTTP_METHOD_v1_0_NEXT_STATE_BY_LAST_SYMBOLS_LENGTH - 1] = OGHTTP_METHOD_v1_0_PARSER_INITIAL_STATE,
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

extern inline oghttp_method_v1_0_parser_state_fast_t oghttp_method_v1_0_get_next_state(
  oghttp_method_v1_0_parser_state_fast_t state, oghttp_symbol_fast_t byte);

extern inline bool oghttp_method_v1_0_is_finished(oghttp_method_v1_0_parser_state_fast_t state);
