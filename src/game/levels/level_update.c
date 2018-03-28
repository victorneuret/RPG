/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** level_update
*/

#include "game.h"
#include "level.h"
#include "render_window.h"

static sfVector2f get_move_factor(win_t *win, level_t *level)
{
	sfVector2f move_factor = {0};
	sfVector2f top_left_corner = sfRectangleShape_getPosition(
						level->tiles[0][0].block);
	sfVector2f bottom_right_corner = sfRectangleShape_getPosition(
		level->tiles[level->size.y - 1][level->size.x - 1].block);

	bottom_right_corner.x += level->block_size;
	bottom_right_corner.y += level->block_size;
	move_factor.x = -win->joystick->rx * 7.5f * win->dt;
	move_factor.y = -win->joystick->ry * 7.5f * win->dt;
	if (top_left_corner.x + move_factor.x > 0)
		move_factor.x = -top_left_corner.x;
	if (top_left_corner.y + move_factor.y > 0)
		move_factor.y = -top_left_corner.y;
	if (bottom_right_corner.x + move_factor.x < WIN_MAX_W)
		move_factor.x = WIN_MAX_W - bottom_right_corner.x;
	if (bottom_right_corner.y + move_factor.y < WIN_MAX_H)
		move_factor.y = WIN_MAX_H - bottom_right_corner.y;
	return move_factor;
}

void update_level(win_t *win)
{
	level_t *level = win->game->level;
	sfVector2f move_factor = (sfVector2f) {0, 0};

	if (win->joystick->rx == 0 && win->joystick->ry == 0)
		return;
	move_factor = get_move_factor(win, level);
	for (size_t y = 0; y < level->size.y; y++)
		for (size_t x = 0; x < level->size.x; x++)
			sfRectangleShape_move(level->tiles[y][x].block,
						move_factor);
}
