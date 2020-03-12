#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "constant.h"

#define CONSTANT OGHTTP_CONSTANT
#define GLUE ";"

#define PRINT(string) fputs(string, stdout)
#define PRINT_ERROR(string) fputs(string, stderr)

// -- constant --

static inline void print_constant()
{
  PRINT(CONSTANT);
}

// -- min state bits --

static inline int print_min_state_bits()
{
  size_t max_state = strlen(CONSTANT);
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
    PRINT_ERROR("max state is too big\n");
    return 1;
  }

  PRINT(min_state_bits);

  return 0;
}

int main()
{
  // -- constant --

  print_constant();
  PRINT(GLUE);

  // -- min state bits --

  int result = print_min_state_bits();
  if (result != 0) {
    return 1;
  }

  return 0;
}
