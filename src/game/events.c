/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** Event handler
*/

#include "macros.h"

#include "game/events.h"
#include "game/keyboard/keybinds.h"
#include "game/particles/particle_explosion.h"

#include "utils/csfml/event_utils.h"
#include "utils/csfml/mouse_utils.h"

void close_win_evt(win_t *win, __attribute__((unused)) sfEvent *event)
{
	sfRenderWindow_close(win->sf_win);
}

void key_pressed(win_t *win, sfEvent *event)
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

void mouse_click(win_t *win, __attribute__((unused)) sfEvent *event)
{
	static uint16_t index = 0;
	const sfColor colors[] = {
		sfRed, sfGreen,
		sfBlue, sfYellow,
		sfMagenta, sfCyan
	};
	sfVector2f pos = get_mouse_pos(win);

	create_explosion(win, 100, pos, colors[(++index) % 6]);
}

void on_resize(win_t *win, __attribute__((unused)) sfEvent *event)
{
	sfVector2u size = sfRenderWindow_getSize(win->sf_win);

	win->width = size.x;
	win->height = size.y;
}

void process_event(win_t *win)
{
	sfEvent event;

	while (sfRenderWindow_pollEvent(win->sf_win, &event)) {
		for (size_t i = 0; events[i].func != NULL; i++) {
			if ((events[i].game_state == ALL ||
			events[i].game_state == win->game_state) &&
			events[i].type == event.type) {
				events[i].func(win, &event);
				break;
			}
		}
	}
}
