/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** joystick_button_LB_RB
*/

#include "joystick.h"

void button_lb(__attribute__((unused)) win_t *win, bool press)
{
	static bool pressed = false;

	if (!press) {
		pressed = false;
		return;
	}
	if (!pressed && press) {
		pressed = true;
		putstr("LB\n");
	}
}

void button_rb(__attribute__((unused)) win_t *win, bool press)
{
	static bool pressed = false;

	if (!press) {
		pressed = false;
		return;
	}
	if (!pressed && press) {
		pressed = true;
		putstr("RB\n");
	}
}
