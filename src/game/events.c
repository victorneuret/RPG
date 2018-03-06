/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** Event handler
*/

#include "game/events.h"
#include "game/keyboard/keybinds.h"

#include "utils/csfml/event_utils.h"

static void key_pressed(win_t *win, sfEvent *event)
{
	for (size_t i = 0; keybinds[i].func != NULL; i++)
		if (keybinds[i].keycode == event->key.code)
			keybinds[i].func(win);
}

void process_event(win_t *win)
{
	sfEvent event;

	while (sfRenderWindow_pollEvent(win->sf_win, &event)) {
		switch (event.type) {
		case sfEvtClosed: sfRenderWindow_close(win->sf_win); break;
		case sfEvtKeyPressed: key_pressed(win, &event); break;
		default: break;
		}
	}
}
