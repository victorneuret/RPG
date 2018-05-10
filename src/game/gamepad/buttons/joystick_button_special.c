/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** joystick_button_special
*/

#include "joystick.h"
#include "change_state.h"

void button_select(win_t *win, bool press)
{
	static bool pressed = false;

	if (!press) {
		pressed = false;
		return;
	} else if (!pressed && press) {
		stats_game(win);
		pressed = true;
	}
}

void button_start(win_t *win, bool press)
{
	static bool pressed = false;

	if (!press && pressed) {
		pressed = false;
		return;
	} else if (!pressed && press) {
		pause_game(win);
		pressed = true;
	}
}

void button_menu(win_t *win, bool press)
{
	static bool pressed = false;

	if (!press && pressed) {
		pressed = false;
		return;
	} else if (!pressed && press) {
		pressed = true;
		to_title_page(win);
	}
}
