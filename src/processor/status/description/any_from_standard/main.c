// HTTP old generation (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

// This file was generated, do not edit manually.

// It may not be possible to run generator while cross compiling.
// So generated file should be shipped with its template.

#include "main.h"

const hog_processor_state_fast_t HOG_PROCESSOR_STATUS_DESCRIPTION_ANY_FROM_STANDARD_INITIAL_STATE = 0;

const size_t HOG_PROCESSOR_STATUS_DESCRIPTION_ANY_FROM_STANDARD_MIN_LENGTH = 1;
const size_t HOG_PROCESSOR_STATUS_DESCRIPTION_ANY_FROM_STANDARD_MAX_LENGTH = 65535;

#define ALLOWED_BYTES_LENGTH HOG_MAX_SYMBOL + 1

// clang-format off

const bool HOG_PROCESSOR_STATUS_DESCRIPTION_ANY_FROM_STANDARD_ALLOWED_BYTES[ALLOWED_BYTES_LENGTH] = {
  [0 ... ALLOWED_BYTES_LENGTH - 1] = false,
  [67] = true,
  [111] = true,
  [110] = true,
  [116] = true,
  [105] = true,
  [117] = true,
  [101] = true,
  [83] = true,
  [119] = true,
  [99] = true,
  [104] = true,
  [103] = true,
  [32] = true,
  [80] = true,
  [114] = true,
  [108] = true,
  [115] = true,
  [69] = true,
  [97] = true,
  [121] = true,
  [72] = true,
  [85] = true,
  [100] = true,
  [79] = true,
  [75] = true,
  [65] = true,
  [112] = true,
  [78] = true,
  [45] = true,
  [118] = true,
  [73] = true,
  [102] = true,
  [109] = true,
  [82] = true,
  [77] = true,
  [70] = true,
  [120] = true,
  [40] = true,
  [41] = true,
  [84] = true,
  [66] = true,
  [113] = true,
  [122] = true,
  [98] = true,
  [71] = true,
  [76] = true,
  [107] = true,
  [68] = true,
  [86] = true};

// clang-format on

extern inline hog_processor_state_fast_t hog_processor_status_description_any_from_standard_get_next_state(
  hog_processor_state_fast_t state, hog_symbol_fast_t byte);

extern inline bool hog_processor_status_description_any_from_standard_is_finished(hog_processor_state_fast_t state);
