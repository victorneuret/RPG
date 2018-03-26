/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** level_load
*/

#include "game.h"
#include "level.h"
#include "my_calloc.h"
#include "render_window.h"

static const size_t BLOCK_SIZE = 1920 / 27.f;

static tile_type_t get_block_type(sfColor pixel_color)
{
	sfUint32 pixel = sfColor_toInteger(pixel_color);

	switch (pixel) {
	case EMPTY: return EMPTY;
	case BLOCK: return BLOCK;
	case DECO: return DECO;
	case SPAWN: return SPAWN;
	default: return UNKNOWN;
	}
	return UNKNOWN;
}

static bool load_tile(sfImage *src, tile_t **tiles, size_t x, size_t y)
{
	sfColor tile_color = sfImage_getPixel(src, x, y);
	sfRectangleShape *block = sfRectangleShape_create();

	if (!block)
		return false;
	sfRectangleShape_setSize(block, (sfVector2f) {BLOCK_SIZE, BLOCK_SIZE});
	sfRectangleShape_setFillColor(block, tile_color);
	sfRectangleShape_setOutlineColor(block, sfBlack);
	sfRectangleShape_setOutlineThickness(block, 1.f);
	sfRectangleShape_setPosition(block,
				(sfVector2f) {x * BLOCK_SIZE, y * BLOCK_SIZE});
	tiles[y][x].pos = (sfVector2u) {x, y};
	tiles[y][x].block = block;
	tiles[y][x].tile_type = get_block_type(tile_color);
	return true;
}

static tile_t **load_tiles(sfImage *src, sfVector2u size)
{
	tile_t **tiles = my_calloc(size.y, sizeof(tile_t *));
	bool tile_load_ok = true;

	if (!tiles)
		return NULL;
	for (size_t y = 0; y < size.y; y++) {
		tiles[y] = my_calloc(size.x, sizeof(tile_t));
		if (!tiles[y])
			return NULL;
		for (size_t x = 0; x < size.x && tile_load_ok; x++)
			tile_load_ok = load_tile(src, tiles, x, y);
		if (!tile_load_ok)
			return NULL;
	}
	return tiles;
}

bool load_level(game_t *game, char const *path)
{
	level_t *level = my_calloc(1, sizeof(level_t));

	putstr("Loading level...\n");
	if (!level)
		return false;
	level->level_src = sfImage_createFromFile(path);
	if (!level->level_src)
		return false;
	level->size = sfImage_getSize(level->level_src);
	level->tiles = load_tiles(level->level_src, level->size);
	if (!level->tiles)
		return false;
	game->level = level;
	putstr("Level loaded\n");
	return true;
}
