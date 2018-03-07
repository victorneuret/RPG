/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** Struct window
*/

#pragma once

#include <SFML/Graphics.h>

#include "settings.h"

#define WINDOW_TITLE "My RPG"

typedef enum {
	TITLE,
	GAME,
	PAUSE,
	ALL
} game_status;

typedef struct render_window {
	float dt;
	size_t width;
	size_t height;
	settings_t *settings;
	sfRenderWindow *sf_win;
	sfClock *timer;
	sfView *view;
	game_status game_state;
} win_t;

#include "window/destroy.h"

win_t *create_window(size_t width, size_t height, settings_t *settings);
