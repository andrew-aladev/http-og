// Old generation HTTP (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

#if !defined(ALPHABET_H)
#define ALPHABET_H

#include <stdlib.h>

void init_alphabet(size_t* alphabet_length_ptr);
void print_alphabet(size_t alphabet_length);
void print_symbol_by_bytes(size_t alphabet_length);

#endif // ALPHABET_H
