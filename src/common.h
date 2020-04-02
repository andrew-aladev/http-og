// HTTP old generation (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

#if !defined(HOG_COMMON_H)
#define HOG_COMMON_H

#include <stdint.h>

#include "config.h"

// We are working for POSIX systems only.
// POSIX system requires CHAR_BIT to be 8.
// We won't use "least" types from "stdint.h".

// We will use precise types for source, destination and constants to optimize memory consumption.
// We will try to use fast types in all other cases.

typedef uint_fast8_t hog_result_t;

typedef uint8_t      hog_symbol_t;
typedef uint_fast8_t hog_symbol_fast_t;

// Unified fast processor state type.
typedef uint_fast32_t hog_processor_state_fast_t;

#define HOG_MAX_SYMBOL UINT8_MAX

#endif // HOG_COMMON_H
