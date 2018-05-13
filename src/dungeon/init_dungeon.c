/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** init_dungeon
*/

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include "dungeon.h"
#include "nb_utils.h"
#include "render_window.h"

static void place_neighbor_room(dungeon_t *dungeon, uint8_t x, uint8_t y,
				uint8_t *room_nb)
{
	if (x != 0 && dungeon->rooms[y][x - 1] == -1 && rand_int(0, 1)) {
		dungeon->rooms[y][x - 1] = *room_nb;
		*room_nb += 1;
	}
	if (y != 0 && dungeon->rooms[y - 1][x] == -1 && rand_int(0, 1)) {
		dungeon->rooms[y - 1][x] = *room_nb;
		*room_nb += 1;
	}
	if (x != NB_ROOMS_WIDTH - 1 && dungeon->rooms[y][x + 1] == -1
		&& rand_int(0, 1)) {
		dungeon->rooms[y][x + 1] = *room_nb;
		*room_nb += 1;
	}
	if (y != NB_ROOMS_HEIGHT - 1 && dungeon->rooms[y + 1][x] == -1
		&& rand_int(0, 1)) {
		dungeon->rooms[y + 1][x] = *room_nb;
		*room_nb += 1;
	}
}

static bool check_dir(uint8_t x, uint8_t y, uint8_t dir)
{
	if (dir == TOP && y == 0)
		return false;
	if (dir == BOTTOM && y == NB_ROOMS_HEIGHT - 1)
		return false;
	if (dir == LEFT && x == 0)
		return false;
	if (dir == RIGHT && x == NB_ROOMS_WIDTH - 1)
		return false;
	return true;
}

static bool next_room(uint8_t *x, uint8_t *y)
{
	uint8_t dir = rand_int(0, 3);

	if (!check_dir(*x, *y, dir))
		return false;
	if (dir == TOP)
		*y -= 1;
	if (dir == BOTTOM)
		*y += 1;
	if (dir == LEFT)
		*x -= 1;
	if (dir == RIGHT)
		*x += 1;
	return true;
}

void place_rooms(dungeon_t *dungeon)
{
	uint8_t room_nb = 0;
	uint8_t x = rand_int(0, NB_ROOMS_WIDTH - 1);
	uint8_t y = rand_int(0, NB_ROOMS_HEIGHT - 1);

	for (size_t i = 0; i < NB_ROOMS_HEIGHT; i++)
		memset(dungeon->rooms[i], -1, NB_ROOMS_WIDTH);
	while (room_nb < 8) {
		if (dungeon->rooms[y][x] == -1) {
			dungeon->rooms[y][x] = room_nb;
			room_nb++;
		}
		place_neighbor_room(dungeon, x, y, &room_nb);
		if (!next_room(&x, &y))
			break;
	}
	if (room_nb < 5) {
		for (size_t i = 0; i < NB_ROOMS_HEIGHT; i++)
			memset(dungeon->rooms[i], -1, NB_ROOMS_WIDTH);
		place_rooms(dungeon);
	} else
		dungeon->nb_rooms = room_nb;
}

bool init_dungeon(win_t *win)
{
	win->game->dungeon->rooms = malloc(sizeof(int8_t *) * NB_ROOMS_HEIGHT);
	win->game->dungeon->shade = sfRectangleShape_create();
	win->game->dungeon->transition = false;
	if (!win->game->dungeon->rooms || !win->game->dungeon->shade)
		return false;
	sfRectangleShape_setFillColor(win->game->dungeon->shade, sfBlack);
	sfRectangleShape_setSize(win->game->dungeon->shade,
						(sfVector2f){1920, 1080});
	for (size_t i = 0; i < NB_ROOMS_HEIGHT; i++) {
		win->game->dungeon->rooms[i] = malloc(sizeof(int8_t)
							* NB_ROOMS_WIDTH);
		if (!win->game->dungeon->rooms[i])
			return false;
	}
	for (size_t i = 0; i < NB_ROOMS_HEIGHT; i++)
		memset(win->game->dungeon->rooms[i], -1, NB_ROOMS_WIDTH);
	if (!init_portal(win->game->dungeon, win->game))
		return false;
	return true;
}
