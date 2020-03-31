// HTTP old generation (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

// This file was generated, do not edit manually.

// It may not be possible to run generator while cross compiling.
// So generated file should be shipped with its template.

#include "processor.h"

// clang-format off

// -- constant --

const char*  HOG_METHOD_v0_9_PROCESSOR_CONSTANT        = "GET";
const size_t HOG_METHOD_v0_9_PROCESSOR_CONSTANT_LENGTH = 3;

const hog_method_v0_9_processor_state_fast_t HOG_METHOD_v0_9_PROCESSOR_INITIAL_STATE = 0;

// clang-format on

extern inline hog_method_v0_9_processor_state_fast_t hog_method_v0_9_get_next_state(
  hog_method_v0_9_processor_state_fast_t state, hog_symbol_fast_t byte);

extern inline bool hog_method_v0_9_is_finished(hog_method_v0_9_processor_state_fast_t state);
