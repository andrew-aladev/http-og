// HTTP old generation (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

#include "constants.h"

#include <stdlib.h>

#include "print.h"

#define CONSTANT_TEMPLATE "\"%s\""

#define PRINT_CONSTANT(constant) printf(CONSTANT_TEMPLATE, constant);

void print_constants(const xmlNodeSetPtr nodes, size_t nodes_length)
{
  INITIALIZE_SPACERS();

  for (size_t index = 0; index < nodes_length; index++) {
    const xmlNodePtr node = nodes->nodeTab[index];
    const char*      text = (const char*)xmlNodeGetContent(node);

    PRINT_SPACER();
    PRINT_CONSTANT(text);
  }
}
