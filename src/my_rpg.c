/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** Main game logic
*/

#include "my_rpg.h"

static void update_clock(win_t *win)
{
	static sfClock *frame_clock = 0;

	if (!frame_clock) {
		frame_clock = sfClock_create();
		return;
	}
	win->dt = sfTime_asSeconds(sfClock_restart(frame_clock));
}

static void draw(win_t *win)
{
	if (win->settings->display_fps)
		draw_fps(win);
}

bool my_rpg_loop(win_t *win)
{
	while (sfRenderWindow_isOpen(win->sf_win)) {
		sfRenderWindow_clear(win->sf_win, (sfColor) {0, 41, 58, 0});
		draw(win);
		process_event(win);
		sfRenderWindow_display(win->sf_win);
		update_clock(win);
	}
	return true;
}
