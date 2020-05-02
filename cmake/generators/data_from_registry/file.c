// HTTP old generation (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

#include "file.h"

#include <libxml/HTMLparser.h>
#include <libxml/parser.h>
#include <libxml/xpath.h>
#include <string.h>

#include "alphabet.h"
#include "constants.h"
#include "print.h"

static inline int print_data(const xmlXPathObjectPtr xpath_object, const char* mode)
{
  const xmlNodeSetPtr nodes        = xpath_object->nodesetval;
  size_t              nodes_length = nodes->nodeNr;

  if (nodes_length == 0) {
    PRINT_ERROR("can't find nodes for xpath");
    return 1;
  }

  if (strcmp(mode, "constants") == 0) {
    print_constants(nodes, nodes_length);
    return 0;
  }

  if (print_alphabet(nodes, nodes_length) != 0) {
    return 2;
  }

  return 0;
}

int print_data_from_file(const char* file_path, const char* xpath, const char* mode)
{
  xmlInitParser();
  LIBXML_TEST_VERSION

  const htmlDocPtr document = htmlParseFile(file_path, NULL);
  if (document == NULL) {
    PRINT_ERROR("failed to parse HTML file");
    xmlCleanupParser();
    return 1;
  }

  const xmlXPathContextPtr xpath_context = xmlXPathNewContext(document);
  if (xpath_context == NULL) {
    PRINT_ERROR("failed to create xpath context");
    xmlFreeDoc(document);
    xmlCleanupParser();
    return 2;
  }

  const xmlXPathObjectPtr xpath_object = xmlXPathEvalExpression((const xmlChar*)xpath, xpath_context);
  if (xpath_object == NULL) {
    PRINT_ERROR("failed to create xpath");
    xmlXPathFreeContext(xpath_context);
    xmlFreeDoc(document);
    xmlCleanupParser();
    return 3;
  }

  int result = print_data(xpath_object, mode);

  xmlXPathFreeObject(xpath_object);
  xmlXPathFreeContext(xpath_context);
  xmlFreeDoc(document);
  xmlCleanupParser();

  if (result != 0) {
    return 4;
  }

  return 0;
}
