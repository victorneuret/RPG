/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** destroy CSFML
*/

#include "window/destroy.h"

void destroy_window(win_t *win)
{
	sfClock_destroy(win->timer);
	sfRenderWindow_destroy(win->sf_win);
	free(win);
}
