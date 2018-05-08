/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** special_actions
*/

#include "render_window.h"
#include "inventory.h"

void plus(win_t *win)
{
	win->game->player->inventory->selected =
			(win->game->player->inventory->selected + 1) % 3;
	printf("%d\n", win->game->player->inventory->selected);
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
	printf("%d\n", win->game->player->inventory->selected);
	drop_item(win, win->game->player->inventory,
				win->game->player->inventory->selected);
}

void open_door(win_t *win)
{
	win->game->dungeon->door_open =
			(win->game->dungeon->door_open) ? false : true;
}
