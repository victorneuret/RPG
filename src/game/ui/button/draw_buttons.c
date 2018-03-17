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
	for (buttons_t *tmp = win->game->ui->buttons; tmp; tmp = tmp->next) {
		if (tmp->game_state == win->game_state
			|| tmp->game_state == ALL)
			sfRenderWindow_drawSprite(win->sf_win, tmp->sprite, 0);
	}
}
