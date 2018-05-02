/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** level
*/

#pragma once

#include <stddef.h>
#include <SFML/Graphics.h>

typedef enum env_name {
	BOAT, DONGEON, HELL, VOLCANO,
	NIGHTMARE, DEEP_CAVE, CAVE, DESERT,
	CASTLE, CANYON, COAL_MINE, HAUNTED,
	OLDER_HOUSE, OLD_HOUSE, EMPTY_LIBRARY, LIBRARY,

	ENV_COUNT
} env_name;

typedef struct env {
	env_name name;
	sfIntRect texture_rect;
} env_t;

typedef struct level {
	sfTexture *texture;
	sfSprite *top_left;
	sfSprite *top_right;
	sfSprite *bot_left;
	sfSprite *bot_right;
} level_t;

static const env_t env_list[] = {
	{ BOAT,			(sfIntRect) {0, 0, 960, 540} },
	{ DONGEON,		(sfIntRect) {960, 0, 960, 540} },
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
