/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** game
*/

#pragma once

#include "render_window.h"
#include "texture.h"

typedef struct textures textures_t;
typedef struct render_window win_t;

typedef struct game {
	textures_t *textures;
} game_t;

bool init_game(win_t *win);
