#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "constant_generator.h"

int main()
{
  // Output constant itself.
  printf("%s;", OGHTTP_CONSTANT);

  size_t max_state = strlen(OGHTTP_CONSTANT) + 1;
  char*  min_state_t;

  if (max_state <= UINT8_MAX) {
    min_state_t = "uint8_t";
  }
  else if (max_state <= UINT16_MAX) {
    min_state_t = "uint16_t";
  }
  else if (max_state <= UINT32_MAX) {
    min_state_t = "uint32_t";
  }
  else {
    // Max state is too big.
    return 1;
  }

  // Output minimal state type.
  puts(min_state_t);

  return 0;
}
