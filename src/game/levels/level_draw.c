/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** level_draw
*/

#include "game.h"
#include "level.h"
#include "render_window.h"

// Can be even more optimized: check by row instead of tile by tile
static void draw_tile(sfRenderWindow *sf_win, level_t *level, sfVector2u index)
{
	sfFloatRect block = sfRectangleShape_getGlobalBounds(
		level->tiles[index.y][index.x].block);
	sfFloatRect screen = (sfFloatRect) {0, 0, WIN_MAX_W, WIN_MAX_H};
	sfFloatRect inter = {0};

	if (!sfFloatRect_intersects(&block, &screen, &inter))
		return;
	sfRenderWindow_drawRectangleShape(sf_win,
				level->tiles[index.y][index.x].block, NULL);
}

void draw_level(sfRenderWindow *sf_win, level_t *level)
{
	for (size_t y = 0; y < level->size.y; y++)
		for (size_t x = 0; x < level->size.x; x++)
			draw_tile(sf_win, level, (sfVector2u) {x, y});
}
