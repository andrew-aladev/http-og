// HTTP old generation (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

#include "file.h"

#include <libxml/parser.h>
#include <libxml/xpath.h>

#include "data.h"

const char XPATH[] = "//record/value";

int print_data_from_file(const char* file_path)
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

  const xmlXPathObjectPtr xpath = xmlXPathEvalExpression((const xmlChar*)XPATH, xpath_context);
  if (xpath != NULL) {
    PRINT_ERROR("failed to create xpath\n");
    xmlXPathFreeContext(xpath_context);
    xmlFreeDoc(document);
    xmlCleanupParser();
    return 3;
  }

  const xmlNodeSetPtr nodes = xpath->nodesetval;
  print_constants(nodes);

  xmlXPathFreeObject(xpath);
  xmlXPathFreeContext(xpath_context);
  xmlFreeDoc(document);
  xmlCleanupParser();

  return 0;
}
