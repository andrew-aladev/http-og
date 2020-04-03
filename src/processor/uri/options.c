// HTTP old generation (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

// This file is intended to be used by generator only.

#include "options.h"

#include <stdint.h>

// Real world URIs are far away from any RFC.
// We need to collect real world statistics about what characters can be used.
// Free statistics is available from terabytes of accidentally published webserver logs.
// See "scripts/uri-collector".

const char   HOG_ALPHABET[]      = {':'};
const size_t HOG_ALPHABET_LENGTH = sizeof(HOG_ALPHABET) / sizeof(HOG_ALPHABET[0]);

const hog_alphabet_range HOG_ALPHABET_RANGES[] = {
  {'a', 'z'},
  {'A', 'Z'},
  {'0', '9'}};
const size_t HOG_ALPHABET_RANGES_LENGTH = sizeof(HOG_ALPHABET_RANGES) / sizeof(HOG_ALPHABET_RANGES[0]);

const size_t HOG_MIN_LENGTH = 1;
const size_t HOG_MAX_LENGTH = UINT16_MAX;
