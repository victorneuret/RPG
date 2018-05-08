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
#include "nb_utils.h"

void add_item(inventory_t *inventory, uint8_t place,
							item_type item_nb)
{
	if (!inventory->item_list[item_nb].droped)
		return;
	for (size_t i = 0; i < INVENTORY_NB; i++) {
		if (!inventory->item[i] || inventory->item[i]->droped) {
			inventory->item[i] = &inventory->item_list[item_nb];
			inventory->item[i]->droped = false;
			inventory->item[i]->pos = (sfVector2f) {0, 0};
			sfSprite_setRotation(inventory->item[i]->sprite, 0);
			return;
		}
	}
	inventory->item[place]->droped = true;
	inventory->item_list[item_nb].droped = false;
	inventory->item[place] = &inventory->item_list[item_nb];
}

void draw_inventory(win_t *win, inventory_t *inventory)
{
	sfVector2f pos = {1000, 1000};

	for (uint8_t i = 0; i < INVENTORY_NB; i++) {
		if (inventory->item[i] && !inventory->item[i]->droped) {
			sfSprite_setPosition(inventory->item[i]->sprite, pos);
			render_object(win->sf_win,
					SPRITE, inventory->item[i]->sprite);
		}
		pos.x += 100;
	}
	for (uint8_t i = 0; i < (NB_ITEMS - 1); i++) {
		if (inventory->item_list[i].droped &&
				(inventory->item_list[i].pos.x != 0 &&
				inventory->item_list[i].pos.y != 0)) {
			render_object(win->sf_win, SPRITE,
					inventory->item_list[i].sprite);
		}
	}
}

void drop_item(win_t *win, inventory_t *inventory, uint8_t place)
{
	sfVector2f player_pos;

	if (!inventory->item[place] || !inventory->item[place]->name)
		return;
	player_pos = sfSprite_getPosition(win->game->player->sprite);
	player_pos.y += 66;
	inventory->item[place]->droped = true;
	inventory->item[place]->pos = player_pos;
	sfSprite_setPosition(inventory->item[place]->sprite,
						inventory->item[place]->pos);
	sfSprite_setRotation(inventory->item[place]->sprite, rand_int(0, 360));
	inventory->item[place] = NULL;
}

inventory_t *init_inventory(win_t *win)
{
	inventory_t *inventory = malloc(sizeof(inventory_t));

	inventory->item_list = malloc(sizeof(item_t) * NB_ITEMS);
	inventory->item = malloc(sizeof(item_t*) * INVENTORY_NB);
	inventory->selected = 0;
	if (!inventory->item_list || !inventory->item)
		return NULL;
	if (!xml_item(inventory->item_list, win->game->textures))
		return NULL;
	for (size_t i = 0; i < INVENTORY_NB; i++) {
		inventory->item[i] = malloc(sizeof(item_t));
		inventory->item[i]->droped = true;
		inventory->item[i]->name = NULL;
	}
	return inventory;
}
