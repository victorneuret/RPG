/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** draw_buttons
*/

#include "buttons.h"

void draw_buttons(win_t *win)
{
	button_animation(win);
	for (buttons_t *btn = win->game->ui->buttons; btn; btn = btn->next) {
		if ((btn->game_state & win->game_state) == win->game_state
			|| btn->game_state == ALL)
			sfRenderWindow_drawSprite(win->sf_win, btn->sprite, 0);
	}
}
