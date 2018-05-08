/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** door_action
*/

#include <stdint.h>

#include "render_window.h"
#include "render.h"
#include "inventory.h"
#include "xml.h"

void add_item(inventory_t *inventory, uint8_t place,
							item_type item_nb)
{
	for (size_t i = 0; i < INVENTORY_NB; i++) {
		if (!inventory->item[i].name) {
			inventory->item[i] = inventory->item_list[item_nb];
			return;
		}
	}
	inventory->item[place].droped = true;
	inventory->item[place] = inventory->item_list[item_nb];
}

void draw_inventory(win_t *win, item_t *item)
{
	sfVector2f pos = {1000, 1000};

	if (win->game_state != GAME)
		return;
	for (uint8_t i = 0; i < INVENTORY_NB; i++) {
		if (item[i].name) {
			sfSprite_setPosition(item[i].sprite, pos);
			render_object(win->sf_win, SPRITE, item[i].sprite);
		}
		pos.x += 100;
	}
}

void drop_item(inventory_t *inventory, uint8_t place)
{
	inventory->item[place].droped = true;
	inventory->item[place] = inventory->item[EMPTY];
}

inventory_t *init_inventory(win_t *win)
{
	inventory_t *inventory = malloc(sizeof(inventory_t));

	inventory->item_list = malloc(sizeof(item_t) * NB_ITEMS);
	inventory->item = malloc(sizeof(item_t) * INVENTORY_NB);
	if (!inventory->item_list || !inventory->item)
		return NULL;
	if (!xml_item(inventory->item_list, win->game->textures))
		return NULL;
	for (size_t i = 0; i < INVENTORY_NB; i++)
		inventory->item[i].name = NULL;
	return inventory;
}
