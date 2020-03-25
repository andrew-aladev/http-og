// Old generation HTTP (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

// This file was generated, do not edit manually.

// It may not be possible to run generator while cross compiling.
// So generated file should be shipped with its template.

#if !defined(OGHTTP_METHOD_v1_0_PARSER_H)
#define OGHTTP_METHOD_v1_0_PARSER_H

#include <stdint.h>
#include <stdlib.h>

#include "../../parser/constants/../../common.h"

typedef uint8_t      oghttp_method_v1_0_parser_state_t;
typedef uint_fast8_t oghttp_method_v1_0_parser_state_fast_t;

// -- constants --

extern const char*  OGHTTP_METHOD_v1_0_PARSER_CONSTANTS[];
extern const size_t OGHTTP_METHOD_v1_0_PARSER_CONSTANTS_LENGTH;

extern const oghttp_method_v1_0_parser_state_fast_t OGHTTP_METHOD_v1_0_PARSER_INITIAL_STATE;

// -- alphabet --

extern const oghttp_symbol_t OGHTTP_METHOD_v1_0_PARSER_ALPHABET[];
extern const size_t          OGHTTP_METHOD_v1_0_PARSER_ALPHABET_LENGTH;

extern const oghttp_symbol_fast_t OGHTTP_METHOD_v1_0_PARSER_UNDEFINED_SYMBOL;
extern const size_t               OGHTTP_METHOD_v1_0_PARSER_SYMBOL_BY_BYTES_LENGTH;
extern const oghttp_symbol_t      OGHTTP_METHOD_v1_0_PARSER_SYMBOL_BY_BYTES[];

// -- next state by last symbols --

extern const size_t OGHTTP_METHOD_v1_0_NEXT_STATE_BY_LAST_SYMBOLS_LENGTH;

extern const oghttp_method_v1_0_parser_state_t OGHTTP_METHOD_v1_0_NEXT_STATE_BY_LAST_SYMBOLS;

#endif // OGHTTP_METHOD_v1_0_PARSER_H
