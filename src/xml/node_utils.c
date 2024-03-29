/*
** EPITECH PROJECT, 2018
** xml
** File description:
** node_utils
*/

#include "libxml.h"
#include "xml.h"
#include "getnbr.h"

char *get_node_string(xmlNode *root, const char *node_name)
{
	xmlNode *node = get_node_by_name(root, node_name);

	if (!node)
		return NULL;
	return ((char *) xmlNodeGetContent(node));
}

int get_node_int(xmlNode *root, const char *node_name)
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

float get_node_float(xmlNode *root, const char *node_name)
{
	xmlNode *node = get_node_by_name(root, node_name);
	float value = 0;
	char *string = NULL;

	if (!node)
		return 0;
	string = (char *) xmlNodeGetContent(node);
	value = str_to_float(string);
	free(string);
	return (value);
}

char *get_prop(xmlNode *root, const char *prop_name)
{
	return ((char *) xmlGetProp(root, (xmlChar *) prop_name));
}
