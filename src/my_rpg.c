/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** Main game logic
*/

#include <stdbool.h>

#include "game.h"
#include "events.h"
#include "render.h"
#include "update.h"
#include "save.h"

static void update_clock(win_t *win)
{
	static sfClock *frame_clock = 0;

	if (!frame_clock) {
		frame_clock = sfClock_create();
		return;
	}
	win->dt = sfTime_asSeconds(sfClock_restart(frame_clock));
}

bool my_rpg_loop(win_t *win)
{
	if (!init_game(win))
		return false;
	while (sfRenderWindow_isOpen(win->sf_win)) {
		sfRenderWindow_clear(win->sf_win, sfBlack);
		if (!update(win))
			return false;
		process_events(win);
		render(win);
		sfRenderWindow_display(win->sf_win);
		update_clock(win);
	}
	unload_level(win->game->level);
	free_game(win->game);
	return true;
}
