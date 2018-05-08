/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** parse_xml_player
*/

#include <libxml/parser.h>

#include "xml.h"
#include "getnbr.h"
#include "player.h"

static bool parse_xml_player(xmlNode *root, player_t *player)
{
	xmlNode *hp_node = get_node_by_name(root, "hp");
	xmlNode *xp_node = get_node_by_name(root, "xp");

	if (!hp_node || !xp_node)
		return false;
	player->hp->hp = get_node_int(hp_node, "start");
	player->hp->max_hp = get_node_int(hp_node, "start");
	player->hp->hp_mult = get_node_float(hp_node, "multiplicator");
	player->xp = get_node_int(xp_node, "start");
	player->xp_multi = get_node_float(xp_node, "multiplicator");
	return true;
}

bool xml_player(player_t *player)
{
	player->hp = malloc(sizeof(hp_t));
	xmlDoc *document = load_xml_file("config/player.xml");
	xmlNode *root;

	if (!document || !player->hp)
		return false;
	root = load_xml_node(document);
	if (!root)
		return false;
	if (!parse_xml_player(root, player))
		return false;
	xmlFreeDoc(document);
	return true;
}
