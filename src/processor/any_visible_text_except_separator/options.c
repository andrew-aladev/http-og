// Old generation HTTP (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

// This file was generated, do not edit manually.
// This file is intended to be used by generator only.

// It may not be possible to run generator while cross compiling.
// So generated file should be distributed with its template.

#include "options.h"

// RFC 1945 - 2.2 Basic Rules.
// RFC 7230 - Appendix B. Collected ABNF.

const ogh_alphabet_range_t OGH_ALPHABET_RANGES[]      = {{'\x21', '\x7e'}, {'\x80', '\xff'}};
const size_t               OGH_ALPHABET_RANGES_LENGTH = sizeof(OGH_ALPHABET_RANGES) / sizeof(OGH_ALPHABET_RANGES[0]);

const char   OGH_ALPHABET[]      = {0};
const size_t OGH_ALPHABET_LENGTH = 0;

const ogh_alphabet_mode_t OGH_ALPHABET_MODE = OGH_ALPHABET_INCLUDING_BYTES_INTO_RANGES;

const size_t OGH_MIN_LENGTH = 1;
const size_t OGH_MAX_LENGTH = UINT16_MAX;
