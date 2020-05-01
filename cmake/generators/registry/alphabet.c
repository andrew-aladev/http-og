// HTTP old generation (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

#include "alphabet.h"

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "print.h"

#define ALPHABET_MAX_LENGTH UINT8_MAX + 1

#define BYTE_TEMPLATE "'%c'"

#define PRINT_BYTE(byte) printf(BYTE_TEMPLATE, byte);

int print_alphabet(const xmlNodeSetPtr nodes, size_t nodes_length)
{
  bool* alphabet = malloc(ALPHABET_MAX_LENGTH);
  if (alphabet == NULL) {
    PRINT_ERROR("failed to allocate memory for alphabet");
    return 1;
  }

  uint8_t byte = 0;

  while (true) {
    alphabet[byte] = false;

    if (byte == UINT8_MAX) {
      break;
    }
    byte++;
  }

  INITIALIZE_SPACERS();

  for (size_t index = 0; index < nodes_length; index++) {
    const xmlNodePtr node = nodes->nodeTab[index];
    const char*      text = (const char*)xmlNodeGetContent(node);

    for (size_t jndex = 0; jndex < strlen(text); jndex++) {
      byte = text[jndex];

      if (!alphabet[byte]) {
        PRINT_SPACER();
        PRINT_BYTE(byte);

        alphabet[byte] = true;
      }
    }
  }

  free(alphabet);

  return 0;
}
