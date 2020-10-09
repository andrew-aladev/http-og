// Old generation HTTP (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

// This file was generated, do not edit manually.

// It may not be possible to run generator while cross compiling.
// So generated file should be distributed with its template.

#if !defined(OGH_PROCESSOR_HEADER_SEPARATOR_H)
#define OGH_PROCESSOR_HEADER_SEPARATOR_H

#include <stdbool.h>

#include "../../../common.h"
#include "../../../log.h"

extern const ogh_processor_state_fast_t OGH_PROCESSOR_HEADER_SEPARATOR_INITIAL_STATE;

extern const ogh_processor_state_fast_t OGH_PROCESSOR_HEADER_SEPARATOR_MIN_LENGTH;
extern const ogh_processor_state_fast_t OGH_PROCESSOR_HEADER_SEPARATOR_MAX_LENGTH;

extern const bool OGH_PROCESSOR_HEADER_SEPARATOR_ALLOWED_BYTES[];

inline ogh_processor_state_fast_t ogh_processor_header_separator_get_next_state(ogh_processor_state_fast_t state,
                                                                                ogh_byte_fast_t            byte)
{
  if (state == OGH_PROCESSOR_HEADER_SEPARATOR_MAX_LENGTH) {
    OGH_LOG_ERROR("header_separator processor exceeded max length");
    return OGH_PROCESSOR_HEADER_SEPARATOR_INITIAL_STATE;
  }

  if (!OGH_PROCESSOR_HEADER_SEPARATOR_ALLOWED_BYTES[byte]) {
    OGH_LOG_ERROR("header_separator processor received invalid byte: %u", byte);
    return OGH_PROCESSOR_HEADER_SEPARATOR_INITIAL_STATE;
  }

  return state + 1;
}

inline bool ogh_processor_header_separator_is_valid(ogh_processor_state_fast_t state)
{
  return state >= OGH_PROCESSOR_HEADER_SEPARATOR_MIN_LENGTH;
}

#endif // OGH_PROCESSOR_HEADER_SEPARATOR_H
