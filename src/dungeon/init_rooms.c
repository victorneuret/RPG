/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** init_rooms
*/

#include <string.h>

#include "render_window.h"
#include "rooms.h"

// static void print_room(game_t *game)
// {
// 	for (size_t i = 0; i < game->dungeon->nb_rooms; i++) {
// 		printf("room: %ld\n", i);
// 		for (size_t j = 0; game->rooms[i]->cells[j]; j++) {
// 			putstr(game->rooms[i]->cells[j]);
// 			putstr("\n");
// 		}
// 		if (game->rooms[i]->door_up)
// 			putstr("door up\n");
// 		if (game->rooms[i]->door_down)
// 			putstr("door down\n");
// 		if (game->rooms[i]->door_left)
// 			putstr("door left\n");
// 		if (game->rooms[i]->door_right)
// 			putstr("door right\n");
// 		putstr("\n\n");
// 	}
// }

char **create_map(void)
{
	char **map = malloc(sizeof(char *) * ROOM_HEIGHT + sizeof(char *));

	if (!map)
		return NULL;
	for (size_t i = 0; i < ROOM_HEIGHT; i++) {
		map[i] = malloc(sizeof(char) * ROOM_WIDTH + 1);
		if (!map[i])
			return false;
		memset(map[i], 'E', ROOM_WIDTH);
		map[i][ROOM_WIDTH] = '\0';
	}
	map[ROOM_HEIGHT] = NULL;
	return map;
}

bool init_rooms(win_t *win)
{
	static char **map = NULL;

	if (!map) {
		map = create_map();
		if (!map)
			return false;
	}
	if (win->game->rooms) {
		for (size_t i = 0; win->game->rooms[i]; i++)
			free(win->game->rooms[i]);
		free(win->game->rooms);
	}
	win->game->rooms = malloc(sizeof(room_t *)
			* win->game->dungeon->nb_rooms + sizeof(room_t));
	if (!win->game->rooms)
		return false;
	win->game->rooms[0] = NULL;
	if (!init_all_rooms(win, map))
		return false;
	return true;
}
