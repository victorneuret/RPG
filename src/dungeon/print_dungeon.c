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
		printf("\t");
	else
		printf("%d\t", cell);
}

void print_dungeon(dungeon_t *dungeon)
{
	for (size_t i = 0; i < (size_t) (NB_ROOMS_WIDTH * 8 + 1); i++)
		printf("-");
	printf("\n");
	for (size_t i = 0; i < NB_ROOMS_HEIGHT; i++) {
		printf("|");
		for (size_t j = 0; j < NB_ROOMS_WIDTH; j++)
			print_cells(dungeon->rooms[i][j]);
		printf("|\n");
	}
	for (size_t i = 0; i < (size_t) (NB_ROOMS_WIDTH * 8 + 1); i++)
		printf("-");
	printf("\n");
}
