/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** hp_bar
*/

#include <stdbool.h>

#include "player.h"
#include "hud.h"
#include "color_utils.h"

void display_hp_bar(win_t *win)
{
	sfRenderWindow_drawRectangleShape(win->sf_win,
		win->game->player->hud->hp_bar, 0);
}
