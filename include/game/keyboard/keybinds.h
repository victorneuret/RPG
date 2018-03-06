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
	sfKeyCode keycode;
	bool (*func)(win_t *win);
} keybind_t;

static const keybind_t keybinds[] = {
	{sfKeyEscape, &close_win},
	{sfKeyF12, &toggle_fps},
	{0, NULL}
};
