/*
** EPITECH PROJECT, 2018
** xml
** File description:
** load_xml
*/

#include <libxml/parser.h>

#include "str_utils.h"

xmlDoc *load_xml_file(char *file_name)
{
	xmlDoc *document = xmlParseFile(file_name);

	if (!document) {
		puterr("Invalid file and/or syntax!\n");
		return NULL;
	}
	return document;
}

xmlNode *load_xml_node(xmlDoc *document)
{
	xmlNode *root;

	root = xmlDocGetRootElement(document);
	if (!root) {
		puterr("Invalid syntax! (Root not found)\n");
		xmlFreeDoc(document);
		return NULL;
	}
	return root;
}
