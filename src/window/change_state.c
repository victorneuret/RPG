/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** change_state
*/

#include "render_window.h"

void change_state(win_t *win, game_status state)
{
	win->game_state = state;
	sfView_reset(win->view, (sfFloatRect) {0, 0, WIN_MAX_W, WIN_MAX_H});
}
