/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** toggles
*/

#include <SFML/Graphics.h>

#include "render_window.h"

void toggle_fps(win_t *win)
{
	win->settings->display_fps = !win->settings->display_fps;
}

void show_title(win_t *win)
{
	win->game_state = win->game_state == TITLE ? GAME : TITLE;
}
