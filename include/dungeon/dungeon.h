/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** dungeon
*/

#pragma once

#include <stdint.h>
#include <stdbool.h>

#include "render_window.h"
#include "player.h"

#define ROOM_WIDTH 13
#define ROOM_HEIGHT 7

static const uint8_t NB_ROOMS_WIDTH = 8;
static const uint8_t NB_ROOMS_HEIGHT = 4;

typedef struct room {
	uint8_t id;
	char **cells;
	bool door_up;
	bool door_down;
	bool door_left;
	bool door_right;
} room_t;

typedef struct dungeon {
	int8_t **rooms;
	uint8_t nb_rooms;
} dungeon_t;

bool init_dungeon(win_t *win);
void print_dungeon(dungeon_t *dungeon);
bool init_rooms(win_t *win);
void free_dungeon(game_t *game);
