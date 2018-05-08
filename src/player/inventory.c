/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** door_action
*/

#include "render_window.h"
#include "inventory.h"
#include "xml.h"

inventory_t *init_inventory(win_t *win)
{
	inventory_t *inventory = malloc(sizeof(inventory_t));
	inventory->item_list = malloc(sizeof(item_t) * NB_ITEMS);

	if (!xml_item(inventory->item_list, win->game->textures))
		return NULL;
	return inventory;
}
