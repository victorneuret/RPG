/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** Event header
*/

#pragma once

#include <stdbool.h>
#include <SFML/Graphics.h>

#include "window/render_window.h"
#include "game/keyboard/key_pressed_functions.h"

void on_resize(win_t *win, sfEvent *event);
void key_pressed(win_t *win, sfEvent *event);
void mouse_click(win_t *win, sfEvent *event);
void close_win_evt(win_t *win, sfEvent *event);
void process_event(win_t *win);

typedef struct {
	game_status game_state;
	sfEventType type;
	void (*func)(win_t *win, sfEvent *event);
} event_t;

static const event_t events[] = {
	{ALL,	sfEvtClosed,			&close_win_evt},
	{ALL,	sfEvtKeyPressed,		&key_pressed},
	{ALL,	sfEvtResized,			&on_resize},
	{ALL,	sfEvtMouseButtonPressed,	&mouse_click},
	{0,	0,				NULL}
};
