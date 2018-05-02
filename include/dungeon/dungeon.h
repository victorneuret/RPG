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

static const uint8_t ROOM_WIDTH = 12;
static const uint8_t ROOM_HEIGHT = 8;

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
} dungeon_t;

bool init_dungeon(win_t *win);
void print_dungeon(dungeon_t *dungeon);
