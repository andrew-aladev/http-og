// HTTP old generation (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

#include "file.h"
#include "print.h"

int main(int argc, const char** argv)
{
  if (argc != 5) {
    PRINT_ERROR("required arguments: file path, ns uri, xpath, mode");
    return 1;
  }

  const char* file_path = argv[1];
  const char* ns_uri    = argv[2];
  const char* xpath     = argv[3];
  const char* mode      = argv[4];

  int result = print_data_from_file(file_path, ns_uri, xpath, mode);
  if (result != 0) {
    return 2;
  }

  return 0;
}
