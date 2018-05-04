/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** dir_arrow
*/

#include "render_window.h"

void keyboard_shoot(win_t *win)
{
	player_shoot(win, win->game->player);
}

void shoot_up(win_t *win)
{
	win->joystick->ry = -100;
}

void shoot_down(win_t *win)
{
	win->joystick->ry = 100;
}

void shoot_left(win_t *win)
{
	win->joystick->rx = -100;
}

void shoot_right(win_t *win)
{
	win->joystick->rx = 100;
}
