/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** joystick_button_arrow
*/

#include "joystick.h"
#include "events.h"
#include "render_window.h"


void button_left(win_t *win)
{
	win->game->player->inventory->selected =
		(win->game->player->inventory->selected + 1) % INVENTORY_NB;

}

void button_right(win_t *win)
{
	win->game->player->inventory->selected =
		(win->game->player->inventory->selected + 1) % INVENTORY_NB;
}
