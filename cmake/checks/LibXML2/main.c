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

const char XPATH[]           = "/root/element";
const char ATTRIBUTE_KEY[]   = "key";
const char ATTRIBUTE_VALUE[] = "value";
const char TEXT[]            = "text";

int main()
{
  xmlInitParser();
  LIBXML_TEST_VERSION

  const xmlDocPtr doc = xmlParseMemory(DATA, strlen(DATA));
  assert(doc != NULL);

  const xmlXPathContextPtr xpath_ctx = xmlXPathNewContext(doc);
  assert(xpath_ctx != NULL);

  const xmlXPathObjectPtr xpath_obj = xmlXPathEvalExpression((const xmlChar*)XPATH, xpath_ctx);
  assert(xpath_obj != NULL);

  const xmlNodeSetPtr nodes = xpath_obj->nodesetval;
  assert(nodes->nodeNr == 1);

  const xmlNodePtr node = nodes->nodeTab[0];
  assert(node != NULL);

  const xmlAttrPtr attribute = xmlHasProp(node, (const xmlChar*)ATTRIBUTE_KEY);
  assert(attribute != NULL);

  const char* attribute_value = (const char*)xmlGetProp(node, (const xmlChar*)ATTRIBUTE_KEY);
  assert(attribute_value != NULL);
  assert(strcmp(attribute_value, ATTRIBUTE_VALUE) == 0);

  const char* text = (const char*)xmlNodeGetContent(node);
  assert(text != NULL);
  assert(strcmp(text, TEXT) == 0);

  xmlXPathFreeObject(xpath_obj);
  xmlXPathFreeContext(xpath_ctx);
  xmlFreeDoc(doc);
  xmlCleanupParser();

  return 0;
}
