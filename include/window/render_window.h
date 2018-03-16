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
#include "game.h"

#define WINDOW_TITLE "My RPG"

static const uint16_t WIN_MAX_W = 1920;
static const uint16_t WIN_MAX_H = 1080;

typedef struct game game_t;

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
	game_t *game;
	sfRenderWindow *sf_win;
	sfClock *timer;
	sfView *view;
	game_status game_state;
	struct particle_manager *particle_manager;
} win_t;

#include "destroy.h"

win_t *create_window(size_t width, size_t height, settings_t *settings);
