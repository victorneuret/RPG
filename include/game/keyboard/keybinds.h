/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** keybinds
*/

#pragma once

#include <SFML/Graphics.h>

#include "render_window.h"

#include "key_pressed_functions.h"

typedef struct {
	game_status game_state;
	sfKeyCode keycode;
	void (*func)(win_t *win);
} keybind_t;

static const keybind_t keybinds[] = {
	{ALL,	sfKeyQ,		&close_win},
	{ALL,	sfKeyF11,	&toggle_fullscreen},
	{ALL,	sfKeyF12,	&toggle_fps},
	{PAUSE,	sfKeyEscape,	&pause_game},
	{GAME,	sfKeyEscape,	&pause_game},
	{GAME,	sfKeyUp,	&next_intensity},
	{GAME,	sfKeyDown,	&previous_intensity},
	{GAME,	sfKeyRight,	&next_weather},
	{GAME,	sfKeyLeft,	&previous_weather},
	{0,	0,		NULL}
};
