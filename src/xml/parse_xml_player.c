/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** parse_xml_player
*/

#include "libxml.h"
#include "xml.h"
#include "getnbr.h"
#include "player.h"

static bool parse_xml_player(xmlNode *root, player_t *player)
{
	xmlNode *hp_node = get_node_by_name(root, "hp");
	xmlNode *xp_node = get_node_by_name(root, "xp");

	if (!hp_node || !xp_node)
		return false;
	player->hp->value = get_node_int(hp_node, "start");
	player->hp->max_value = get_node_int(hp_node, "start");
	player->hp->mult = get_node_float(hp_node, "multiplicator");
	player->xp->value = 0;
	player->xp->max_value = get_node_int(xp_node, "start");
	player->xp->mult = get_node_float(xp_node, "multiplicator");
	player->level = 1;
	player->skill_point = 0;
	return true;
}

bool xml_player(player_t *player)
{
	static bool first = true;
	xmlDoc *document = load_xml_file("config/player.xml");
	xmlNode *root;

	if (!first) {
		free(player->xp);
		free(player->hp);
	}
	player->hp = malloc(sizeof(bar_t));
	player->xp = malloc(sizeof(bar_t));
	if (!document || !player->hp || !player->xp)
		return false;
	root = load_xml_node(document);
	if (!root)
		return false;
	if (!parse_xml_player(root, player))
		return false;
	xmlFreeDoc(document);
	first = false;
	return true;
}
