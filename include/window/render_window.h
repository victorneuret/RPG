/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** Struct window
*/

#pragma once

#include <SFML/Graphics.h>

#include "settings.h"

#include "particle.h"

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
	struct particle_manager *particle_manager;
} win_t;

#include "destroy.h"

win_t *create_window(size_t width, size_t height, settings_t *settings);
