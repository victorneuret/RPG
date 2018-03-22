/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** to_title_page
*/

#include "render_window.h"

void to_title_page(win_t *win)
{
	if (win->game_state == TITLE)
		close_win(win);
	win->game_state = TITLE;
}
