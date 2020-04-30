// HTTP old generation (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

#include "constants.h"

#include <stdlib.h>

#include "print.h"

#define CONSTANT_TEMPLATE "\"%s\""

#define PRINT_SPACER_AND_CONSTANT(constant) \
  PRINT_SPACER();                           \
  printf(CONSTANT_TEMPLATE, constant);

void print_constants(const xmlNodeSetPtr nodes)
{
  INITIALIZE_SPACERS();

  for (size_t index = 0; index < nodes->nodeNr; index++) {
    const xmlNodePtr node = nodes->nodeTab[index];
    const char*      text = (const char*)xmlNodeGetContent(node);

    PRINT_SPACER_AND_CONSTANT(text);
  }
}
