// HTTP old generation (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

// This file is intended to be used by generator only.

#include "options.h"

const char* HOG_CONSTANTS[] = {
  // RFC 1945 - 10 Header Field Definitions.
  "Allow",
  "Authorization",
  "Content-Encoding",
  "Content-Length",
  "Content-Type",
  "Date",
  "Expires",
  "From",
  "If-Modified-Since",
  "Last-Modified",
  "Location",
  "Pragma",
  "Referer",
  "Server",
  "User-Agent",
  "WWW-Authenticate"};

const size_t HOG_CONSTANTS_LENGTH = sizeof(HOG_CONSTANTS) / sizeof(HOG_CONSTANTS[0]);
