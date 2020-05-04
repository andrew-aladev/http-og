// HTTP old generation (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

// This file was generated, do not edit manually.
// This file is intended to be used by generator only.

// It may not be possible to run generator while cross compiling.
// So generated file should be distributed with its template.

#include "options.h"

// RFC 1945 - 6.1 Status-Line.
// RFC 1945 - 6.1.1 Status Code and Reason Phrase.
// RFC 1945 - B Tolerant Applications.
// RFC 7230 - 3.1.2 Status Line.
// RFC 7230 - 3.2.6 Field Value Components.
// RFC 7230 - 3.5 Message Parsing Robustness.

const hog_alphabet_range_t HOG_ALPHABET_RANGES[]      = {{'\x21', '\x7e'}, {'\x80', '\xff'}};
const size_t               HOG_ALPHABET_RANGES_LENGTH = sizeof(HOG_ALPHABET_RANGES) / sizeof(HOG_ALPHABET_RANGES[0]);

const char   HOG_ALPHABET[]      = {' ', '\t'};
const size_t HOG_ALPHABET_LENGTH = sizeof(HOG_ALPHABET) / sizeof(HOG_ALPHABET[0]);

const hog_alphabet_mode_t HOG_ALPHABET_MODE = HOG_ALPHABET_INCLUDING_BYTES_INTO_RANGES;

const size_t HOG_MIN_LENGTH = 1;
const size_t HOG_MAX_LENGTH = UINT16_MAX;
