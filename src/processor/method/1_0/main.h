// Old generation HTTP (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

// This file was generated, do not edit manually.

// It may not be possible to run generator while cross compiling.
// So generated file should be distributed with its template.

#if !defined(OGH_PROCESSOR_METHOD_1_0_H)
#define OGH_PROCESSOR_METHOD_1_0_H

#include <stdbool.h>

#include "../../../common.h"
#include "../../../log.h"

extern const ogh_processor_state_fast_t OGH_PROCESSOR_METHOD_1_0_INITIAL_STATE;

extern const ogh_processor_state_fast_t OGH_PROCESSOR_METHOD_1_0_CONSTANTS_LENGTH;

extern const uint_fast16_t OGH_PROCESSOR_METHOD_1_0_ALPHABET_LENGTH;
extern const uint_fast16_t OGH_PROCESSOR_METHOD_1_0_ALPHABET_MAX_LENGTH;

extern const ogh_byte_fast_t OGH_PROCESSOR_METHOD_1_0_UNDEFINED_SYMBOL;
extern const ogh_byte_t      OGH_PROCESSOR_METHOD_1_0_SYMBOL_BY_BYTES[];

typedef uint8_t ogh_processor_method_1_0_state_t;

extern const ogh_processor_method_1_0_state_t OGH_PROCESSOR_METHOD_1_0_NEXT_STATE_BY_LAST_SYMBOLS[];

inline ogh_processor_state_fast_t ogh_processor_method_1_0_get_next_state(
  ogh_processor_state_fast_t state, ogh_byte_fast_t byte)
{
  ogh_byte_fast_t symbol = OGH_PROCESSOR_METHOD_1_0_SYMBOL_BY_BYTES[byte];

  // We need to verify symbol if alphabet is not full.
  if (OGH_PROCESSOR_METHOD_1_0_ALPHABET_LENGTH != OGH_PROCESSOR_METHOD_1_0_ALPHABET_MAX_LENGTH && symbol == OGH_PROCESSOR_METHOD_1_0_UNDEFINED_SYMBOL) {
    OGH_LOG_ERROR("method_1_0 processor received invalid byte: %u", byte);
    return OGH_PROCESSOR_METHOD_1_0_INITIAL_STATE;
  }

  return OGH_PROCESSOR_METHOD_1_0_NEXT_STATE_BY_LAST_SYMBOLS[state * OGH_PROCESSOR_METHOD_1_0_ALPHABET_LENGTH + symbol];
}

inline bool ogh_processor_method_1_0_is_valid(ogh_processor_state_fast_t state)
{
  // State of each constant equals to its index.
  return state < OGH_PROCESSOR_METHOD_1_0_CONSTANTS_LENGTH;
}

#endif // OGH_PROCESSOR_METHOD_1_0_H
