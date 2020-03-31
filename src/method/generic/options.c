// HTTP old generation (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

// This file is intended to be used by generator only.

#include "options.h"

#include <stdint.h>

const hog_alphabet_range HOG_ALPHABET_RANGES[] = {
  {'a', 'z'},
  {'A', 'Z'},
  {'0', '9'}};

const char HOG_ALPHABET[] = {
  '-'};

const size_t HOG_MIN_LENGTH = 1;

// We can fail if custom HTTP method length is greater than max symbol.
const size_t HOG_MAX_LENGTH = UINT8_MAX;
