// HTTP old generation (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

#include "max_state.h"

#include <stdint.h>

#include "options.h"
#include "print.h"

int check_max_state()
{
  if (HOG_MAX_LENGTH > UINT32_MAX) {
    PRINT_ERROR("max length is too big\n");
    return 1;
  }

  return 0;
}
