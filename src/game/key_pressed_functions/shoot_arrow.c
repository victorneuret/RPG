/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** shoot_arrow
*/

#include "render_window.h"

void shoot_up(win_t *win)
{
	win->joystick->ry = -100;
	player_shoot(win, win->game->player);
}

void shoot_down(win_t *win)
{
	win->joystick->ry = 100;
	player_shoot(win, win->game->player);
}

void shoot_left(win_t *win)
{
	win->joystick->rx = -100;
	player_shoot(win, win->game->player);
}

void shoot_right(win_t *win)
{
	win->joystick->rx = 100;
	player_shoot(win, win->game->player);
}
