/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** checkbox_click
*/

#include "buttons.h"

static void checkbox_click_released_action(win_t *win, checkbox_t *checkbox)
{
	sfFloatRect rect = sfSprite_getGlobalBounds(
		get_checkbox_sprite(checkbox));
	sfVector2f mouse = get_mouse_pos(win);

	if (mouse.x >= rect.left && mouse.x <= rect.left + rect.width
		&& mouse.y >= rect.top && mouse.y <= rect.top + rect.height) {
		checkbox->value = checkbox->value ? false : true;
		play_sfx(win->game->sounds, CLICK);
		if (checkbox->func)
			checkbox->func(win, checkbox);
		checkbox_click_animation(checkbox);
		sfClock_restart(checkbox->checkbox_clock);
		checkbox->reset_scale = true;
	}
}

void checkbox_click_released(win_t *win, const sfEvent *event)
{
	if (event->mouseButton.button != sfMouseLeft)
		return;
	for (checkbox_t *tmp = win->game->ui->checkbox; tmp; tmp = tmp->next) {
		if (tmp->game_state == win->game_state
			|| tmp->game_state == ALL)
			checkbox_click_released_action(win, tmp);
	}
}

static void checkbox_click_pressed_action(win_t *win, checkbox_t *checkbox)
{
	sfFloatRect rect;
	sfVector2f mouse = get_mouse_pos(win);
	sfVector2f scale = (sfVector2f) {0.9, 0.9};

	rect = sfSprite_getGlobalBounds(get_checkbox_sprite(checkbox));
	if (mouse.x >= rect.left && mouse.x <= rect.left + rect.width
		&& mouse.y >= rect.top && mouse.y <= rect.top + rect.height) {
		sfSprite_setScale(checkbox->selected, scale);
		sfSprite_setScale(checkbox->unselected, scale);
		checkbox->reset_scale = false;
	}
}

void checkbox_click_pressed(win_t *win, const sfEvent *event)
{
	if (event->mouseButton.button != sfMouseLeft)
		return;
	for (checkbox_t *tmp = win->game->ui->checkbox; tmp; tmp = tmp->next) {
		if (tmp->game_state == win->game_state
			|| tmp->game_state == ALL)
			checkbox_click_pressed_action(win, tmp);
	}
}
