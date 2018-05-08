/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** player
*/

#pragma once

#include <SFML/Graphics.h>

#include <stdint.h>

#include "hud.h"

static const float X_SPEED = 900.f;
static const uint8_t WALL_SIZE = 140;

static const uint8_t PLAYER_W = 128;
static const uint8_t PLAYER_H = 138;

typedef enum {
	LEFT,
	RIGHT,
	TOP,
	BOTTOM
} direction_t;

typedef struct player {
	sfClock *timer;
	sfSprite *sprite;
	float speed;
	uint8_t level;
	uint16_t basic_hp;
	uint16_t hp;
	float hp_mult;
	uint16_t xp;
	float xp_multi;
	hud_t *hud;
	sfSprite *aim;
	float aim_angle;
} player_t;

#include "render_window.h"
#include "dungeon.h"

typedef struct room room_t;

player_t *init_player(win_t *win);
void update_player(win_t *win, player_t *player);
void update_idle(player_t *player, uint8_t dir);
void animate_sprite(player_t *player, uint16_t offset, uint8_t max_val);
void draw_player(win_t *win, player_t *player);
void destroy_player(player_t *player);
void check_obstacle(sfVector2f *pos, win_t *win);

void player_shoot(win_t *win, player_t *player);
void player_door(win_t *win, sfVector2f *pos, room_t *room);
void door_action(win_t *win, sfVector2f *pos, room_t *room);
