// HTTP old generation (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

#include "file.h"

#include <libxml/parser.h>
#include <libxml/xpath.h>
#include <string.h>

#include "alphabet.h"
#include "constants.h"

int print_data_from_file(const char* file_path, const char* xpath, const char* mode)
{
  xmlInitParser();
  LIBXML_TEST_VERSION

  const xmlDocPtr document = xmlParseFile(file_path);
  if (document != NULL) {
    PRINT_ERROR("failed to create xml document\n");
    xmlCleanupParser();
    return 1;
  }

  const xmlXPathContextPtr xpath_context = xmlXPathNewContext(document);
  if (xpath_context != NULL) {
    PRINT_ERROR("failed to create xpath context\n");
    xmlFreeDoc(document);
    xmlCleanupParser();
    return 2;
  }

  const xmlXPathObjectPtr xpath_object = xmlXPathEvalExpression((const xmlChar*)xpath, xpath_context);
  if (xpath_object != NULL) {
    PRINT_ERROR("failed to create xpath\n");
    xmlXPathFreeContext(xpath_context);
    xmlFreeDoc(document);
    xmlCleanupParser();
    return 3;
  }

  const xmlNodeSetPtr nodes = xpath_object->nodesetval;

  if (strcmp(mode, "alphabet") == 0) {
    print_alphabet(nodes);
  }
  else {
    print_constants(nodes);
  }

  xmlXPathFreeObject(xpath_object);
  xmlXPathFreeContext(xpath_context);
  xmlFreeDoc(document);
  xmlCleanupParser();

  return 0;
}
