// HTTP old generation (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

// This file is intended to be used by generator only.

#include "options.h"

#include <limits.h>

// Version should be a part of both request and response status lines.
// So we can use any bytes except separators or terminators.

const hog_alphabet_range_t HOG_ALPHABET_RANGES[]      = {{CHAR_MIN, CHAR_MAX}};
const size_t               HOG_ALPHABET_RANGES_LENGTH = sizeof(HOG_ALPHABET_RANGES) / sizeof(HOG_ALPHABET_RANGES[0]);

const char   HOG_ALPHABET[]      = {' ', '\t', '\r', '\n'};
const size_t HOG_ALPHABET_LENGTH = sizeof(HOG_ALPHABET) / sizeof(HOG_ALPHABET[0]);

const hog_alphabet_mode_t HOG_ALPHABET_MODE = HOG_ALPHABET_EXCLUDING_BYTES_FROM_RANGES;

const size_t HOG_MIN_LENGTH = 1;
const size_t HOG_MAX_LENGTH = UINT16_MAX;
