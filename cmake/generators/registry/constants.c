// HTTP old generation (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

#include "constants.h"

#include <stdlib.h>

#include "print.h"

#define CONSTANT_PREFIX "  "
#define CONSTANT_TEMPLATE "\"%s\""
#define CONSTANT_TERMINATOR ",\n"

#define PRINT_SPACER_AND_CONSTANT(constant)           \
  PRINT_SPACER(CONSTANT_PREFIX, CONSTANT_TERMINATOR); \
  printf(CONSTANT_TEMPLATE, constant);

void print_constants(const xmlNodeSetPtr nodes)
{
  INITIALIZE_SPACERS();

  size_t nodes_length = nodes->nodeNr;

  for (size_t index = 0; index < nodes_length; index++) {
    const xmlNodePtr node = nodes->nodeTab[index];
    const char*      text = (const char*)xmlNodeGetContent(node);

    PRINT_SPACER_AND_CONSTANT(text);
  }

  PRINT_GLUE();

  PRINT_LENGTH(nodes_length);
  PRINT_GLUE();
}
