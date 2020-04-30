// HTTP old generation (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

#include "alphabet.h"

#include <stdint.h>
#include <stdlib.h>

#include "print.h"

#define ALPHABET_MAX_LENGTH UINT8_MAX + 1

#define BYTE_TEMPLATE "'%c'"

#define PRINT_SPACER_AND_BYTE(byte) \
  PRINT_SPACER();                   \
  printf(BYTE_TEMPLATE, byte);

int print_alphabet(const xmlNodeSetPtr nodes)
{
  bool* alphabet = malloc(ALPHABET_MAX_LENGTH);
  if (alphabet == NULL) {
    PRINT_ERROR("failed to allocate memory for alphabet\n");
    return 1;
  }

  char byte;

  for (byte = 0; byte < ALPHABET_MAX_LENGTH; byte++) {
    alphabet[byte] = false;
  }

  INITIALIZE_SPACERS();

  for (size_t index = 0; index < nodes->nodeNr; index++) {
    const xmlNodePtr node = nodes->nodeTab[index];
    const char*      text = (const char*)xmlNodeGetContent(node);

    for (size_t jndex = 0; jndex < strlen(text); jndex++) {
      byte = text[jndex];

      if (!alphabet[byte]) {
        PRINT_SPACER_AND_BYTE(byte);

        alphabet[byte] = true;
      }
    }
  }

  free(alphabet);

  return 0;
}
