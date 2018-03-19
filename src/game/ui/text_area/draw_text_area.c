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
		sfRenderWindow_drawRectangleShape(win->sf_win, tmp->box, 0);
		sfRenderWindow_drawText(win->sf_win, tmp->text, 0);
	}
}
