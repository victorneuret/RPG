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

static bool load_tile(level_t *level, tile_t **tiles, size_t x, size_t y)
{
	sfColor tile_color = sfImage_getPixel(level->level_src, x, y);
	sfRectangleShape *block = sfRectangleShape_create();

	if (!block)
		return false;
	sfRectangleShape_setSize(block,
			(sfVector2f) {level->block_size, level->block_size});
	sfRectangleShape_setFillColor(block, tile_color);
	sfRectangleShape_setPosition(block,
		(sfVector2f) {x * level->block_size, y * level->block_size});
	tiles[y][x].block = block;
	tiles[y][x].pos = (sfVector2u) {x, y};
	tiles[y][x].tile_type = get_block_type(tile_color);
	tiles[y][x].screen_pos = (sfVector2u) {x * level->block_size,
					y * level->block_size};
	return true;
}

static tile_t **load_tiles(level_t *level)
{
	tile_t **tiles = my_calloc(level->size.y, sizeof(tile_t *));
	bool tile_load_ok = true;

	if (!tiles)
		return NULL;
	for (size_t y = 0; y < level->size.y; y++) {
		tiles[y] = my_calloc(level->size.x, sizeof(tile_t));
		if (!tiles[y])
			return NULL;
		for (size_t x = 0; x < level->size.x && tile_load_ok; x++)
			tile_load_ok = load_tile(level, tiles, x, y);
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
	sfImage_createMaskFromColor(level->level_src, sfWhite, 0);
	level->size = sfImage_getSize(level->level_src);
	level->block_size = (WIN_MAX_H / (double) level->size.y) * 2.5f;
	level->tiles = load_tiles(level);
	if (!level->tiles)
		return false;
	game->level = level;
	putstr("Level loaded\n");
	return true;
}
