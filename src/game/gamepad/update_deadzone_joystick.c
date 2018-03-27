/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** update_deadzone_joystick
*/

#include "joystick.h"

void update_deadzone_joystick(joystick_t *joystick)
{
	if ((joystick->lx > -30 && joystick->lx < 30)
		&& (joystick->ly > -30 && joystick->ly < 30)) {
		joystick->lx = 0;
		joystick->ly = 0;
	}
	if ((joystick->rx > -30 && joystick->rx < 30)
		&& (joystick->ry > -30 && joystick->ry < 30)) {
		joystick->rx = 0;
		joystick->ry = 0;
	}
}
