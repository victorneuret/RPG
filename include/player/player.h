/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** player
*/

#pragma once

#include <SFML/Graphics.h>

#include <stdint.h>

static const float X_SPEED = 1000.f;
static const uint8_t WALL_SIZE = 140;

typedef enum {
	LEFT,
	RIGHT,
	TOP,
	BOTTOM
} direction_t;

typedef struct player {
	sfClock *clock;
	sfSprite *sprite;
	sfSprite *aim;
	float y_speed;
} player_t;

#include "render_window.h"

player_t *init_player(win_t *win);
void update_player(win_t *win, player_t *player);
void update_idle(player_t *player, uint8_t dir);
void animate_sprite(player_t *player, uint16_t offset, uint8_t max_val);
void draw_player(win_t *win, player_t *player);
void destroy_player(player_t *player);
