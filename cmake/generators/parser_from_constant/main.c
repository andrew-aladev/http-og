#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "constant.h"

#define GLUE ";"

#define PRINT(string) fputs(string, stdout)

void print_constant()
{
  PRINT(OGHTTP_CONSTANT);
}

int print_min_state_bits()
{
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

  PRINT(min_state_bits);

  return 0;
}

int main()
{
  print_constant();
  PRINT(GLUE);

  if (print_min_state_bits() != 0) {
    return 1;
  }

  return 0;
}
