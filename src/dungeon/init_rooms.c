/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** init_rooms
*/

#include <string.h>

#include "dungeon.h"
#include "render_window.h"
#include "rooms.h"

#include "nb_utils.h"

static void print_room(game_t *game)
{
	for (size_t i = 0; i < game->dungeon->nb_rooms; i++) {
		printf("room: %ld\n", i);
		for (size_t j = 0; game->rooms[i]->cells[j]; j++) {
			putstr(game->rooms[i]->cells[j]);
			putstr("\n");
		}
		if (game->rooms[i]->door_up)
			putstr("door up\n");
		if (game->rooms[i]->door_down)
			putstr("door down\n");
		if (game->rooms[i]->door_left)
			putstr("door left\n");
		if (game->rooms[i]->door_right)
			putstr("door right\n");
		putstr("\n\n");
	}
}

static void set_room_cells(room_t *room)
{
	uint8_t nb_generated_maps = 0;

	while (rooms_setup[nb_generated_maps][0])
		nb_generated_maps++;
	room->cells = (char **) rooms_setup[rand_int(0, nb_generated_maps)];
}

static uint8_t find_room_pos(game_t *game, uint8_t id, uint8_t y)
{
	for (uint8_t i = 0; i < NB_ROOMS_WIDTH; i++) {
		if (game->dungeon->rooms[y][i] == id)
			return i;
	}
	return 0;
}

static void set_neighbor(game_t *game, room_t *room)
{
	uint8_t x = 0;
	uint8_t y = 0;

	for (; game->dungeon->rooms[y]; y++) {
		x = find_room_pos(game, room->id, y);
		if (game->dungeon->rooms[y][x] == room->id)
			break;
	}
	if (y != 0 && game->dungeon->rooms[y - 1][x] != -1)
		room->door_up = true;
	if (y != NB_ROOMS_HEIGHT - 1 && game->dungeon->rooms[y + 1][x] != -1)
		room->door_down = true;
	if (x != 0 && game->dungeon->rooms[y][x - 1] != -1)
		room->door_left = true;
	if (x != NB_ROOMS_WIDTH - 1 && game->dungeon->rooms[y][x + 1] != -1)
		room->door_right = true;
}

static bool init_all_rooms(win_t *win, char **map)
{
	for (size_t i = 0; i < win->game->dungeon->nb_rooms; i++) {
		win->game->rooms[i] = malloc(sizeof(room_t));
		if (!win->game->rooms[i])
			return false;
		win->game->rooms[i]->cells = map;
		win->game->rooms[i]->id = (uint8_t) i;
		win->game->rooms[i]->door_up = false;
		win->game->rooms[i]->door_down = false;
		win->game->rooms[i]->door_left = false;
		win->game->rooms[i]->door_right = false;
		set_neighbor(win->game, win->game->rooms[i]);
		set_room_cells(win->game->rooms[i]);
	}
	return true;
}

bool init_rooms(win_t *win)
{
	char **map = malloc(sizeof(char *) * ROOM_HEIGHT + 1);

	if (!map)
		return false;
	for (size_t i = 0; i < ROOM_HEIGHT; i++) {
		map[i] = malloc(sizeof(char) * ROOM_WIDTH + 1);
		if (!map[i])
			return false;
		memset(map[i], 'E', ROOM_WIDTH);
		map[i][ROOM_WIDTH] = '\0';
	}
	map[ROOM_HEIGHT] = NULL;
	win->game->rooms = malloc(sizeof(room_t *)
					* win->game->dungeon->nb_rooms);
	if (!win->game->rooms)
		return false;
	if (!init_all_rooms(win, map))
		return false;
	print_room(win->game);
	return true;
}
