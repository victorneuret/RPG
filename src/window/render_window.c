/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** Window functions
*/

#include <stdlib.h>

#include "settings.h"

#include "utils/my_calloc.h"
#include "window/render_window.h"

win_t *create_window(size_t width, size_t height, settings_t *settings)
{
	win_t *win = my_calloc(1, sizeof(win_t));
	sfVideoMode mode = {width, height, 32};

	if (!win || !settings)
		return 0;
	win->width = width;
	win->height = height;
	win->dt = 0;
	win->sf_win = sfRenderWindow_create(mode, "My RPG",
					sfClose | sfFullscreen, NULL);
	win->timer = sfClock_create();
	if (!win->sf_win || !win->timer) {
		free(win);
		return 0;
	}
	sfRenderWindow_setFramerateLimit(win->sf_win,
					settings->fps_limit);
	return win;
}
