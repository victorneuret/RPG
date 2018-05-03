/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** Window functions
*/

#include <stdlib.h>

#include "settings.h"

#include "my_calloc.h"
#include "render_window.h"
#include "particle.h"
#include "joystick.h"

static sfView *init_view(win_t *win)
{
	sfView *view = sfView_create();

	if (!view)
		return NULL;
	sfView_reset(view, (sfFloatRect) {0, 0, WIN_MAX_W, WIN_MAX_H});
	sfRenderWindow_setView(win->sf_win, view);
	return view;
}

win_t *create_window(size_t width, size_t height, settings_t *settings)
{
	win_t *win = my_calloc(1, sizeof(win_t));
	const sfVideoMode vm = settings->fullscreen
					? (sfVideoMode) {1920, 1080, 32}
					: (sfVideoMode) {width, height, 32};
	const sfUint32 style = settings->fullscreen ? sfFullscreen : sfClose;

	if (!win || !settings)
		return 0;
	win->size.x = width;
	win->size.y = height;
	win->dt = 0;
	win->sf_win = sfRenderWindow_create(vm, "My RPG", style, NULL);
	win->timer = sfClock_create();
	win->view = init_view(win);
	win->particle_manager = my_calloc(1, sizeof(particle_manager_t));
	if (!win->sf_win || !win->timer || !win->particle_manager) {
		free(win);
		return 0;
	}
	sfRenderWindow_setFramerateLimit(win->sf_win, settings->fps_limit);
	return win;
}
