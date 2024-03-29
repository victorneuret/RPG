/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** basic_events
*/

#include "macros.h"

#include "events.h"
#include "keybinds.h"
#include "particle_explosion.h"
#include "mouse_utils.h"
#include "slide_bar.h"

void close_win_evt(win_t *win, __attribute__((unused)) sfEvent *event)
{
	sfRenderWindow_close(win->sf_win);
}

void key_pressed(win_t *win, sfEvent *event)
{
	for (size_t i = 0; keybinds[i].func != NULL; i++) {
		if (((keybinds[i].game_state & win->game_state)
		== win->game_state || keybinds[i].game_state == ALL) &&
				keybinds[i].keycode == event->key.code) {
			keybinds[i].func(win);
			break;
		}
	}
}

void mouse_click(win_t *win, sfEvent *event)
{
	if (text_area_click(win))
		return;
	slide_bar_click(win->game->ui->slide_bar, win, 1);
	mouse_moved(win, event);
	button_click_pressed(win, event);
	checkbox_click_pressed(win, event);
	slider_click_pressed(win, event);
}

void mouse_click_released(win_t *win, sfEvent *event)
{
	button_click_released(win, event);
	checkbox_click_released(win, event);
	slide_bar_click(win->game->ui->slide_bar, win, 0);
}

void on_resize(win_t *win, __attribute__((unused)) sfEvent *event)
{
	sfVector2u size = sfRenderWindow_getSize(win->sf_win);

	win->size.x = size.x;
	win->size.y = size.y;
}
