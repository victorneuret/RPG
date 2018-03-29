/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** level_draw
*/

#include "game.h"
#include "level.h"
#include "render.h"
#include "render_window.h"

void draw_level(sfRenderWindow *sf_win, level_t *level)
{
	for (size_t y = 0; y < level->size.y; y++)
		for (size_t x = 0; x < level->size.x; x++)
			render_object(sf_win, RECTANGLE,
				level->tiles[y][x].block);
}