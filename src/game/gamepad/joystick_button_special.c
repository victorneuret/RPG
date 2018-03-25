/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** joystick_button_special
*/

#include "joystick.h"

void button_select(__attribute__((unused)) win_t *win, bool press)
{
	static bool pressed = false;

	if (!press) {
		pressed = false;
		return;
	}
	if (!pressed && press) {
		pressed = true;
		putstr("Select\n");
	}
}

void button_start(win_t *win, bool press)
{
	static bool pressed = false;

	if (!press && pressed) {
		pressed = false;
		pause_game(win);
		return;
	} else if (!pressed && press) {
		pressed = true;
		putstr("Start\n");
	}
}

void button_menu(win_t *win, bool press)
{
	static bool pressed = false;

	if (!press && pressed) {
		pressed = false;
		to_title_page(win);
		return;
	} else if (!pressed && press) {
		pressed = true;
		putstr("Menu\n");
	}
}
