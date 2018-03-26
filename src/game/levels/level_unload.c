/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** level_unload
*/

#include "game.h"
#include "level.h"
#include "render_window.h"

static void destroy_tiles(tile_t **tiles, sfVector2u size)
{
	for (size_t y = 0; y < size.y; y++) {
		for (size_t x = 0; x < size.x; x++)
			sfRectangleShape_destroy(tiles[y][x].block);
		free(tiles[y]);
	}
	free(tiles);
}

void unload_level(game_t *game)
{
	level_t *level = game->level;

	putstr("Unloading level...\n");
	game->level = NULL;
	if (!level)
		return;
	sfImage_destroy(level->level_src);
	destroy_tiles(level->tiles, level->size);
	putstr("Level unloaded.\n");
}
