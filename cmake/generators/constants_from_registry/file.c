// HTTP old generation (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

#include "file.h"

#include <libxml/HTMLparser.h>
#include <libxml/parser.h>
#include <libxml/xpath.h>

#include "constants.h"
#include "print.h"

int process_file(const char* file_path, const char* xpath)
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

  const xmlNodeSetPtr nodes        = xpath_object->nodesetval;
  int                 nodes_length = nodes->nodeNr;

  int result = print_constants(nodes, nodes_length);

  xmlXPathFreeObject(xpath_object);
  xmlXPathFreeContext(xpath_context);
  xmlFreeDoc(document);
  xmlCleanupParser();

  if (result != 0) {
    return 4;
  }

  return 0;
}
