/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** level_update
*/

#include "game.h"
#include "level.h"
#include "render_window.h"

static void update_tile(win_t *win, tile_t *tile)
{
	sfVector2f move_factor = {0};

	move_factor.x = -win->joystick->rx * 5.f * win->dt;
	move_factor.y = -win->joystick->ry * 5.f * win->dt;
	sfRectangleShape_move(tile->block, move_factor);
}

void update_level(win_t *win)
{
	level_t *level = win->game->level;

	for (size_t y = 0; y < level->size.y; y++)
		for (size_t x = 0; x < level->size.x; x++)
			update_tile(win, &level->tiles[y][x]);
}
