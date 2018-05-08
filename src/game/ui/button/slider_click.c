/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** slider_click
*/

#include <SFML/Graphics.h>
#include <math.h>

#include "slider.h"
#include "render_window.h"

static void slider_click_pressed_action(win_t *win, slider_t *tmp)
{
	float i = 0;
	char *str = NULL;
	sfFloatRect rect = sfText_getGlobalBounds(tmp->unselected);
	sfVector2f mouse = get_mouse_pos(win);

	if (mouse.x >= rect.left && mouse.x <= rect.left + rect.width
		&& mouse.y >= rect.top && mouse.y <= rect.top + rect.height &&
		tmp->hover) {
		i = (mouse.x - rect.left) /
			(float) (rect.width / (float) tmp->elements);
		i = i < 0.4 ? 0 : ceil(i);
		i = i > 8 ? 8 : i;
		if (i != 0)
			str = get_string_from_char('\'', i);
		sfText_setString(tmp->selected, str);
		free(str);
	}
}

void slider_click_pressed(win_t *win, const sfEvent *event)
{
	slider_t *tmp = win->game->ui->slider;

	if (event->mouseButton.button != sfMouseLeft ||
		(tmp->game_state & win->game_state) != win->game_state)
		return;
	for (; tmp; tmp = tmp->next) {
		if (tmp->game_state == win->game_state)
			slider_click_pressed_action(win, tmp);
	}
}
