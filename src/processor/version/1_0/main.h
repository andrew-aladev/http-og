// HTTP old generation (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

// This file was generated, do not edit manually.

// It may not be possible to run generator while cross compiling.
// So generated file should be distributed with its template.

#if !defined(HOG_PROCESSOR_VERSION_1_0_H)
#define HOG_PROCESSOR_VERSION_1_0_H

#include <stdbool.h>

#include "../../../common.h"
#include "../../../log.h"

extern const hog_processor_state_fast_t HOG_PROCESSOR_VERSION_1_0_INITIAL_STATE;

extern const hog_symbol_t               HOG_PROCESSOR_VERSION_1_0_CONSTANT_SYMBOLS[];
extern const hog_processor_state_fast_t HOG_PROCESSOR_VERSION_1_0_CONSTANT_LENGTH;

inline hog_processor_state_fast_t hog_processor_version_1_0_get_next_state(
  hog_processor_state_fast_t state, hog_symbol_fast_t byte)
{
  if (HOG_PROCESSOR_VERSION_1_0_CONSTANT_SYMBOLS[state] != byte) {
    HOG_LOG_ERROR("version_1_0 processor received invalid byte: %u", byte);
    return HOG_PROCESSOR_VERSION_1_0_INITIAL_STATE;
  }

  return state + 1;
}

inline bool hog_processor_version_1_0_is_valid(hog_processor_state_fast_t state)
{
  return state == HOG_PROCESSOR_VERSION_1_0_CONSTANT_LENGTH;
}

#endif // HOG_PROCESSOR_VERSION_1_0_H
