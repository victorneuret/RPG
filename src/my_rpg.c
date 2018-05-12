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

static void update_clock(win_t *win)
{
	static sfClock *frame_clock = 0;

	if (!frame_clock) {
		frame_clock = sfClock_create();
		return;
	}
	win->dt = sfTime_asSeconds(sfClock_restart(frame_clock));
}

#include "save.h"

bool my_rpg_loop(win_t *win)
{
	if (!init_game(win))
		return false;
	if (save_exist(win->game->save)) {
		puts("Found save");
		if (!open_save(win, win->game->save))
			puts("Corrupted save");
	}
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
	create_save(win, win->game->save);
	free_game(win->game);
	return true;
}
