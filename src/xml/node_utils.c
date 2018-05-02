/*
** EPITECH PROJECT, 2018
** xml
** File description:
** node_utils
*/

#include <libxml/parser.h>

#include "xml.h"
#include "getnbr.h"

char *get_node_string(xmlNode *root, char *node_name)
{
	xmlNode *node = get_node_by_name(root, node_name);

	if (!node)
		return NULL;
	return ((char *) xmlNodeGetContent(node));
}

int get_node_int(xmlNode *root, char *node_name)
{
	xmlNode *node = get_node_by_name(root, node_name);
	int value = 0;
	char *string = NULL;

	if (!node)
		return 0;
	string = (char *) xmlNodeGetContent(node);
	value = getnbr(string);
	free(string);
	return (value);
}

char *get_prop(xmlNode *root, char *prop_name)
{
	return ((char *) xmlGetProp(root, (xmlChar *) prop_name));
}
