#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "constant.h"

int main()
{
  // Output constant itself.
  printf("%s;", OGHTTP_CONSTANT);

  size_t max_state = strlen(OGHTTP_CONSTANT) + 1;
  char*  min_state_bits;

  if (max_state <= UINT8_MAX) {
    min_state_bits = "8";
  }
  else if (max_state <= UINT16_MAX) {
    min_state_bits = "16";
  }
  else if (max_state <= UINT32_MAX) {
    min_state_bits = "32";
  }
  else {
    // Max state is too big.
    return 1;
  }

  // Output minimal state type.
  fputs(min_state_bits, stdout);

  return 0;
}
