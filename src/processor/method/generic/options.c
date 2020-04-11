// HTTP old generation (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

// This file is intended to be used by generator only.

#include "options.h"

#include <stdint.h>

// HTTP Method Registry https://www.iana.org/assignments/http-methods/http-methods.xml.

const char HOG_ALPHABET[] = {'-'};

const size_t HOG_ALPHABET_LENGTH = sizeof(HOG_ALPHABET) / sizeof(HOG_ALPHABET[0]);

const hog_alphabet_range HOG_ALPHABET_RANGES[] = {
  {'a', 'z'},
  {'A', 'Z'},
  {'0', '9'}};

const size_t HOG_ALPHABET_RANGES_LENGTH = sizeof(HOG_ALPHABET_RANGES) / sizeof(HOG_ALPHABET_RANGES[0]);

const size_t HOG_MIN_LENGTH = 1;
const size_t HOG_MAX_LENGTH = UINT8_MAX;
