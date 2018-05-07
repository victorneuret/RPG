/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** draw_buttons
*/

#include "render.h"
#include "buttons.h"

void draw_slider(win_t *win, slider_t *slider)
{
	slider_t *tmp = slider;

	for (slider_t *tmp = slider; tmp; tmp = tmp->next) {
		if ((tmp->game_state & win->game_state) != win->game_state
			&& tmp->game_state != ALL)
			continue;
		render_object(win->sf_win, TEXT, tmp->unselected);
		//render_object(win->sf_win, TEXT, slider[i].unselected);
	}
}

void draw_checkbox(win_t *win)
{
	checkbox_animation(win);
	for (checkbox_t *btn = win->game->ui->checkbox; btn; btn = btn->next) {
		if ((btn->game_state & win->game_state) != win->game_state
			&& btn->game_state != ALL)
			continue;
		if (btn->value)
			render_object(win->sf_win, SPRITE, btn->selected);
		else
			render_object(win->sf_win, SPRITE, btn->unselected);
	}
}

void draw_buttons(win_t *win)
{
	button_animation(win);
	for (buttons_t *btn = win->game->ui->buttons; btn; btn = btn->next) {
		if ((btn->game_state & win->game_state) == win->game_state
			|| btn->game_state == ALL)
			render_object(win->sf_win, SPRITE, btn->sprite);
	}
}
