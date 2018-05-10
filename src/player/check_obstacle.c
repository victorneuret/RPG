/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** check_obstacle
*/

#include <SFML/Graphics.h>

#include "render_window.h"
#include "player.h"
#include "dungeon.h"

static void check_cell_horizontal(sfVector2f *pos, uint8_t y_pos, uint8_t x_pos)
{
	uint16_t x = x_pos * ROCK_W + WALL_SIZE_ROCK;
	uint16_t y = y_pos * ROCK_H + WALL_SIZE_ROCK;

	if (pos->x + 32 > x && pos->x + 32 < x + ROCK_W
		&& ((pos->y + PLAYER_H / 2.f > y
		&& pos->y + PLAYER_H / 2.f < y + ROCK_H)
		|| (pos->y + PLAYER_H > y && pos->y + PLAYER_H < y + ROCK_H))) {
		pos->x = x + ROCK_W - 31;
	}
	if (pos->x + PLAYER_W - 32 > x && pos->x + PLAYER_W - 32 < x + ROCK_W
		&& ((pos->y + PLAYER_H / 2.f > y
		&& pos->y + PLAYER_H / 2.f < y + ROCK_H)
		|| (pos->y + PLAYER_H > y && pos->y + PLAYER_H < y + ROCK_H))) {
		pos->x = x - PLAYER_W + 31;
	}
}

static void check_cell_vertical(sfVector2f *pos, uint8_t y_pos, uint8_t x_pos)
{
	uint16_t x = x_pos * ROCK_W + WALL_SIZE_ROCK;
	uint16_t y = y_pos * ROCK_H + WALL_SIZE_ROCK;

	if (pos->y + PLAYER_H / 2.f < y + ROCK_H && pos->y + PLAYER_H / 2.f > y
		&& ((pos->x + 32 > x && pos->x + 32 < x + ROCK_W)
		|| (pos->x + PLAYER_W - 32 > x
		&& pos->x + PLAYER_W - 32 < x + ROCK_W))) {
		pos->y = y + ROCK_H - PLAYER_H / 2;
	}
	if (pos->y + PLAYER_H < y + ROCK_H && pos->y + PLAYER_H > y
		&& ((pos->x + 32 > x && pos->x + 32 < x + ROCK_W)
		|| (pos->x + PLAYER_W - 32 > x
		&& pos->x + PLAYER_W - 32 < x + ROCK_W))) {
		pos->y = y - PLAYER_H;
	}
}

static bool is_side(win_t *win, sfVector2i cell_pos)
{
	sfFloatRect rect = sfSprite_getGlobalBounds(win->game->player->sprite);

	if (rect.left + rect.width - 32 < cell_pos.x * ROCK_W + WALL_SIZE_ROCK)
		return true;
	else if (rect.left + 32 > cell_pos.x * ROCK_W + WALL_SIZE_ROCK + ROCK_W)
		return true;
	return false;
}

static void is_obstacle(win_t *win, sfVector2f *pos, char **map,
			sfVector2i cell_pos)
{
	bool side = false;

	if (map[cell_pos.y][cell_pos.x] == 'X') {
		side = is_side(win, cell_pos);
		if (side)
			check_cell_horizontal(pos, cell_pos.y, cell_pos.x);
		else
			check_cell_vertical(pos, cell_pos.y, cell_pos.x);
	}
}

void check_obstacle(sfVector2f *pos, win_t *win)
{
	char **map = win->game->rooms[win->game->dungeon->act_room]->cells;

	pos->x -= PLAYER_W / 2.f;
	pos->y -= PLAYER_H / 2.f;
	for (size_t i = 0; map[i]; i++)
		for (size_t j = 0; map[i][j]; j++)
			is_obstacle(win, pos, map, (sfVector2i) {j, i});
	pos->x += PLAYER_W / 2.f;
	pos->y += PLAYER_H / 2.f;
}
