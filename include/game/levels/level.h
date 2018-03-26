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
	EMPTY = 0xffffffff,
	BLOCK = 0x000000ff,
	DECO = 0x424242ff,
	SPAWN = 0xffff00ff,

	UNKNOWN = 0
} tile_type_t;

typedef struct {
	sfRectangleShape *block;
	sfVector2u pos;
	sfVector2u screen_pos;
	tile_type_t tile_type;
} tile_t;

typedef struct {
	sfImage *level_src;
	sfVector2u size;
	double block_size;
	tile_t **tiles;
} level_t;

void unload_level(game_t *game);
bool load_level(game_t *game, char const *path);
void draw_level(sfRenderWindow *sf_win, level_t *level);
