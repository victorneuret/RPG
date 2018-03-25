/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** joystick
*/

#include "render_window.h"
#include "joystick.h"

struct_gamepad_button_state_t gamepad_button_state[] = {
	{CONTROLLER_A, false, button_a},
	{CONTROLLER_B, false, button_b},
	{CONTROLLER_X, false, button_x},
	{CONTROLLER_Y, false, button_y},
	{CONTROLLER_LB, false, button_lb},
	{CONTROLLER_RB, false, button_rb},
	{CONTROLLER_SELECT, false, button_select},
	{CONTROLLER_START, false, button_start},
	{CONTROLLER_MENU, false, button_menu},
	{CONTROLLER_L, false, button_l},
	{CONTROLLER_R, false, button_r},
	{BTN_COUNT, 0, NULL}
};

void joystick_connected(win_t *win, sfEvent *event)
{
	create_popup(win->game->ui, "Controller connected", INFO);
	putstr(sfJoystick_getIdentification(
		event->joystickConnect.joystickId).name);
	win->game->joystick->id = event->joystickConnect.joystickId;
	putstr("\n");
}

void joystick_disconnected(win_t *win, __attribute__((unused)) sfEvent *event)
{
	create_popup(win->game->ui, "Controller disconnected", WARNING);
}

static void update_joystick_pos(joystick_t *joystick, win_t *win)
{
	joystick->lx = sfJoystick_getAxisPosition(joystick->id, JOYSTICK_LX);
	joystick->ly = sfJoystick_getAxisPosition(joystick->id, JOYSTICK_LY);
	joystick->rx = sfJoystick_getAxisPosition(joystick->id, JOYSTICK_RX);
	joystick->ry = sfJoystick_getAxisPosition(joystick->id, JOYSTICK_RY);
	joystick->dirx =
	sfJoystick_getAxisPosition(joystick->id, JOYSTICK_DIRX);
	joystick->diry =
	sfJoystick_getAxisPosition(joystick->id, JOYSTICK_DIRY);
	joystick->lt = sfJoystick_getAxisPosition(joystick->id, JOYSTICK_LT);
	joystick->rt = sfJoystick_getAxisPosition(joystick->id, JOYSTICK_RT);
	update_mouse_pos_joystick(win->game->joystick, win);
}

void update_joystick(win_t *win)
{
	for (uint8_t i = 0; gamepad_button_state[i].button != BTN_COUNT; i++) {
		if (sfJoystick_isButtonPressed(win->game->joystick->id,
					gamepad_button_state[i].button))
			gamepad_button_state[i].state = true;
		else
			gamepad_button_state[i].state = false;
	}
	update_joystick_pos(win->game->joystick, win);
}
