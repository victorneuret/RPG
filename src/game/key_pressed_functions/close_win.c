/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** close_win
*/

#include <SFML/Graphics.h>

#include "window/render_window.h"

bool close_win(win_t *win)
{
	sfRenderWindow_close(win->sf_win);
	return true;
}
