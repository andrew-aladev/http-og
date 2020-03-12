// Old generation HTTP (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

#if !defined(OGHTTP_PARSER_CONSTANTS_H)
#define OGHTTP_PARSER_CONSTANTS_H

#include <stdlib.h>

#include "common.h"

#define OGHTTP_PARSER_CONSTANTS_GENERATE_DATA(PREFIX, CONSTANTS)        \
  const char*  OGHTTP_##PREFIX##_PARSER_CONSTANTS[]      = {CONSTANTS}; \
  const size_t OGHTTP_##PREFIX##_PARSER_CONSTANTS_LENGTH = sizeof(OGHTTP_##PREFIX##_PARSER_CONSTANTS) / sizeof(OGHTTP_##PREFIX##_PARSER_CONSTANTS[0]);

#define OGHTTP_PARSER_CONSTANTS_GENERATE_INITIAL_STATE(PREFIX, PREFIX_LOWER_CASE) \
  const oghttp_##PREFIX_LOWER_CASE##_parser_state_fast_t OGHTTP_##PREFIX##_PARSER_INITIAL_STATE = OGHTTP_##PREFIX##_PARSER_CONSTANTS_LENGTH;

#define OGHTTP_PARSER_CONSTANTS_GENERATE_ALPHABET(PREFIX, ALPHABET)            \
  const oghttp_symbol_t OGHTTP_##PREFIX##_PARSER_ALPHABET[]      = {ALPHABET}; \
  const size_t          OGHTTP_##PREFIX##_PARSER_ALPHABET_LENGTH = sizeof(OGHTTP_##PREFIX##_PARSER_ALPHABET) / sizeof(OGHTTP_##PREFIX##_PARSER_ALPHABET[0]);

#define OGHTTP_PARSER_CONSTANTS_GENERATE_SYMBOL_BY_BYTES(PREFIX, SYMBOL_BY_BYTES)                                     \
  const oghttp_symbol_fast_t OGHTTP_##PREFIX##_PARSER_UNDEFINED_SYMBOL       = OGHTTP_SYMBOL_MAX;                     \
  const size_t               OGHTTP_##PREFIX##_PARSER_SYMBOL_BY_BYTES_LENGTH = OGHTTP_SYMBOL_MAX + 1;                 \
                                                                                                                      \
  const oghttp_symbol_t OGHTTP_##PREFIX##_PARSER_SYMBOL_BY_BYTES[OGHTTP_##PREFIX##_PARSER_SYMBOL_BY_BYTES_LENGTH] = { \
    [0 ... OGHTTP_##PREFIX##_PARSER_SYMBOL_BY_BYTES_LENGTH - 1] = OGHTTP_##PREFIX##_PARSER_UNDEFINED_SYMBOL,          \
    SYMBOL_BY_BYTES};

#endif // OGHTTP_PARSER_CONSTANTS_H
