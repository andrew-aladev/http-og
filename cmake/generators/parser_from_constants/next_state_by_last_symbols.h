// Old generation HTTP (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

#if !defined(NEXT_STATE_BY_LAST_SYMBOLS_H)
#define NEXT_STATE_BY_LAST_SYMBOLS_H

#include <stdint.h>
#include <stdlib.h>

int print_next_state_by_last_symbols(const uint8_t* alphabet_ptr, const uint8_t* symbol_by_bytes_ptr, size_t alphabet_length, size_t max_state);

#endif // NEXT_STATE_BY_LAST_SYMBOLS_H
