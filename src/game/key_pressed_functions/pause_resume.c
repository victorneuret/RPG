/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** pause_resume
*/

#include <SFML/Graphics.h>

#include "change_state.h"
#include "render_window.h"
#include "stats_menu.h"

void pause_game(win_t *win)
{
	if (win->game_state == PAUSE)
		change_state(win, GAME);
	else if (win->game_state == GAME)
		change_state(win, PAUSE);
}

void stats_game(win_t *win)
{
	if (win->game_state == STATS)
		change_state(win, GAME);
	else if (win->game_state == GAME) {
		update_stat_menu(win->game->stats_menu, win->game->player);
		change_state(win, STATS);
	}
}
