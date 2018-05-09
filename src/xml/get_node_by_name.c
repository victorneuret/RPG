/*
** EPITECH PROJECT, 2018
** xml
** File description:
** get_node_by_name
*/

#include <libxml/parser.h>

#include "str_utils.h"

xmlNode *get_node_by_name(xmlNode *root, const char *name)
{
	for (xmlNode *node = root->children; node; node = node->next) {
		if (str_eq((char *) node->name, name))
			return (node);
	}
	return (NULL);
}
