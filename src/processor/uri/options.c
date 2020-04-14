// HTTP old generation (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

// This file is intended to be used by generator only.

#include "options.h"

#include <stdint.h>

const char HOG_ALPHABET[] = {
  // RFC 3986 gen-delims.
  ':',
  '/',
  '?',
  '#',
  '[',
  ']',
  '@',

  // RFC 3986 sub-delims.
  '!',
  '$',
  '&',
  '\'',
  '(',
  ')',
  '*',
  '+',
  ',',
  ';',
  '=',

  // RFC 3986 unreserved.
  '-',
  '.',
  '_',
  '~',

  // RFC 3986 pct-encoded.
  '%',

  // There are several symbols invalid for RFC 3986 but used often in real world.
  // These symbols are described as unsafe in old RFC 1738.
  // See "scripts/request-collector" research.
  '\\',
  '{',
  '}',
  '<',
  '>',
  '|',
  '`',
  '^',
  '"'};

const size_t HOG_ALPHABET_LENGTH = sizeof(HOG_ALPHABET) / sizeof(HOG_ALPHABET[0]);

// RFC 3986 digits and letters.

const hog_alphabet_range HOG_ALPHABET_RANGES[]      = {{'a', 'z'}, {'A', 'Z'}, {'0', '9'}};
const size_t             HOG_ALPHABET_RANGES_LENGTH = sizeof(HOG_ALPHABET_RANGES) / sizeof(HOG_ALPHABET_RANGES[0]);

const size_t HOG_MIN_LENGTH = 1;
const size_t HOG_MAX_LENGTH = UINT16_MAX;
