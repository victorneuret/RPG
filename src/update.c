/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** update
*/

#include <SFML/Graphics.h>

#include "intro.h"
#include "enemies.h"
#include "options.h"
#include "render_window.h"
#include "particle_updater.h"

static void update_general(win_t *win)
{
	update_particles(win, win->particle_manager);
	update_text_hover(win->game->ui->hover_text_button, win);
	update_popups(win->game->ui->popup_list);
}

bool update(win_t *win)
{
	switch (win->game_state) {
	case INTRO:
		if (!update_intro(win, win->intro))
			return false;
		break;
	case GAME:
		update_player(win, win->game->player);
		update_enemies(win, win->game->enemy_list, win->game->sounds,
					&win->game->dungeon->door_open);
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
	update_general(win);
	return true;
}
