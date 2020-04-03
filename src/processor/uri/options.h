// HTTP old generation (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

// This file is intended to be used by generator only.

#if !defined(HOG_PROCESSOR_URI_OPTIONS_H)
#define HOG_PROCESSOR_URI_OPTIONS_H

#include <stdlib.h>

extern const char   HOG_ALPHABET[];
extern const size_t HOG_ALPHABET_LENGTH;

typedef struct {
  char from;
  char to;
} hog_alphabet_range;

extern const hog_alphabet_range HOG_ALPHABET_RANGES[];
extern const size_t             HOG_ALPHABET_RANGES_LENGTH;

extern const size_t HOG_MIN_LENGTH;
extern const size_t HOG_MAX_LENGTH;

#endif // HOG_PROCESSOR_URI_OPTIONS_H
