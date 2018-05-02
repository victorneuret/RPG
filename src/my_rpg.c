/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** Main game logic
*/

#include "render.h"
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

static void update(win_t *win)
{
	switch (win->game_state) {
	case GAME:
		update_player(win, win->game->player);
		break;
	case TITLE:
		update_title_page(win);
		update_weather(win);
		break;
	default: break;
	}
	update_particles(win, win->particle_manager);
	update_text_hover(win->game->ui->hover_text_button, win);
	update_popups(win->game->ui->popup_list);
}

static void render(win_t *win)
{
	sfRenderWindow_clear(win->sf_win, sfBlack);
	draw_particles(win);
	switch (win->game_state) {
	case TITLE:
		render_object(win->sf_win, SPRITE,
					win->game->ui->title_page->earth);
		break;
	case GAME:
		draw_player(win, win->game->player);
		break;
	case PAUSE: break;
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
	print_dungeon(win->game->dungeon);
	while (sfRenderWindow_isOpen(win->sf_win)) {
		sfRenderWindow_clear(win->sf_win, (sfColor) {25, 25, 25, 255});
		update(win);
		process_events(win);
		render(win);
		sfRenderWindow_display(win->sf_win);
		update_clock(win);
	}
	free_game(win->game);
	return true;
}
