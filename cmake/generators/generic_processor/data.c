// HTTP old generation (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

#include "data.h"

#include "options.h"
#include "print.h"

void print_data()
{
  PRINT_LENGTH(HOG_MIN_LENGTH);
  PRINT_GLUE();

  PRINT_LENGTH(HOG_MAX_LENGTH);
  PRINT_GLUE();
}
