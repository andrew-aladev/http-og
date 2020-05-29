// Old generation HTTP (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

#if !defined(OGH_COMMON_H)
#define OGH_COMMON_H

#include <stdint.h>

#include "config.h"

// We are working for POSIX systems only.
// POSIX system requires CHAR_BIT to be 8.
// We won't use "least" types from "stdint.h".

// We will use precise types for source, destination and constants to optimize memory consumption.
// We will try to use fast types in all other cases.

typedef uint_fast8_t ogh_result_t;

typedef uint8_t      ogh_byte_t;
typedef uint_fast8_t ogh_byte_fast_t;

// Unified fast processor state type.
typedef uint_fast32_t ogh_processor_state_fast_t;

#define OGH_MAX_SYMBOL UINT8_MAX

#endif // OGH_COMMON_H
