// HTTP old generation (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

// This file is intended to be used by generator only.

#if !defined(HOG_PROCESSOR_GENERATOR_GENERIC_OPTIONS_H)
#define HOG_PROCESSOR_GENERATOR_GENERIC_OPTIONS_H

#include <stdint.h>
#include <stdlib.h>

typedef struct {
  char from;
  char to;
} hog_alphabet_range_t;

extern const hog_alphabet_range_t HOG_ALPHABET_RANGES[];
extern const size_t               HOG_ALPHABET_RANGES_LENGTH;

extern const char   HOG_ALPHABET[];
extern const size_t HOG_ALPHABET_LENGTH;

enum {
  HOG_ALPHABET_INCLUDING_BYTES_INTO_RANGES,
  HOG_ALPHABET_EXCLUDING_BYTES_FROM_RANGES
};
typedef uint8_t hog_alphabet_mode_t;

extern const hog_alphabet_mode_t HOG_ALPHABET_MODE;

extern const size_t HOG_MIN_LENGTH;
extern const size_t HOG_MAX_LENGTH;

#endif // HOG_PROCESSOR_GENERATOR_GENERIC_OPTIONS_H
