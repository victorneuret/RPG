/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** parse_xml_inventory
*/

#include <stdbool.h>
#include <SFML/Graphics.h>

#include "libxml.h"
#include "xml.h"
#include "getnbr.h"
#include "inventory.h"
#include "texture.h"

static bool parse_xml_item(xmlNode *root, item_t *item,
			textures_t *texture, const char *item_name)
{
	xmlNode *weapon_node = get_node_by_name(root, item_name);
	textures_t *tmp = texture;


	if (!weapon_node || !item)
		return false;
	for (; tmp && !str_eq(tmp->name, item_name); tmp = tmp->next);
	item->name = get_node_string(weapon_node, "name");
	item->damages = get_node_float(weapon_node, "damages");
	item->delay = get_node_float(weapon_node, "delay");
	item->sprite = create_sprite(tmp->texture);
	item->pos = (sfVector2f){0, 0};
	sfSprite_setOrigin(item->sprite,
				(sfVector2f){ITEM_SIZE / 2, ITEM_SIZE / 2});
	item->droped = true;
	return true;
}

bool xml_item(item_t *item, textures_t *texture)
{
	xmlDoc *document = load_xml_file("config/weapons.xml");
	xmlNode *root;
	size_t i = 0;

	if (!document)
		return false;
	root = load_xml_node(document);
	if (!root)
		return false;
	for (i = 0; item_list[i]; i++) {
		if (!parse_xml_item(root, &item[i], texture, item_list[i]))
			return false;
	}
	xmlFreeDoc(document);
	return true;
}
