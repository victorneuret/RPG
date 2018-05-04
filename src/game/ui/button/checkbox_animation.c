/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** checkbox_animation
*/

#include "buttons.h"

void checkbox_click_animation(checkbox_t *checkbox)
{
	sfSprite_setColor(get_checkbox_sprite(checkbox), checkbox->color);
}

static void checkbox_hover(win_t *win, checkbox_t *checkb)
{
	sfSprite *sprite = get_checkbox_sprite(checkb);
	sfFloatRect rect = sfSprite_getGlobalBounds(sprite);
	sfVector2f mouse = get_mouse_pos(win);

	if (mouse.x >= rect.left && mouse.x <= rect.left + rect.width
		&& mouse.y >= rect.top && mouse.y <= rect.top + rect.height
		&& sfClock_getElapsedTime(checkb->checkbox_clock).microseconds
		/ 60000 > 2) {
		sfSprite_setColor(sprite, checkb->hover_color);
		checkb->hover = true;
		return;
	}
	checkb->hover = false;
	sfSprite_setColor(sprite, checkb->color);
}

void checkbox_animation(win_t *win)
{
	sfVector2f scale;
	sfSprite *sprite;

	for (checkbox_t *tmp = win->game->ui->checkbox; tmp; tmp = tmp->next) {
		sprite = get_checkbox_sprite(tmp);
		if (tmp->game_state == win->game_state
			|| tmp->game_state == ALL)
			checkbox_hover(win, tmp);
		scale = sfSprite_getScale(sprite);
		if (!tmp->reset_scale)
			continue;
		if (scale.x < 1) {
			scale.x += 0.01;
			scale.y += 0.01;
		}
		sfSprite_setScale(sprite, scale);
		if (scale.x >= 1)
			tmp->reset_scale = false;
	}
}

void update_checkbox(checkbox_t *checkbox, win_t *win)
{
	sfFloatRect rect;
	sfVector2f mouse = get_mouse_pos(win);
	sfSprite *sprite;

	for (checkbox_t *tmp = checkbox; tmp; tmp = tmp->next) {
		sprite = get_checkbox_sprite(tmp);
		if (tmp->reset_scale)
			continue;
		rect = sfSprite_getGlobalBounds(sprite);
		if (mouse.x <= rect.left || mouse.x >= rect.left + rect.width
			|| mouse.y <= rect.top
			|| mouse.y >= rect.top + rect.height)
			tmp->reset_scale = true;
	}
}
