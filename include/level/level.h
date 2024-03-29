/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** level
*/

#pragma once

#include <stddef.h>
#include <SFML/Graphics.h>

#include "dungeon.h"

typedef enum env_name {
	BOAT, DUNGEON, HELL, VOLCANO,
	NIGHTMARE, DEEP_CAVE, CAVE, DESERT,
	CASTLE, CANYON, COAL_MINE, HAUNTED,
	OLDER_HOUSE, OLD_HOUSE, EMPTY_LIBRARY, LIBRARY,

	ENV_COUNT
} env_name_t;

typedef struct env {
	env_name_t name;
	sfIntRect texture_rect;
} env_t;

typedef struct level {
	sfSprite *top_l;
	sfSprite *top_r;
	sfSprite *bot_l;
	sfSprite *bot_r;
} level_t;

static const size_t ENV_W = 960;
static const size_t ENV_H = 540;

static const env_t env_list[] = {
	{ BOAT,			(sfIntRect) {0, 0, 960, 540} },
	{ DUNGEON,		(sfIntRect) {960, 0, 960, 540} },
	{ HELL,			(sfIntRect) {1920, 0, 960, 540} },
	{ VOLCANO,		(sfIntRect) {2880, 0, 960, 540} },
	{ NIGHTMARE,		(sfIntRect) {0, 540, 960, 540} },
	{ DEEP_CAVE,		(sfIntRect) {960, 540, 960, 540} },
	{ CAVE,			(sfIntRect) {1920, 540, 960, 540} },
	{ DESERT,		(sfIntRect) {2880, 540, 960, 540} },
	{ CASTLE,		(sfIntRect) {0, 1080, 960, 540} },
	{ CANYON,		(sfIntRect) {960, 1080, 960, 540} },
	{ COAL_MINE,		(sfIntRect) {1920, 1080, 960, 540} },
	{ HAUNTED,		(sfIntRect) {2880, 1080, 960, 540} },
	{ OLDER_HOUSE,		(sfIntRect) {0, 1620, 960, 540} },
	{ OLD_HOUSE,		(sfIntRect) {960, 1620, 960, 540} },
	{ EMPTY_LIBRARY,	(sfIntRect) {1920, 1620, 960, 540} },
	{ LIBRARY,		(sfIntRect) {2880, 1620, 960, 540} }
};

static const uint16_t X_DOOR_UP = 1920 / 2;
static const uint16_t Y_DOOR_UP = 83;
static const uint16_t X_DOOR_DOWN = 1920 / 2;
static const uint16_t Y_DOOR_DOWN = 1080 - 83;
static const uint16_t X_DOOR_LEFT = 83;
static const uint16_t Y_DOOR_LEFT = 1080 / 2;
static const uint16_t X_DOOR_RIGHT = 1920 - 83;
static const uint16_t Y_DOOR_RIGHT = 1080 / 2;

typedef struct room room_t;

bool display_door(room_t *room, win_t *win);
bool draw_obstacle(room_t *room, win_t *win);
void draw_at_pos(win_t *win, sfSprite *sprite, sfVector2f pos,
		int16_t rotation);

void unload_level(level_t *level);
bool load_level(level_t **level, env_name_t env_name, win_t *win);
void draw_level(sfRenderWindow *window, level_t const *level, win_t *win);
