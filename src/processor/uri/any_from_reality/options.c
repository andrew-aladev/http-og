// HTTP old generation (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

// This file is intended to be used by generator only.

#include "options.h"

// RFC 3986 - 2.3 Unreserved Characters.

const hog_alphabet_range_t HOG_ALPHABET_RANGES[]      = {{'a', 'z'}, {'A', 'Z'}, {'0', '9'}};
const size_t               HOG_ALPHABET_RANGES_LENGTH = sizeof(HOG_ALPHABET_RANGES) / sizeof(HOG_ALPHABET_RANGES[0]);

const char HOG_ALPHABET[] = {
  // RFC 3986 - 2.2 Reserved Characters.
  ':',
  '/',
  '?',
  '#',
  '[',
  ']',
  '@',

  // RFC 3986 - 2.2 Reserved Characters.
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

  // RFC 3986 - 2.3 Unreserved Characters.
  '-',
  '.',
  '_',
  '~',

  // RFC 3986 - 2.1 Percent-Encoding.
  '%',

  // There are several symbols invalid for RFC 3986 but used often in real world.
  // These symbols are described as unsafe in old RFC 1738.
  // See "request-collector" research.
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

const hog_alphabet_mode_t HOG_ALPHABET_MODE = HOG_ALPHABET_INCLUDING_BYTES_INTO_RANGES;

const size_t HOG_MIN_LENGTH = 1;
const size_t HOG_MAX_LENGTH = UINT16_MAX;
