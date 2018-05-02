/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** print_dungeon
*/

#include "dungeon.h"
#include "str_utils.h"

static void print_cells(int cell)
{
	if (cell == -1)
		printf("a\t");
	else
		printf("%d\t", cell);
}

void print_dungeon(dungeon_t *dungeon)
{
	for (size_t i = 0; i < NB_ROOMS_HEIGHT; i++) {
		for (size_t j = 0; j < NB_ROOMS_WIDTH; j++)
			print_cells(dungeon->rooms[i][j]);
		printf("\n");
	}
}
