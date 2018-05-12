/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** inventory
*/

#include <stdint.h>

#include "render_window.h"
#include "render.h"
#include "inventory.h"
#include "xml.h"
#include "nb_utils.h"

void get_item(win_t *win, inventory_t *inventory,
						sfSprite *player, bool pick_up)
{
	const sfFloatRect rect = sfSprite_getGlobalBounds(player);
	item_t *item_list = inventory->item_list;
	sfFloatRect item_rect;

	if (!item_list)
		return;
	for (int8_t i = 0; i < (NB_ITEMS - 1); i++) {
		if (!item_list[i].droped || item_list[i].pos.x == 0)
			continue;
		item_rect = sfSprite_getGlobalBounds(item_list[i].sprite);
		if (!sfFloatRect_intersects(&rect, &item_rect, &item_rect))
			continue;
		inventory->display_message = true;
		if (pick_up)
			add_item(win, inventory, inventory->selected, i);
		return;
	}
	inventory->display_message = false;
}

void add_item(win_t *win, inventory_t *inventory, uint8_t place,
							uint8_t item_nb)
{
	if (!inventory->item_list[item_nb].droped)
		return;
	for (uint8_t i = 0; i < INVENTORY_NB; i++) {
		if (!inventory->item[i] || inventory->item[i]->droped) {
			inventory->item[i] = &inventory->item_list[item_nb];
			inventory->item[i]->droped = false;
			inventory->item[i]->pos = (sfVector2f) {0, 0};
			sfSprite_setRotation(inventory->item[i]->sprite, 0);
			inventory->selected = i;
			return;
		}
	}
	if (str_eq(inventory->item[place]->name, "Bubble"))
		return;
	inventory->item[place]->droped = true;
	inventory->item[place]->pos = win->game->player->pos;
	sfSprite_setPosition(inventory->item[place]->sprite,
						inventory->item[place]->pos);
	inventory->item_list[item_nb].droped = false;
	inventory->item[place] = &inventory->item_list[item_nb];
}

void drop_item(win_t *win, inventory_t *inventory, uint8_t place)
{
	sfVector2f player_pos;

	if (!inventory->item[place] || !inventory->item[place]->name ||
				str_eq(inventory->item[place]->name, "Bubble"))
		return;
	player_pos = sfSprite_getPosition(win->game->player->sprite);
	player_pos.y += 66;
	inventory->item[place]->droped = true;
	inventory->item[place]->pos = player_pos;
	sfSprite_setPosition(inventory->item[place]->sprite,
						inventory->item[place]->pos);
	sfSprite_setRotation(inventory->item[place]->sprite, rand_int(0, 360));
	inventory->item[place] = NULL;
	inventory->selected = get_next_inventory(inventory, 1);
}

uint8_t get_next_inventory(inventory_t *inventory, int8_t negative)
{
	int8_t select = inventory->selected;

	select = (select + (1 * negative)) % 3;
	select = select < 0 ? 2 : select;
	while (select != inventory->selected) {
		if (inventory->item[select] && !inventory->item[select]->droped)
			break;
		select = (select + (1 * negative)) % 3;
		select = select < 0 ? 2 : select;
	}
	return select;
}
