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

static void update(win_t *win)
{
	static sfClock *timer;
	static uint16_t index = 0;
	const sfColor colors[] = {
		sfRed, sfGreen,
		sfBlue, sfYellow,
		sfMagenta, sfCyan
	};
	uint32_t current_time = timer ? sfTime_asMilliseconds(
				sfClock_getElapsedTime(timer)) : 0;
	sfVector2f pos = (sfVector2f) {rand_int(0, win->width),
					rand_int(0, win->height)};

	if (!timer)
		timer = sfClock_create();
	if (current_time >= 200) {
		create_explosion(win, 100, pos, colors[(++index) % 6]);
		sfClock_restart(timer);
	}
	update_particles(win, win->particle_manager);
}

static void render(win_t *win)
{
	if (win->game_state == GAME) {
	} else if (win->game_state == PAUSE) {
		sfRenderWindow_clear(win->sf_win, sfBlack);
	}
	draw_particles(win);
	if (win->settings->display_fps)
		draw_fps(win);
}

bool my_rpg_loop(win_t *win)
{
	win->game_state = GAME;
	while (sfRenderWindow_isOpen(win->sf_win)) {
		sfRenderWindow_clear(win->sf_win, (sfColor) {25, 25, 25, 255});
		process_events(win);
		update(win);
		render(win);
		sfRenderWindow_display(win->sf_win);
		update_clock(win);
	}
	return true;
}
