/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** switch_gamepad
*/

#include "joystick.h"

void mouse_moved(win_t *win, __attribute__((unused)) sfEvent *event)
{
	if (win->joystick->switch_gamepad->gamepad == true) {
		sfMouse_setPositionRenderWindow(
			win->joystick->switch_gamepad->mouse_pos, win->sf_win);
		sfRenderWindow_setMouseCursorVisible(win->sf_win, sfTrue);
		win->joystick->switch_gamepad->gamepad = false;
	} else
		win->joystick->switch_gamepad->mouse_pos =
				sfMouse_getPositionRenderWindow(win->sf_win);
}

void joystick_moved(win_t *win, __attribute__((unused)) sfEvent *event)
{
	if (win->joystick->switch_gamepad->gamepad == false) {
		win->joystick->switch_gamepad->mouse_pos =
			sfMouse_getPositionRenderWindow(win->sf_win);
		win->joystick->switch_gamepad->gamepad = true;
	}
	sfRenderWindow_setMouseCursorVisible(win->sf_win, sfFalse);
}
