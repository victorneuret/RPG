/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** Main game logic
*/

#include <stdbool.h>

#include "render.h"
#include "my_rpg.h"
#include "game.h"
#include "intro.h"
#include "events.h"
#include "particle_updater.h"
#include "particle_drawer.h"
#include "fps.h"
#include "options.h"
#include "music_management.h"
#include "hud.h"
#include "inventory.h"

static void update_clock(win_t *win)
{
	static sfClock *frame_clock = 0;

	if (!frame_clock) {
		frame_clock = sfClock_create();
		return;
	}
	win->dt = sfTime_asSeconds(sfClock_restart(frame_clock));
}

static bool update(win_t *win)
{
	switch (win->game_state) {
	case INTRO:
		if (!update_intro(win, win->intro))
			return false;
		break;
	case GAME:
		update_player(win, win->game->player);
		break;
	case TITLE:
		update_title_page(win);
		break;
	case OPTION:
		update_title_page(win);
		update_options_page(win);
		break;
	default: break;
	}
	update_particles(win, win->particle_manager);
	update_text_hover(win->game->ui->hover_text_button, win);
	update_popups(win->game->ui->popup_list);
	return true;
}

static void render_game(win_t *win)
{
	switch (win->game_state) {
		case GAME:
			draw_level(win->sf_win, win->game->level, win);
			draw_player(win, win->game->player);
			draw_inventory(win, win->game->player->inventory->item);
			render_transition(win);
			break;
		case OPTION: break;
		default: break;
	}
	draw_particles(win);
	draw_buttons(win);
	draw_checkbox(win);
	draw_text_hover_button(win->game->ui->hover_text_button, win);
	draw_text_area(win);
	render_object(win->sf_win, SPRITE,
					win->game->ui->title_page->overlay);
	if (win->game_state == GAME)
			display_hp_bar(win);
	draw_popups(win, win->game->ui->popup_list);
	if (win->settings->display_fps)
		draw_fps(win);
}

static void render(win_t *win)
{
	switch (win->game_state) {
		case TITLE:
		case OPTION:
			render_object(win->sf_win, SPRITE,
					win->game->ui->title_page->background);
			render_object(win->sf_win, SPRITE,
					win->game->ui->title_page->menu_paper);
			render_object(win->sf_win, SPRITE,
					win->game->ui->title_page->options);
			break;
		case INTRO:
			render_intro(win, win->intro);
			break;
		default: break;
	}
	music_management(win->game->sounds, win->game_state);
	render_game(win);
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
