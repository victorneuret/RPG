/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** joystick
*/

#include "render_window.h"

void joystick_connected(win_t *win, sfEvent *event)
{
	printf("connected\n");
	printf("%d\n", sfJoystick_getButtonCount(event->joystickConnect.joystickId));
	printf("%s\n", sfJoystick_getIdentification(event->joystickConnect.joystickId).name);
}

void joystick_disconnected(win_t *win, sfEvent *event)
{
	printf("disconnected\n");
}
