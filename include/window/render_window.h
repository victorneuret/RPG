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
#include "joystick.h"
#include "intro_struct.h"

#define WINDOW_TITLE "My RPG"

static const uint16_t WIN_MAX_W = 1920;
static const uint16_t WIN_MAX_H = 1080;

typedef struct game game_t;
typedef struct particle_manager particle_manager_t;

typedef enum game_state {
	TITLE = 1,
	GAME = 1 << 1,
	PAUSE = 1 << 2,
	OPTION = 1 << 3,
	INTRO = 1 << 4,
	ALL = -1
} game_status;

typedef struct render_window {
	settings_t *settings;
	game_t *game;
	joystick_t *joystick;
	particle_manager_t *particle_manager;
	intro_t *intro;
	sfRenderWindow *sf_win;
	sfClock *timer;
	sfView *view;
	sfVector2f size;
	game_status game_state;
	float dt;
} win_t;

#include "game.h"
#include "destroy.h"

win_t *create_window(size_t width, size_t height, settings_t *settings);
