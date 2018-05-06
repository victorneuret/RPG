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
#include "dir_arrow.h"
#include "shoot_arrow.h"

typedef struct {
	game_status game_state;
	sfKeyCode keycode;
	void (*func)(win_t *win);
} keybind_t;

static const keybind_t keybinds[] = {
	{ALL,	sfKeyDelete,	&to_title_page},
	{ALL,	sfKeyF11,	&toggle_fullscreen},
	{ALL,	sfKeyF12,	&toggle_fps},
	{PAUSE,	sfKeyEscape,	&pause_game},
	{GAME,	sfKeyEscape,	&pause_game},
	{GAME,	sfKeyZ,		&arrow_up},
	{GAME,	sfKeyS,		&arrow_down},
	{GAME,	sfKeyD,		&arrow_right},
	{GAME,	sfKeyQ,		&arrow_left},
	{GAME,	sfKeyUp, 	&shoot_up},
	{GAME, 	sfKeyDown, 	&shoot_down},
	{GAME, 	sfKeyRight, 	&shoot_right},
	{GAME, 	sfKeyLeft, 	&shoot_left},
	{0,	0,		NULL}
};
