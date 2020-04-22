// HTTP old generation (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

#include <assert.h>
#include <libxml/parser.h>
#include <libxml/xpath.h>
#include <string.h>

const char DATA[] =
  "<?xml version=\"1.0\"?>\
    <root>\
      <element key=\"value\">text</element>\
    </root>\
  ";

int main()
{
  xmlInitParser();
  LIBXML_TEST_VERSION();

  xmlDocPtr doc = xmlParseMemory(DATA, strlen(DATA));
  assert(doc != NULL);

  xmlXPathContextPtr xpath_ctx = xmlXPathNewContext(doc);
  assert(xpath_ctx != NULL);

  xmlXPathObjectPtr xpath_obj = xmlXPathEvalExpression("/element", xpath_ctx);
  assert(xpath_obj != NULL);

  xmlXPathFreeObject(xpath_obj);
  xmlXPathFreeContext(xpath_ctx);
  xmlFreeDoc(doc);
  xmlCleanupParser();

  return 0;
}
