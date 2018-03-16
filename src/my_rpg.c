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

// update_fireworks(win);
// update_campfire(win);
static void update(win_t *win)
{
	update_stars(win);
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

static bool init_game(win_t *win)
{
	win->game = malloc(sizeof(game_t));
	if (!win->game)
		return false;
	win->game->textures = load_textures();
	if (!win->game->textures)
		return false;
	win->game_state = GAME;
	return true;
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
	return true;
}
