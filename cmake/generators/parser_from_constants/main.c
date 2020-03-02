#include <stdio.h>
#include <stdlib.h>

#include "constants.h"

#define CONSTANTS_LENGTH sizeof(OGHTTP_CONSTANTS) / sizeof(OGHTTP_CONSTANTS[0])
#define CONSTANT_PREFIX "    "
#define CONSTANT_TEMPLATE "\"%s\""
#define CONSTANT_TERMINATOR ",\n"
#define GLUE ";"

#define PRINT(string) fputs(string, stdout)

void print_constants()
{
  for (size_t index = 0; index < CONSTANTS_LENGTH; index++) {
    if (index != 0) {
      PRINT(CONSTANT_TERMINATOR);
      PRINT(CONSTANT_PREFIX);
    }
    printf(CONSTANT_TEMPLATE, OGHTTP_CONSTANTS[index]);
  }
}

int main()
{
  print_constants();
  PRINT(GLUE);

  PRINT("8");

  return 0;
}
