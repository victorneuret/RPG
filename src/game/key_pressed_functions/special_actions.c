/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** special_actions
*/

#include "render_window.h"
#include "inventory.h"

void add_gun(win_t *win)
{
	add_item(win->game->player->inventory,
				win->game->player->inventory->selected, GUN);
}

void drop_gun(win_t *win)
{
	drop_item(win->game->player->inventory,
				win->game->player->inventory->selected);
}

void open_door(win_t *win)
{
	win->game->dungeon->door_open =
			(win->game->dungeon->door_open) ? false : true;
}
