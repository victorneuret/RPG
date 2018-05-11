/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** render
*/

#include "npc.h"
#include "fps.h"
#include "intro.h"
#include "render.h"
#include "render_window.h"
#include "particle_drawer.h"
#include "music_management.h"
#include "stats_menu.h"

void render_object(sfRenderWindow *sf_win, shape_type type, void *obj_ptr)
{
	const sfFloatRect screen = (sfFloatRect) {0, 0, WIN_MAX_W, WIN_MAX_H};
	sfFloatRect obj_rect = {0};
	sfFloatRect inter = {0};

	if (type < 0 || type >= SHAPE_COUNT)
		return;
	obj_rect = shape_list[type].get_global_bounds(obj_ptr);
	if (!sfFloatRect_intersects(&obj_rect, &screen, &inter))
		return;
	shape_list[type].draw_shape(sf_win, obj_ptr, NULL);
}

static void render_general(win_t *win)
{
	draw_particles(win);
	draw_buttons(win);
	draw_checkbox(win);
	draw_slider(win, win->game->ui->slider);
	draw_text_hover_button(win->game->ui->hover_text_button, win);
	draw_text_area(win);
	render_object(win->sf_win, SPRITE, win->game->ui->title_page->overlay);
	if (win->game_state == GAME) {
		display_hp_bar(win);
		display_xp_bar(win);
	}
	draw_popups(win, win->game->ui->popup_list);
	if (win->settings->display_fps)
		draw_fps(win);
}

static void render_game(win_t *win)
{
	switch (win->game_state) {
	case GAME:
		draw_level(win->sf_win, win->game->level, win);
		draw_inventory(win, win->game->player->inventory);
		draw_npc(win, win->game->npc);
		draw_enemies(win->sf_win, win->game->enemy_list);
		draw_player(win, win->game->player);
		render_transition(win);
		break;
	case OPTION: break;
	default: break;
	}
	render_general(win);
}

void render(win_t *win)
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
	case STATS:
		draw_stat_menu(win, win->game->stats_menu);
		draw_skill_tree(win, win->game->stats_menu);
		break;
	default: break;
	}
	music_management(win->game->sounds, win->game_state);
	render_game(win);
}
