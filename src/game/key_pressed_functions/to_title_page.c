/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** to_title_page
*/

#include "change_state.h"
#include "render_window.h"
#include "music.h"

void to_title_page(win_t *win)
{
	play_sfx(win->game->sounds, SWITCH_TITLE);
	if (win->game_state == TITLE)
		close_win(win);
	change_state(win, TITLE);
}
