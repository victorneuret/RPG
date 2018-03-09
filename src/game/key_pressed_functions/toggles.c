/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** toggles
*/

#include <SFML/Graphics.h>

#include "window/render_window.h"

void toggle_fps(win_t *win)
{
	win->settings->display_fps = !win->settings->display_fps;
}
