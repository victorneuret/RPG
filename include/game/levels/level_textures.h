/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** level_textures
*/

#pragma once

#include "level.h"

typedef enum texture_orientation {
	TOP_LEFT,	TOP,	TOP_RIGHT,
	LEFT,		CENTER,	RIGHT,
	BOTTOM_LEFT,	BOTTOM,	BOTTOM_RIGHT
} texture_orientation;

typedef struct tile_texture {
	texture_orientation orientation;
	sfIntRect img_pos;
} tile_texture_t;

static const size_t SIZE = 16;

static const tile_texture_t tile_textures[] = {
	{TOP,		(sfIntRect) {SIZE * 1, SIZE * 0, SIZE, SIZE}}
};
