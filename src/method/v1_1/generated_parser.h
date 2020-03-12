// Old generation HTTP (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

// It may not be possible to run generator while cross compiling.
// So generated file should be shipped with its template.

#if !defined(OGHTTP_METHOD_v1_1_GENERATED_PARSER_H)
#define OGHTTP_METHOD_v1_1_GENERATED_PARSER_H

#include "../../macro.h"
#include "../../parser/constants.h"

OGHTTP_PARSER_GENERATE_STATE_TYPE(method_v1_1, 8);
OGHTTP_PARSER_GENERATE_FAST_STATE_TYPE(method_v1_1, 8);

OGHTTP_PARSER_CONSTANTS_GENERATE_DATA(
  METHOD_v1_1,
  OGHTTP_ARGUMENTS(
    "OPTIONS",
    "GET",
    "HEAD",
    "POST",
    "PUT",
    "DELETE",
    "TRACE",
    "CONNECT",
    "PATCH",
    "LINK",
    "UNLINK",
    "PROPFIND",
    "PROPPATCH",
    "MKCOL",
    "COPY",
    "MOVE",
    "LOCK",
    "UNLOCK",
    "BIND",
    "UNBIND",
    "REBIND",
    "ACL",
    "REPORT",
    "SEARCH",
    "VERSION-CONTROL",
    "CHECKOUT",
    "CHECKIN",
    "UNCHECKOUT",
    "MKWORKSPACE",
    "UPDATE",
    "LABEL",
    "MERGE",
    "BASELINE-CONTROL",
    "MKACTIVITY",
    "MKREDIRECTREF",
    "UPDATEREDIRECTREF",
    "ORDERPATCH",
    "MKCALENDAR",
    "PRI"));

OGHTTP_PARSER_CONSTANTS_GENERATE_INITIAL_STATE(METHOD_v1_1, method_v1_1);

OGHTTP_PARSER_CONSTANTS_GENERATE_ALPHABET(
  METHOD_v1_1,
  OGHTTP_ARGUMENTS(
    79,
    80,
    84,
    73,
    78,
    83,
    71,
    69,
    72,
    65,
    68,
    85,
    76,
    82,
    67,
    75,
    70,
    77,
    89,
    86,
    66,
    45,
    87));

OGHTTP_PARSER_CONSTANTS_GENERATE_SYMBOL_BY_BYTES(
  METHOD_v1_1,
  OGHTTP_ARGUMENTS(
    [79] = 0,
    [80] = 1,
    [84] = 2,
    [73] = 3,
    [78] = 4,
    [83] = 5,
    [71] = 6,
    [69] = 7,
    [72] = 8,
    [65] = 9,
    [68] = 10,
    [85] = 11,
    [76] = 12,
    [82] = 13,
    [67] = 14,
    [75] = 15,
    [70] = 16,
    [77] = 17,
    [89] = 18,
    [86] = 19,
    [66] = 20,
    [45] = 21,
    [87] = 22));

#endif // OGHTTP_METHOD_v1_1_GENERATED_PARSER_H
