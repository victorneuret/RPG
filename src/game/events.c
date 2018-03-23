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

	while (sfRenderWindow_pollEvent(win->sf_win, &event))
		process_event(win, &event);
}
