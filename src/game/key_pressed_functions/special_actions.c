/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** special_actions
*/

#include "render_window.h"
#include "inventory.h"

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

void switch_inventory(win_t *win)
{
	win->game->player->inventory->selected =
			get_next_inventory(win->game->player->inventory, 1);
}

void add_gun(win_t *win)
{
	static int i = GUN;

	if (!win->game->player->inventory->item_list[i].droped)
		i = (i + 1) % 3;
	add_item(win->game->player->inventory,
				win->game->player->inventory->selected, i);
}

void drop_gun(win_t *win)
{
	drop_item(win, win->game->player->inventory,
				win->game->player->inventory->selected);
}

void open_door(win_t *win)
{
	win->game->dungeon->door_open =
			(win->game->dungeon->door_open) ? false : true;
}
