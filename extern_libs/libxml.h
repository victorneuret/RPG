/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** libxml
*/

#pragma once

#define XMLPUBFUN

typedef enum {
	XML_ELEMENT_NODE = 1,
	XML_ATTRIBUTE_NODE = 2,
	XML_TEXT_NODE = 3,
	XML_CDATA_SECTION_NODE = 4,
	XML_ENTITY_REF_NODE = 5,
	XML_ENTITY_NODE = 6,
	XML_PI_NODE = 7,
	XML_COMMENT_NODE = 8,
	XML_DOCUMENT_NODE = 9,
	XML_DOCUMENT_TYPE_NODE = 10,
	XML_DOCUMENT_FRAG_NODE = 11,
	XML_NOTATION_NODE = 12,
	XML_HTML_DOCUMENT_NODE = 13,
	XML_DTD_NODE = 14,
	XML_ELEMENT_DECL = 15,
	XML_ATTRIBUTE_DECL = 16,
	XML_ENTITY_DECL = 17,
	XML_NAMESPACE_DECL = 18,
	XML_XINCLUDE_START = 19,
	XML_XINCLUDE_END = 20,
	XML_DOCB_DOCUMENT_NODE = 21
} xmlElementType;

typedef unsigned char xmlChar;
typedef struct _xmlNs xmlNs;

typedef struct _xmlNode xmlNode;
struct _xmlNode {
	void *_private;
	xmlElementType type;
	const xmlChar *name;
	struct _xmlNode *children;
	struct _xmlNode *last;
	struct _xmlNode *parent;
	struct _xmlNode *next;
	struct _xmlNode *prev;
	struct _xmlDoc *doc;
	xmlNs *ns;
	xmlChar *content;
	struct _xmlAttr *properties;
	xmlNs *nsDef;
	void *psvi;
	unsigned short line;
	unsigned short extra;
};
typedef struct _xmlDoc xmlDoc;
typedef xmlNode *xmlNodePtr;
typedef xmlDoc *xmlDocPtr;

xmlDocPtr xmlParseFile(const char *filename);
xmlNodePtr xmlDocGetRootElement(const xmlDoc *doc);
void xmlFreeDoc(xmlDocPtr cur);
xmlChar *xmlNodeGetContent(const xmlNode *cur);
xmlChar *xmlGetProp(const xmlNode *node, const xmlChar *name);
