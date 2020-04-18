// HTTP old generation (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

#include "data.h"

#include "options.h"
#include "print.h"

#define LENGTH_TEMPLATE "%zu"

static inline void print_length(size_t length)
{
  printf(LENGTH_TEMPLATE, length);
  PRINT_GLUE();
}

void print_data()
{
  print_length(HOG_MIN_LENGTH);
  print_length(HOG_MAX_LENGTH);
}
