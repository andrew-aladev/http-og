// HTTP old generation (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

// This file was generated, do not edit manually.

// It may not be possible to run generator while cross compiling.
// So generated file should be shipped with its template.

#if !defined(HOG_PROCESSOR_METHOD_v0_9_H)
#define HOG_PROCESSOR_METHOD_v0_9_H

#include <stdbool.h>
#include <stdlib.h>

#include "../../../common.h"
#include "../../../log.h"

extern const hog_processor_state_fast_t HOG_PROCESSOR_METHOD_v0_9_INITIAL_STATE;

extern const hog_symbol_t HOG_PROCESSOR_METHOD_v0_9_CONSTANT_SYMBOLS[];
extern const size_t       HOG_PROCESSOR_METHOD_v0_9_CONSTANT_LENGTH;

inline hog_processor_state_fast_t hog_processor_method_v0_9_get_next_state(
  hog_processor_state_fast_t state, hog_symbol_fast_t byte)
{
  if (HOG_PROCESSOR_METHOD_v0_9_CONSTANT_SYMBOLS[state] != byte) {
    HOG_LOG_ERROR("method_v0_9 processor received invalid byte: %u", byte);
    return HOG_PROCESSOR_METHOD_v0_9_INITIAL_STATE;
  }

  return state + 1;
}

inline bool hog_processor_method_v0_9_is_finished(hog_processor_state_fast_t state)
{
  return state == HOG_PROCESSOR_METHOD_v0_9_CONSTANT_LENGTH;
}

#endif // HOG_PROCESSOR_METHOD_v0_9_H
