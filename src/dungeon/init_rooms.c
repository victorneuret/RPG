/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** init_rooms
*/

#include <string.h>

#include "render_window.h"
#include "rooms.h"
#include "my_calloc.h"

char **create_map(void)
{
	char **map = my_calloc(ROOM_HEIGHT + 1, sizeof(char *));

	if (!map)
		return NULL;
	for (size_t i = 0; i < ROOM_HEIGHT; i++) {
		map[i] = my_calloc(ROOM_HEIGHT + 1, sizeof(char));
		if (!map[i])
			return false;
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
	win->game->rooms = my_calloc(win->game->dungeon->nb_rooms + 1,
					sizeof(room_t *));
	if (!win->game->rooms)
		return false;
	win->game->rooms[0] = NULL;
	if (!init_all_rooms(win, map) || !init_mini_map(win->game->dungeon))
		return false;
	return true;
}
