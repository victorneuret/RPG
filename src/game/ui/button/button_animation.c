/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** button_animation
*/

#include "buttons.h"

void button_click_animation(buttons_t *button)
{
	sfSprite_setColor(button->sprite, button->color);
}

static void button_hover(win_t *win, buttons_t *button)
{
	sfFloatRect rect = sfSprite_getGlobalBounds(button->sprite);
	sfVector2f mouse = get_mouse_pos(win);

	if (mouse.x >= rect.left && mouse.x <= rect.left + rect.width
		&& mouse.y >= rect.top && mouse.y <= rect.top + rect.height
		&& sfClock_getElapsedTime(button->button_clock).microseconds
		/ 60000 > 2) {
		sfSprite_setColor(button->sprite, button->hover_color);
		return;
	}
	sfSprite_setColor(button->sprite, button->color);
}

void button_animation(win_t *win)
{
	for (buttons_t *tmp = win->game->ui->buttons; tmp; tmp = tmp->next) {
		if (tmp->game_state == win->game_state
			|| tmp->game_state == ALL)
			button_hover(win, tmp);
	}
}
