/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** draw_text_area
*/

#include "render.h"
#include "text_area.h"

void draw_text_area(win_t *win)
{
	for (text_area_t *tmp = win->game->ui->text_area; tmp;
		tmp = tmp->next) {
		if (tmp->game_state != win->game_state)
			continue;
		render_object(win->sf_win, RECTANGLE, tmp->box);
		render_object(win->sf_win, TEXT, tmp->text);
		if (tmp->input_text[0] == '\0')
			render_object(win->sf_win, TEXT, tmp->label);
	}
}
