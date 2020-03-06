// Old generation HTTP (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

#if !defined(OGHTTP_PARSER_CONSTANTS_H)
#define OGHTTP_PARSER_CONSTANTS_H

#include <stdint.h>

#define OGHTTP_PARSER_GENERATE_CONSTANTS(PREFIX, CONSTANTS) \
  const char* OGHTTP_##PREFIX##_PARSER_CONSTANTS[] = {CONSTANTS};

#define OGHTTP_PARSER_GENERATE_ALPHABET(PREFIX, ALPHABET) \
  const uint8_t OGHTTP_##PREFIX##_PARSER_ALPHABET[] = {ALPHABET};

#define OGHTTP_PARSER_GENERATE_SYMBOL_BY_BYTES(PREFIX, SYMBOL_BY_BYTES)                                       \
  const uint_fast16_t OGHTTP_##PREFIX##_PARSER_SYMBOL_BY_BYTES_LENGTH = UINT8_MAX + 1;                        \
  const uint8_t       OGHTTP_##PREFIX##_PARSER_UNDEFINED_SYMBOL       = UINT8_MAX;                            \
                                                                                                              \
  const uint8_t OGHTTP_##PREFIX##_PARSER_SYMBOL_BY_BYTES[OGHTTP_##PREFIX##_PARSER_SYMBOL_BY_BYTES_LENGTH] = { \
    [0 ... OGHTTP_##PREFIX##_PARSER_SYMBOL_BY_BYTES_LENGTH - 1] = OGHTTP_##PREFIX##_PARSER_UNDEFINED_SYMBOL,  \
    SYMBOL_BY_BYTES};

#endif // OGHTTP_PARSER_CONSTANTS_H
