// HTTP old generation (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

// This file is intended to be used by generator only.

#include "options.h"

const char* HOG_CONSTANTS[] = {
  // RFC 1945 - 8.1 GET.
  "GET",

  // RFC 1945 - 8.2 HEAD.
  "HEAD",

  // RFC 1945 - 8.3 POST.
  "POST"};

const size_t HOG_CONSTANTS_LENGTH = sizeof(HOG_CONSTANTS) / sizeof(HOG_CONSTANTS[0]);
