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
	sfFloatRect rect = sfText_getGlobalBounds(tmp->unselected);
	sfVector2f mouse = get_mouse_pos(win);
	float i = 0;
	char str[tmp->elements + 1];

	str[0] = '\0';
	if (mouse.x >= rect.left && mouse.x <= rect.left + rect.width
		&& mouse.y >= rect.top && mouse.y <= rect.top + rect.height &&
		tmp->hover) {
		i = mouse.x / (float) (rect.width /
			(float) tmp->elements) - 10;
		i = i < 1 ? 0 : round(i);
		for (uint8_t j = 0; j < i; j++) {
			str[j] = '\'';
			str[j + 1] = '\0';
		}
		sfText_setString(tmp->selected, str);
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
