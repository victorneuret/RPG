/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** draw_text_area
*/

#include "text_area.h"

void draw_text_area(win_t *win)
{
	for (text_area_t *tmp = win->game->ui->text_area; tmp;
		tmp = tmp->next) {
		if (tmp->game_state != win->game_state)
			continue;
		sfRenderWindow_drawRectangleShape(win->sf_win, tmp->box, 0);
		sfRenderWindow_drawText(win->sf_win, tmp->text, 0);
		if (tmp->input_text[0] == '\0')
			sfRenderWindow_drawText(win->sf_win, tmp->label, 0);
	}
}
