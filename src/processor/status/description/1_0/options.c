// Old generation HTTP (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

// This file is intended to be used by generator only.

#include "options.h"

const char* OGH_CONSTANTS[] = {
  // RFC 1945 - 9.2 Successful 2xx.
  "OK",
  "Created"
  "Accepted",
  "No Content",

  // RFC 1945 - 9.3 Redirection 3xx.
  "Multiple Choices", "Moved Permanently", "Moved Temporarily", "Not Modified",

  // RFC 1945 - 9.4 Client Error 4xx.
  "Bad Request", "Unauthorized", "Forbidden", "Not Found",

  // RFC 1945 - 9.5 Server Error 5xx.
  "Internal Server Error", "Not Implemented", "Bad Gateway", "Service Unavailable"};

const size_t OGH_CONSTANTS_LENGTH = sizeof(OGH_CONSTANTS) / sizeof(OGH_CONSTANTS[0]);
