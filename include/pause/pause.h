/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** pause
*/

#pragma once

#include <SFML/Graphics.h>

#include <stdbool.h>

#include "game.h"
#include "render_window.h"

typedef struct pause {
	sfTexture *texture;
	sfSprite *background;
} pause_t;

bool init_pause(game_t *game);
void render_pause(win_t *win, pause_t *pause);
