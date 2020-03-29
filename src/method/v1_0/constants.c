// HTTP old generation (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

// This file is intended to be used by generator only.

#include "constants.h"

// HTTP/1.0 RFC 1945

const char* HOG_CONSTANTS[] = {
  "GET",
  "HEAD",
  "POST"};

const size_t HOG_CONSTANTS_LENGTH = sizeof(HOG_CONSTANTS) / sizeof(HOG_CONSTANTS[0]);
