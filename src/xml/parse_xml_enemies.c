/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** parse_xml_enemies
*/

#include "libxml.h"
#include "xml.h"
#include "enemies.h"
#include "nb_utils.h"

static bool parse_xml_enemies(xmlNode *root, enemy_t *enemy, const char *name,
			enemy_type_t type)
{
	xmlNode *enemy_node = get_node_by_name(root, name);

	if (!enemy_node || !enemy)
		return false;
	enemy->type = type;
	enemy->hp_max = get_node_int(enemy_node, "health");
	enemy->attack = get_node_int(enemy_node, "damages");
	enemy->speed = get_node_float(enemy_node, "speed");
	enemy->hp = enemy->hp_max;
	enemy->pos = (sfVector2f) {0, 0};
	enemy->sprite = NULL;
	return true;
}

enemy_t **xml_enemies(enemy_t **enemies)
{
	xmlDoc *document = load_xml_file("config/enemies.xml");
	xmlNode *root;

	enemies = malloc(sizeof(enemy_t*) * (ENEMIES_NB + 1));
	if (!document || !enemies)
		return NULL;
	root = load_xml_node(document);
	if (!root)
		return NULL;
	for (uint8_t i = 0; enemies_name[i]; i++) {
		enemies[i] = malloc(sizeof(enemy_t));
		if (!parse_xml_enemies(root, enemies[i], enemies_name[i], i))
			return NULL;
		enemies[i + 1] = NULL;
	}
	xmlFreeDoc(document);
	return enemies;
}
