// HTTP old generation (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

// This file was generated, do not edit manually.

// It may not be possible to run generator while cross compiling.
// So generated file should be distributed with its template.

#include "main.h"

const hog_processor_state_fast_t HOG_PROCESSOR_STATUS_CODE_ANY_FROM_STANDARD_INITIAL_STATE = 0;

const hog_processor_state_fast_t HOG_PROCESSOR_STATUS_CODE_ANY_FROM_STANDARD_MIN_LENGTH = 1;
const hog_processor_state_fast_t HOG_PROCESSOR_STATUS_CODE_ANY_FROM_STANDARD_MAX_LENGTH = 255;

#define ALLOWED_BYTES_LENGTH HOG_MAX_SYMBOL + 1

// clang-format off

const bool HOG_PROCESSOR_STATUS_CODE_ANY_FROM_STANDARD_ALLOWED_BYTES[ALLOWED_BYTES_LENGTH] = {
  [0 ... ALLOWED_BYTES_LENGTH - 1] = false,
  [48] = true,
  [49] = true,
  [50] = true,
  [51] = true,
  [52] = true,
  [53] = true,
  [54] = true,
  [55] = true,
  [56] = true,
  [57] = true};

// clang-format on

extern inline hog_processor_state_fast_t hog_processor_status_code_any_from_standard_get_next_state(
  hog_processor_state_fast_t state, hog_symbol_fast_t byte);

extern inline bool hog_processor_status_code_any_from_standard_is_valid(hog_processor_state_fast_t state);
