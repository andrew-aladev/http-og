// Old generation HTTP (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

// It may not be possible to run generator while cross compiling.
// So generated file should be shipped with its template.

#if !defined(OGHTTP_METHOD_v1_0_STRICT_GENERATED_PARSER_H)
#define OGHTTP_METHOD_v1_0_STRICT_GENERATED_PARSER_H

#include "../../macro.h"
#include "../../parser/common.h"
#include "../../parser/constants.h"

OGHTTP_PARSER_GENERATE_STATE_TYPE(method_v1_0_strict, 8);
OGHTTP_PARSER_GENERATE_FAST_STATE_TYPE(method_v1_0_strict, 8);

OGHTTP_PARSER_GENERATE_CONSTANTS(
  METHOD_v1_0_STRICT,
  OGHTTP_ARGUMENTS(
    "GET",
    "HEAD",
    "POST"));
OGHTTP_PARSER_GENERATE_ALPHABET(
  METHOD_v1_0_STRICT,
  OGHTTP_ARGUMENTS(
    71,
    69,
    84,
    72,
    65,
    68,
    80,
    79,
    83));
OGHTTP_PARSER_GENERATE_SYMBOL_BY_BYTES(
  METHOD_v1_0_STRICT,
  OGHTTP_ARGUMENTS(
    [71] = 0,
    [69] = 1,
    [84] = 2,
    [72] = 3,
    [65] = 4,
    [68] = 5,
    [80] = 6,
    [79] = 7,
    [83] = 8));

#endif // OGHTTP_METHOD_v1_0_STRICT_GENERATED_PARSER_H
