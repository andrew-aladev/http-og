// Old generation HTTP (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

// This file was generated, do not edit manually.

// It may not be possible to run generator while cross compiling.
// So generated file should be distributed with its template.

#include "main.h"

const ogh_processor_state_fast_t OGH_PROCESSOR_VERSION_PREFIX_INITIAL_STATE = 0;

const ogh_byte_t OGH_PROCESSOR_VERSION_PREFIX_CONSTANT_SYMBOLS[] = {0x48, 0x54, 0x54, 0x50, 0x2f};

const ogh_processor_state_fast_t OGH_PROCESSOR_VERSION_PREFIX_CONSTANT_LENGTH = 5;

extern inline ogh_processor_state_fast_t ogh_processor_version_prefix_get_next_state(
  ogh_processor_state_fast_t state,
  ogh_byte_fast_t            byte);

extern inline bool ogh_processor_version_prefix_is_valid(ogh_processor_state_fast_t state);
