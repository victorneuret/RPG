/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** joystick_button_stick
*/

#include "joystick.h"

void button_l(__attribute__((unused)) win_t *win, bool press)
{
	static bool pressed = false;

	if (!press) {
		pressed = false;
		return;
	}
	if (!pressed && press)
		pressed = true;
}

void button_r(__attribute__((unused)) win_t *win, bool press)
{
	static bool pressed = false;

	if (!press) {
		pressed = false;
		return;
	}
	if (!pressed && press)
		pressed = true;
}
