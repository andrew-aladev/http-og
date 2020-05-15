// Old generation HTTP (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

// This file is intended to be used by generator only.

#include "options.h"

const char* OGH_CONSTANTS[] = {
  // RFC 1945 - 8.1 GET.
  "GET",

  // RFC 1945 - 8.2 HEAD.
  "HEAD",

  // RFC 1945 - 8.3 POST.
  "POST"};

const size_t OGH_CONSTANTS_LENGTH = sizeof(OGH_CONSTANTS) / sizeof(OGH_CONSTANTS[0]);
