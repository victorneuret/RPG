/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** dir_arrow
*/

#include "render_window.h"

void arrow_up(win_t *win)
{
	win->joystick->ly = -100;
}

void arrow_down(win_t *win)
{
	win->joystick->ly = 100;
}

void arrow_left(win_t *win)
{
	win->joystick->lx = -100;
}

void arrow_right(win_t *win)
{
	win->joystick->lx = 100;
}
