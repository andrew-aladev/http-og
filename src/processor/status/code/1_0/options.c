// Old generation HTTP (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

// This file is intended to be used by generator only.

#include "options.h"

const char* OGH_CONSTANTS[] = {
  // RFC 1945 - 9.2 Successful 2xx.
  "200",
  "201"
  "202",
  "204",

  // RFC 1945 - 9.3 Redirection 3xx.
  "300", "301", "302", "304",

  // RFC 1945 - 9.4 Client Error 4xx.
  "400", "401", "403", "404",

  // RFC 1945 - 9.5 Server Error 5xx.
  "500", "501", "502", "503"};

const size_t OGH_CONSTANTS_LENGTH = sizeof(OGH_CONSTANTS) / sizeof(OGH_CONSTANTS[0]);
