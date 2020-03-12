// Old generation HTTP (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

#if !defined(OGHTTP_PARSER_COMMON_H)
#define OGHTTP_PARSER_COMMON_H

#include <stdint.h>

#define OGHTTP_PARSER_GENERATE_STATE_TYPE(PREFIX_LOWER_CASE, MIN_STATE_BITS) \
  typedef uint##MIN_STATE_BITS##_t oghttp_##PREFIX_LOWER_CASE##_parser_state_t;

#define OGHTTP_PARSER_GENERATE_FAST_STATE_TYPE(PREFIX_LOWER_CASE, MIN_STATE_BITS) \
  typedef uint_fast##MIN_STATE_BITS##_t oghttp_##PREFIX_LOWER_CASE##_parser_state_fast_t;

#define OGHTTP_PARSER_GENERATE_INITIAL_STATE(PREFIX, PREFIX_LOWER_CASE, VALUE) \
  const oghttp_##PREFIX_LOWER_CASE##_parser_state_fast_t OGHTTP_##PREFIX##_PARSER_INITIAL_STATE = VALUE;

#endif // OGHTTP_PARSER_COMMON_H
