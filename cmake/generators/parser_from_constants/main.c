// Old generation HTTP (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

#include "alphabet.h"
#include "data.h"
#include "max_state.h"
#include "min_state_bits.h"
#include "next_state_by_last_symbols.h"
#include "prefix.h"

int main()
{
  print_data();

  // -- alphabet --

  size_t alphabet_length;
  init_alphabet(&alphabet_length);

  print_alphabet(alphabet_length);
  print_symbol_by_bytes(alphabet_length);

  // -- prefixes --

  size_t prefixes_length;

  int result = init_prefixes(&prefixes_length);
  if (result != 0) {
    return 1;
  }

  // -- max state --

  size_t max_state;
  init_max_state(&max_state, prefixes_length);

  print_max_state(max_state);

  // -- min state bits --

  result = print_min_state_bits(max_state);
  if (result != 0) {
    return 2;
  }

  // -- next state by last symbols --

  result = print_next_state_by_last_symbols(alphabet_length, max_state);
  if (result != 0) {
    return 3;
  }

  return 0;
}
