// HTTP old generation (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

#include "alphabet.h"

#include <stdint.h>
#include <stdlib.h>

#include "print.h"

#define ALPHABET_MAX_LENGTH UINT8_MAX + 1

#define PRINT_SPACER_AND_CONSTANT(constant)           \
  PRINT_SPACER(CONSTANT_PREFIX, CONSTANT_TERMINATOR); \
  printf(CONSTANT_TEMPLATE, constant);

int print_alphabet(const xmlNodeSetPtr nodes)
{
  bool* alphabet = malloc(ALPHABET_MAX_LENGTH);
  if (alphabet == NULL) {
    PRINT_ERROR("failed to allocate memory for alphabet\n");
    return 1;
  }

  INITIALIZE_SPACERS();

  size_t nodes_length = nodes->nodeNr;

  for (size_t index = 0; index < nodes_length; index++) {
    const xmlNodePtr node = nodes->nodeTab[index];
    const char*      text = (const char*)xmlNodeGetContent(node);

    PRINT_SPACER_AND_CONSTANT(text);
  }

  free(alphabet);

  return 0;
}
