/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** draw_buttons
*/

#include <SFML/Graphics.h>

#include "render.h"
#include "buttons.h"
#include "mouse_utils.h"

static void slider_animation(win_t *win, slider_t *slider)
{
	slider_t *tmp = slider;
	sfFloatRect rect = sfText_getGlobalBounds(tmp->unselected);
	sfVector2f mouse = get_mouse_pos(win);

	if ((tmp->game_state & win->game_state) != win->game_state
			&& tmp->game_state != ALL)
			return;
	for (slider_t *tmp = slider; tmp; tmp = tmp->next) {
		if (mouse.x >= rect.left && mouse.x <= rect.left + rect.width
		&& mouse.y >= rect.top && mouse.y <= rect.top + rect.height) {
			sfText_setColor(tmp->unselected,
				(sfColor){0, 0, 0, 50});
			tmp->hover = true;
		} else {
			sfText_setColor(tmp->unselected,
				(sfColor){0, 0, 0, 25});
			tmp->hover = false;
		}
	}
}

void draw_slider(win_t *win, slider_t *slider)
{
	slider_t *tmp = slider;

	slider_animation(win, slider);
	for (; tmp; tmp = tmp->next) {
		if ((tmp->game_state & win->game_state) != win->game_state
			&& tmp->game_state != ALL)
			continue;
		render_object(win->sf_win, TEXT, tmp->selected);
		render_object(win->sf_win, TEXT, tmp->unselected);
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
