/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** Event handler
*/

#include "macros.h"

#include "events.h"

static void process_event(win_t *win, sfEvent *event)
{
	for (size_t i = 0; events[i].func != NULL; i++) {
		if (((events[i].game_state & win->game_state)
			== win->game_state || events[i].game_state == ALL) &&
				events[i].type == event->type) {
			events[i].func(win, event);
			break;
		}
	}
}

void process_events(win_t *win)
{
	sfEvent event;
	float axis = 0;

	while (sfRenderWindow_pollEvent(win->sf_win, &event))
		process_event(win, &event);
	if (event.type == sfEvtJoystickMoved) {
		axis = sfJoystick_getAxisPosition(event.joystickButton.joystickId, sfJoystickPovX);
		if (axis == -100)
			printf("Pad left\n");
		else if (axis == 100)
			printf("Pad right\n");
		axis = sfJoystick_getAxisPosition(event.joystickButton.joystickId, sfJoystickPovY);
		if (axis == -100)
			printf("Pad top\n");
		else if (axis == 100)
			printf("Pad bottom\n");
		axis = sfJoystick_getAxisPosition(event.joystickButton.joystickId, sfJoystickU);
		if (axis == -100)
			printf("right joystick left\n");
		else if (axis == 100)
			printf("right joystick right\n");
		axis = sfJoystick_getAxisPosition(event.joystickButton.joystickId, sfJoystickV);
		if (axis == -100)
			printf("right joystick top\n");
		else if (axis == 100)
			printf("right joystick bottom\n");
		axis = sfJoystick_getAxisPosition(event.joystickButton.joystickId, sfJoystickX);
		if (axis == -100)
			printf("left joystick left\n");
		else if (axis == 100)
			printf("left joystick right\n");
		axis = sfJoystick_getAxisPosition(event.joystickButton.joystickId, sfJoystickY);
		if (axis == -100)
			printf("left joystick top\n");
		else if (axis == 100)
			printf("left joystick bottom\n");
		axis = sfJoystick_getAxisPosition(event.joystickButton.joystickId, sfJoystickZ);
		if (axis == -100)
			printf("LT\n");
		else if (axis == 100)
			printf("RT\n");
		//printf("%f\n", sfJoystick_getAxisPosition(event.joystickButton.joystickId, sfJoystickZ));
	}
	if (event.type == sfEvtJoystickButtonPressed) {
		if (sfJoystick_isButtonPressed(event.joystickButton.joystickId, 0))
			printf("A\n");
		if (sfJoystick_isButtonPressed(event.joystickButton.joystickId, 1))
			printf("B\n");
		if (sfJoystick_isButtonPressed(event.joystickButton.joystickId, 2))
			printf("X\n");
		if (sfJoystick_isButtonPressed(event.joystickButton.joystickId, 3))
			printf("Y\n");
		if (sfJoystick_isButtonPressed(event.joystickButton.joystickId, 4))
			printf("LB\n");
		if (sfJoystick_isButtonPressed(event.joystickButton.joystickId, 5))
			printf("RB\n");
		if (sfJoystick_isButtonPressed(event.joystickButton.joystickId, 6))
			printf("select\n");
		if (sfJoystick_isButtonPressed(event.joystickButton.joystickId, 7))
			printf("start\n");
		if (sfJoystick_isButtonPressed(event.joystickButton.joystickId, 8))
			printf("Windaube\n");
		if (sfJoystick_isButtonPressed(event.joystickButton.joystickId, 9))
			printf("Left joystick\n");
		if (sfJoystick_isButtonPressed(event.joystickButton.joystickId, 10))
			printf("Right joystick\n");
		if (sfJoystick_isButtonPressed(event.joystickButton.joystickId, 11))
			printf("??\n");
		if (sfJoystick_isButtonPressed(event.joystickButton.joystickId, 12))
			printf("!??\n");
	}
}
