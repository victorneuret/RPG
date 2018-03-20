/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** level
*/

#pragma once

#include <SFML/Graphics.h>

#include <stdint.h>
#include <stddef.h>

typedef enum {
	EMPTY,
	BLOCK,
	SPAWN
} tile_type_t;

typedef struct {
	sfSprite *sprite;
	sfVector2f pos;
	tile_type_t tile_type;
} tile_t;

typedef struct {
	sfImage *level_src;
	sfVector2f size;
	tile_t **tiles;
} level_t;

bool load_level(win_t *win, char const *path);
