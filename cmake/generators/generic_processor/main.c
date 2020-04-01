// HTTP old generation (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

#include "alphabet.h"
#include "data.h"
#include "min_state_bits.h"

int main()
{
  print_data();

  // -- alphabet --

  print_allowed_bytes();

  // -- min state bits --

  int result = print_min_state_bits();
  if (result != 0) {
    return 1;
  }

  return 0;
}
