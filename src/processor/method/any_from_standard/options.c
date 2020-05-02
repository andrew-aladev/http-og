// HTTP old generation (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

// This file was generated, do not edit manually.
// This file is intended to be used by generator only.

// It may not be possible to run generator while cross compiling.
// So generated file should be shipped with its template.

#include "options.h"

// HTTP Method Registry https://www.iana.org/assignments/http-methods/http-methods.xml

const hog_alphabet_range_t HOG_ALPHABET_RANGES[]      = {{'a', 'z'}, {'A', 'Z'}, {'0', '9'}};
const size_t               HOG_ALPHABET_RANGES_LENGTH = sizeof(HOG_ALPHABET_RANGES) / sizeof(HOG_ALPHABET_RANGES[0]);

const char   HOG_ALPHABET[]      = {'-'};
const size_t HOG_ALPHABET_LENGTH = sizeof(HOG_ALPHABET) / sizeof(HOG_ALPHABET[0]);

const hog_alphabet_mode_t HOG_ALPHABET_MODE = HOG_ALPHABET_INCLUDING_BYTES_INTO_RANGES;

const size_t HOG_MIN_LENGTH = 1;
const size_t HOG_MAX_LENGTH = UINT16_MAX;
