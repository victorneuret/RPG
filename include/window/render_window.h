/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** Struct window
*/

#pragma once

#include <SFML/Graphics.h>

#include "settings.h"

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
	sfClock *timer;
	sfRenderWindow *sf_win;
	sfView *view;
	game_status game_state;
} win_t;

#include "window/destroy.h"

win_t *create_window(size_t width, size_t height, settings_t *settings);
