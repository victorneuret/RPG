/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** special_actions
*/

#include "render_window.h"

void open_door(win_t *win)
{
	win->game->dungeon->door_open =
			(win->game->dungeon->door_open) ? false : true;
}
