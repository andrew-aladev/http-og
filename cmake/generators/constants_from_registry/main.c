// HTTP old generation (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

#include "file.h"
#include "print.h"

int main(int argc, const char** argv)
{
  if (argc != 3) {
    PRINT_ERROR("required arguments: file path, xpath");
    return 1;
  }

  const char* file_path = argv[1];
  const char* xpath     = argv[2];

  int result = process_file(file_path, xpath);
  if (result != 0) {
    return 2;
  }

  return 0;
}
