/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** drawer
*/

#include <SFML/Graphics.h>

#include "render_window.h"

void draw(win_t *win, void *object, void (*draw_func)())
{
	draw_func(win->sf_win, object, NULL);
}
