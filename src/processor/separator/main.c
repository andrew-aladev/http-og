// HTTP old generation (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

// This file was generated, do not edit manually.

// It may not be possible to run generator while cross compiling.
// So generated file should be shipped with its template.

#include ".h"

const hog_processor_state_fast_t HOG_PROCESSOR_SEPARATOR_INITIAL_STATE = 0;

const size_t HOG_PROCESSOR_SEPARATOR_MIN_LENGTH = 1;
const size_t HOG_PROCESSOR_SEPARATOR_MAX_LENGTH = 255;

#define ALLOWED_BYTES_LENGTH HOG_MAX_SYMBOL + 1

// clang-format off

const bool HOG_PROCESSOR_SEPARATOR_ALLOWED_BYTES[ALLOWED_BYTES_LENGTH] = {
  [0 ... ALLOWED_BYTES_LENGTH - 1] = false,
  [32] = true,
  [9] = true};

// clang-format on

extern inline hog_processor_state_fast_t hog_processor_separator_get_next_state(
  hog_processor_state_fast_t state, hog_symbol_fast_t byte);

extern inline bool hog_processor_separator_is_finished(hog_processor_state_fast_t state);
