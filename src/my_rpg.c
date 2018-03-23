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
	switch (win->game_state) {
	case GAME: update_weather(win);
		update_particles(win, win->particle_manager); break;
	case TITLE: update_title_page(win); update_weather(win);
		update_particles(win, win->particle_manager); break;
	default: break;
	}
	update_button(win->game->ui->buttons, win);
	update_text_hover(win->game->ui->hover_text_button, win);
	update_popups(win->game->ui->popup_list);
}

static void render(win_t *win)
{
	switch (win->game_state) {
	case TITLE: sfRenderWindow_clear(win->sf_win, sfBlack);
		draw_particles(win); sfRenderWindow_drawSprite(win->sf_win,
		win->game->ui->title_page->earth, 0); break;
	case GAME: draw_particles(win); break;
	case PAUSE: sfRenderWindow_clear(win->sf_win, sfBlack); break;
	default: break;
	}
	draw_buttons(win);
	draw_text_hover_button(win->game->ui->hover_text_button, win);
	draw_text_area(win);
	draw_popups(win, win->game->ui->popup_list);
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
