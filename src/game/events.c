/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** Event handler
*/

#include "macros.h"

#include "game/events.h"
#include "game/keyboard/keybinds.h"

#include "utils/csfml/event_utils.h"

static void key_pressed(win_t *win, sfEvent *event)
{
	for (size_t i = 0; keybinds[i].func != NULL; i++) {
		if ((keybinds[i].game_state == ALL ||
		keybinds[i].game_state == win->game_state) &&
		keybinds[i].keycode == event->key.code) {
			keybinds[i].func(win);
			break;
		}
	}
}

void on_resize(win_t *win)
{
	sfVector2u size = sfRenderWindow_getSize(win->sf_win);

	win->width = size.x;
	win->height = size.y;
}

void process_event(win_t *win)
{
	sfEvent event;

	while (sfRenderWindow_pollEvent(win->sf_win, &event)) {
		switch (event.type) {
		case sfEvtClosed: sfRenderWindow_close(win->sf_win); break;
		case sfEvtKeyPressed: key_pressed(win, &event); break;
		case sfEvtResized: on_resize(win); break;
		default: break;
		}
	}
}
