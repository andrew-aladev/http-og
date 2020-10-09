// Old generation HTTP (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

// This file was generated, do not edit manually.

// It may not be possible to run generator while cross compiling.
// So generated file should be distributed with its template.

#include "main.h"

const ogh_processor_state_fast_t OGH_PROCESSOR_HEADER_SEPARATOR_INITIAL_STATE = 0;

const ogh_processor_state_fast_t OGH_PROCESSOR_HEADER_SEPARATOR_MIN_LENGTH = 1;
const ogh_processor_state_fast_t OGH_PROCESSOR_HEADER_SEPARATOR_MAX_LENGTH = 1;

#define ALLOWED_BYTES_LENGTH OGH_MAX_SYMBOL + 1

// clang-format off

const bool OGH_PROCESSOR_HEADER_SEPARATOR_ALLOWED_BYTES[ALLOWED_BYTES_LENGTH] = {
  [0 ... ALLOWED_BYTES_LENGTH - 1] = false,
  [58] = true};

// clang-format on

extern inline ogh_processor_state_fast_t ogh_processor_header_separator_get_next_state(ogh_processor_state_fast_t state,
                                                                                       ogh_byte_fast_t            byte);

extern inline bool ogh_processor_header_separator_is_valid(ogh_processor_state_fast_t state);
