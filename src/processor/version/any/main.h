// HTTP old generation (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

// This file was generated, do not edit manually.

// It may not be possible to run generator while cross compiling.
// So generated file should be shipped with its template.

#if !defined(HOG_PROCESSOR_VERSION_ANY_H)
#define HOG_PROCESSOR_VERSION_ANY_H

#include <stdbool.h>
#include <stdlib.h>

#include "../../../common.h"
#include "../../../log.h"

extern const hog_processor_state_fast_t HOG_PROCESSOR_VERSION_ANY_INITIAL_STATE;

extern const size_t HOG_PROCESSOR_VERSION_ANY_MIN_LENGTH;
extern const size_t HOG_PROCESSOR_VERSION_ANY_MAX_LENGTH;

extern const bool HOG_PROCESSOR_VERSION_ANY_ALLOWED_BYTES[];

inline hog_processor_state_fast_t hog_processor_version_any_get_next_state(
  hog_processor_state_fast_t state, hog_symbol_fast_t byte)
{
  if (state == HOG_PROCESSOR_VERSION_ANY_MAX_LENGTH || !HOG_PROCESSOR_VERSION_ANY_ALLOWED_BYTES[byte]) {
    HOG_LOG_ERROR("version_any processor received invalid byte: %u", byte);
    return HOG_PROCESSOR_VERSION_ANY_INITIAL_STATE;
  }

  return state + 1;
}

inline bool hog_processor_version_any_is_finished(hog_processor_state_fast_t state)
{
  return state >= HOG_PROCESSOR_VERSION_ANY_MIN_LENGTH;
}

#endif // HOG_PROCESSOR_VERSION_ANY_H
