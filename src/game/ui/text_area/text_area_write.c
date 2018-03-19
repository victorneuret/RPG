/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** text_area_write
*/

#include "text_area.h"

static void put_in_string(text_area_t *text_area, char c, win_t *win)
{
	int i = 0;

	for (; text_area->input_text[i] != '\0'; i++);
	if (c == '\b')
		text_area->input_text[i - 1] = '\0';
	if (my_strlen(text_area->input_text) >= text_area->nb_char_max)
		return;
	if (c >= ' ' && c <= '~')
		text_area->input_text[i] = c;
	else if (c == '\r') {
		if (text_area->func)
			text_area->func(win, text_area->input_text);
		for (int j = 0; text_area->input_text[j] != '\0'; j++)
			text_area->input_text[j] = '\0';
	}
	sfText_setString(text_area->text, text_area->input_text);
}

void text_area_write(win_t *win, sfEvent *event)
{
	for (text_area_t *tmp = win->game->ui->text_area; tmp;
		tmp = tmp->next) {
		if (tmp->active)
			put_in_string(tmp, event->text.unicode, win);
	}
}
