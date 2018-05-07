/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** button_click
*/

#include "buttons.h"
#include "music.h"

static void button_click_released_action(win_t *win, buttons_t *button)
{
	sfFloatRect rect = sfSprite_getGlobalBounds(button->sprite);
	sfVector2f mouse = get_mouse_pos(win);

	if (mouse.x >= rect.left && mouse.x <= rect.left + rect.width
		&& mouse.y >= rect.top && mouse.y <= rect.top + rect.height) {
		if (button->func)
			button->func(win);
		button_click_animation(button);
		sfClock_restart(button->button_clock);
		button->reset_scale = true;
	}
}

void button_click_released(win_t *win, const sfEvent *event)
{
	if (event->mouseButton.button != sfMouseLeft)
		return;
	for (buttons_t *tmp = win->game->ui->buttons; tmp; tmp = tmp->next) {
		if (tmp->game_state == win->game_state
			|| tmp->game_state == ALL)
			button_click_released_action(win, tmp);
	}
}

static void button_click_pressed_action(win_t *win, buttons_t *button)
{
	sfFloatRect rect = sfSprite_getGlobalBounds(button->sprite);
	sfVector2f mouse = get_mouse_pos(win);
	sfVector2f scale = (sfVector2f) {0.9, 0.9};

	if (mouse.x >= rect.left && mouse.x <= rect.left + rect.width
		&& mouse.y >= rect.top && mouse.y <= rect.top + rect.height) {
		play_sfx(win->game->sounds, CLICK);
		sfSprite_setScale(button->sprite, scale);
		button->reset_scale = false;
	}
}

void button_click_pressed(win_t *win, const sfEvent *event)
{
	if (event->mouseButton.button != sfMouseLeft)
		return;
	for (buttons_t *tmp = win->game->ui->buttons; tmp; tmp = tmp->next) {
		if (tmp->game_state == win->game_state
			|| tmp->game_state == ALL)
			button_click_pressed_action(win, tmp);
	}
}
