/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** player
*/

#pragma once

#include <SFML/Graphics.h>

typedef struct player {
	sfClock *clock;
	sfSprite *sprite;
	float y_speed;
} player_t;

#include "render_window.h"

player_t *init_player(win_t *win);
void update_player(win_t *win, player_t *player);
void draw_player(win_t *win, player_t *player);
void destroy_player(player_t *player);
