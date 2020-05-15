// Old generation HTTP (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

// This file is intended to be used by generator only.

#include "options.h"

// RFC 1945 - 3.1 HTTP Version.
// RFC 7230 - 2.6 Protocol Versioning.

const ogh_alphabet_range_t OGH_ALPHABET_RANGES[]      = {{'0', '9'}};
const size_t               OGH_ALPHABET_RANGES_LENGTH = sizeof(OGH_ALPHABET_RANGES) / sizeof(OGH_ALPHABET_RANGES[0]);

const char   OGH_ALPHABET[]      = {'.'};
const size_t OGH_ALPHABET_LENGTH = sizeof(OGH_ALPHABET) / sizeof(OGH_ALPHABET[0]);

const ogh_alphabet_mode_t OGH_ALPHABET_MODE = OGH_ALPHABET_INCLUDING_BYTES_INTO_RANGES;

const size_t OGH_MIN_LENGTH = 3;
const size_t OGH_MAX_LENGTH = 3;
