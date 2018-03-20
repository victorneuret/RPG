/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** Main game logic
*/

#include "my_rpg.h"
#include "game.h"

static void update_clock(win_t *win)
{
	static sfClock *frame_clock = 0;

	if (!frame_clock) {
		frame_clock = sfClock_create();
		return;
	}
	win->dt = sfTime_asSeconds(sfClock_restart(frame_clock));
}

// update_fireworks(win);
// update_campfire(win);
// update_stars(win);
static void update(win_t *win)
{
	update_weather(win);
	update_button(win->game->ui->buttons, win);
	update_particles(win, win->particle_manager);
}

static void render(win_t *win)
{
	if (win->game_state == GAME) {
	} else if (win->game_state == PAUSE) {
		sfRenderWindow_clear(win->sf_win, sfBlack);
	}
	draw_particles(win);
	draw_buttons(win);
	draw_text_area(win);
	if (win->settings->display_fps)
		draw_fps(win);
}

bool my_rpg_loop(win_t *win)
{
	if (!init_game(win))
		return false;
	while (sfRenderWindow_isOpen(win->sf_win)) {
		sfRenderWindow_clear(win->sf_win, (sfColor) {25, 25, 25, 255});
		process_events(win);
		update(win);
		render(win);
		sfRenderWindow_display(win->sf_win);
		update_clock(win);
	}
	free_game(win->game);
	return true;
}
