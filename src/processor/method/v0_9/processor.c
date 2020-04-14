// HTTP old generation (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

// This file was generated, do not edit manually.

// It may not be possible to run generator while cross compiling.
// So generated file should be shipped with its template.

#include "processor.h"

const hog_processor_state_fast_t HOG_PROCESSOR_METHOD_v0_9_INITIAL_STATE = 0;

const hog_symbol_t HOG_PROCESSOR_METHOD_v0_9_CONSTANT_SYMBOLS[] = {
  0x47,
  0x45,
  0x54};

const size_t HOG_PROCESSOR_METHOD_v0_9_CONSTANT_LENGTH = 3;

extern inline hog_processor_state_fast_t hog_processor_method_v0_9_get_next_state(
  hog_processor_state_fast_t state, hog_symbol_fast_t byte);

extern inline bool hog_processor_method_v0_9_is_finished(hog_processor_state_fast_t state);
