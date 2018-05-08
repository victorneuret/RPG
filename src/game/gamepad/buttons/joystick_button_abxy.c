/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** joystick_button_one
*/

#include "joystick.h"
#include "events.h"
#include "render_window.h"

void button_a(win_t *win, bool press)
{
	static bool pressed = false;
	sfEvent event;

	event.mouseButton.button = sfMouseLeft;
	if (!press && pressed) {
		pressed = false;
	} else if (!pressed && press) {
		if (win->game_state == INTRO)
			exit_intro(win, NULL);
		button_click_released(win, &event);
		if (press && win->game_state == GAME && (
			sfSprite_getPosition(win->game->player->sprite).y +
			sfSprite_getGlobalBounds(win->game->player->sprite)
			.height >= WIN_MAX_H - 10))
			win->game->player->y_speed = 80;
		pressed = true;
	}
}

void button_b(win_t *win, bool press)
{
	static bool pressed = false;

	if (!press && pressed) {
		pressed = false;
		return;
	} else if (!pressed && press) {
		if (win->game_state == OPTION)
			win->game_state = TITLE;
		else if (win->game_state == PAUSE)
			win->game_state = GAME;
		pressed = true;
	}
}

void button_x(__attribute__((unused)) win_t *win, bool press)
{
	static bool pressed = false;

	if (!press) {
		pressed = false;
		return;
	} else if (!pressed && press) {
		pressed = true;
	}
}

void button_y(__attribute__((unused)) win_t *win, bool press)
{
	static bool pressed = false;

	if (!press) {
		pressed = false;
		return;
	} else if (!pressed && press) {
		pressed = true;
	}
}
