/*
** EPITECH PROJECT, 2018
** xml
** File description:
** read_xml
*/

#include <libxml/parser.h>

#include <stdbool.h>

#include "xml.h"

// printf("desc: %s\n", desc);
// printf("name: %s\n", name);
// printf("level: %d\n", get_node_int(player_node, "level"));
// printf("health: %d\n", get_node_int(player_node, "health"));
bool parse_player(xmlNode *root)
{
	xmlNode *player_node = get_node_by_name(root, "player");
	char *desc = NULL;
	char *name = NULL;

	if (!player_node)
		return false;
	desc = get_prop(player_node, "desc");
	name = get_node_string(player_node, "name");
	free(desc);
	free(name);
	return true;
}

bool xml_exemple(void)
{
	xmlDoc *document = load_xml_file("test.xml");
	xmlNode *root;

	if (!document)
		return false;
	root = load_xml_node(document);
	if (!root)
		return false;
	if (!parse_player(root))
		return false;
	xmlFreeDoc(document);
	return true;
}
