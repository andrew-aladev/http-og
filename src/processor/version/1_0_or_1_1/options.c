// Old generation HTTP (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

// This file is intended to be used by generator only.

#include "options.h"

// RFC 1945 - 3.1 HTTP Version.
// RFC 7230 - 2.6 Protocol Versioning.

const char*  OGH_CONSTANTS[]      = {"1.0", "1.1"};
const size_t OGH_CONSTANTS_LENGTH = sizeof(OGH_CONSTANTS) / sizeof(OGH_CONSTANTS[0]);
