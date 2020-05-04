// HTTP old generation (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

// This file is intended to be used by generator only.

#include "options.h"

// RFC 1945 - B Tolerant Applications.
// RFC 7230 - 3.5 Message Parsing Robustness.

const char*  HOG_CONSTANTS[]      = {"\n", "\r\n"};
const size_t HOG_CONSTANTS_LENGTH = sizeof(HOG_CONSTANTS) / sizeof(HOG_CONSTANTS[0]);
