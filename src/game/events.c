/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** Event handler
*/

#include "macros.h"

#include "events.h"
#include "joystick.h"

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

static void joystick_event(win_t *win, __attribute__ ((unused)) sfEvent *event)
{
	for (uint8_t i = 0; gamepad_button_state[i].button != BTN_COUNT; i++) {
		if (gamepad_button_state[i].state == true
			&& gamepad_button_state[i].func)
		 	gamepad_button_state[i].func(win, true);
		else if (gamepad_button_state[i].func)
			gamepad_button_state[i].func(win, false);
	}
}

void process_events(win_t *win)
{
	sfEvent event;

	while (sfRenderWindow_pollEvent(win->sf_win, &event)) {
		process_event(win, &event);
		if (sfJoystick_isConnected(win->game->joystick->id))
			joystick_event(win, &event);
		if (win->game->joystick->rt >= 60)
			button_rt(win, true);
		else
			button_rt(win, false);
		if (win->game->joystick->lt >= 60)
			button_lt(win, true);
		else
			button_lt(win, false);
	}
}
