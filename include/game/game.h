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

typedef struct textures textures_t;
typedef struct render_window win_t;
typedef struct ui ui_t;

typedef struct game {
	textures_t *textures;
	ui_t *ui;
	weather_type_t weather_type;
	weather_intensity_t weather_intensity;
} game_t;

bool init_game(win_t *win);
void free_game(game_t *game);