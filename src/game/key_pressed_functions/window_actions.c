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

bool toggle_fullscreen(win_t *win)
{
	const bool fullscreen = !win->settings->fullscreen;
	const sfVideoMode vm = fullscreen ? (sfVideoMode) {1920, 1080, 32}
					: (sfVideoMode) {1600, 900, 32};
	const sfUint32 style = fullscreen ? sfFullscreen : sfClose;

	win->settings->fullscreen = fullscreen;
	sfRenderWindow_close(win->sf_win);
	sfRenderWindow_destroy(win->sf_win);
	win->sf_win = sfRenderWindow_create(vm, WINDOW_TITLE, style, NULL);
	if (!win->sf_win)
		return false;
	sfRenderWindow_setFramerateLimit(win->sf_win,
					win->settings->fps_limit);
	return true;
}
