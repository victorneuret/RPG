/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** joystick_button_rt_lt
*/

#include "joystick.h"

void button_lt(__attribute__((unused)) win_t *win, bool press)
{
	static bool pressed = false;

	if (!press) {
		pressed = false;
		return;
	}
	if (!pressed && press) {
		pressed = true;
		putstr("LT\n");
	}
}

void button_rt(__attribute__((unused)) win_t *win, bool press)
{
	static bool pressed = false;

	if (!press) {
		pressed = false;
		return;
	}
	if (!pressed && press) {
		pressed = true;
		putstr("RT\n");
	}
}
