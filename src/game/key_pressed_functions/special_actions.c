/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** special_actions
*/

#include "render_window.h"
#include "inventory.h"
#include "inventory_list.h"

void switch_inventory(win_t *win)
{
	win->game->player->inventory->selected =
			get_next_inventory(win->game->player->inventory, 1);
}

void get_nearest_item(win_t *win)
{
	get_item(win, win->game->player->inventory, win->game->player->sprite,
									true);
}

void add_gun(win_t *win)
{
	static int i = GUN;

	nuke_enemies(win->game->enemy_list);
	if (!win->game->player->inventory->item_list[i].droped)
		i = (i + 1) % (NB_ITEMS - 1);
	add_item(win, win->game->player->inventory,
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
