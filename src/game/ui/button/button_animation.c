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
	sfVector2f scale;

	for (buttons_t *tmp = win->game->ui->buttons; tmp; tmp = tmp->next) {
		if (tmp->game_state == win->game_state
			|| tmp->game_state == ALL)
			button_hover(win, tmp);
		scale = sfSprite_getScale(tmp->sprite);
		if (!tmp->reset_scale)
			continue;
		if (scale.x < 1) {
			scale.x += 0.01;
			scale.y += 0.01;
		}
		sfSprite_setScale(tmp->sprite, scale);
		if (scale.x >= 1)
			tmp->reset_scale = false;
	}
}

void update_button(buttons_t *button, win_t *win)
{
	sfFloatRect rect = sfSprite_getGlobalBounds(button->sprite);
	sfVector2f mouse = get_mouse_pos(win);

	for (buttons_t *tmp = button; tmp; tmp = tmp->next) {
		if (tmp->reset_scale)
			continue;
		if (mouse.x <= rect.left || mouse.x >= rect.left + rect.width
			|| mouse.y <= rect.top
			|| mouse.y >= rect.top + rect.height)
			tmp->reset_scale = true;
	}
}
