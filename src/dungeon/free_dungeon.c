/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** free_dungeon
*/

#include <unistd.h>

#include "dungeon.h"

void free_dungeon(game_t *game)
{
	for (size_t i = 0; i < NB_ROOMS_HEIGHT; i++)
		free(game->dungeon->rooms[i]);
	free(game->dungeon->rooms);
	for (size_t i = 0; i < game->dungeon->nb_rooms; i++) {
		free(game->rooms[i]);
	}
	free(game->dungeon);
}
