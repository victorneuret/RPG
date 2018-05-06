/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** game
*/

#pragma once

#include "render_window.h"
#include "texture.h"
#include "ui.h"
#include "weather.h"
#include "joystick.h"
#include "player.h"
#include "dungeon.h"
#include "level.h"
#include "music.h"

typedef struct textures textures_t;
typedef struct render_window win_t;
typedef struct sounds sounds_t;
typedef struct ui ui_t;
typedef struct dungeon dungeon_t;
typedef struct room room_t;

static const float GRAVITY = 500;

typedef struct game {
	textures_t *textures;
	ui_t *ui;
	sounds_t *sounds;
	weather_type_t weather_type;
	weather_intensity_t weather_intensity;
	player_t *player;
	dungeon_t *dungeon;
	room_t **rooms;
	level_t *level;
} game_t;

bool init_game(win_t *win);
void free_game(game_t *game);
