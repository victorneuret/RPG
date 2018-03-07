/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** keybinds
*/

#pragma once

#include <SFML/Graphics.h>

#include "window/render_window.h"

#include "game/keyboard/key_pressed_functions.h"

typedef struct {
	game_status game_state;
	sfKeyCode keycode;
	bool (*func)(win_t *win);
} keybind_t;

static const keybind_t keybinds[] = {
	{ALL,	sfKeyQ,		close_win},
	{ALL,	sfKeyF11,	toggle_fullscreen},
	{ALL,	sfKeyF12,	toggle_fps},
	{PAUSE,	sfKeyEscape,	pause_game},
	{GAME,	sfKeyEscape,	pause_game},
	{0,	0,		NULL}
};
