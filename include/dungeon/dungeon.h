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

static const float ROCK_W = 118.5;
static const float ROCK_H = 100;
static const uint8_t WALL_SIZE_ROCK = 190;

typedef struct room {
	uint8_t id;
	char **cells;
	bool door_up;
	bool door_down;
	bool door_left;
	bool door_right;
	bool cleared;
} room_t;

typedef struct dungeon {
	int8_t **rooms;
	sfRectangleShape ***map;
	uint8_t nb_rooms;
	int8_t act_room;
	bool door_open;
	sfRectangleShape *shade;
	bool transition;
	bool cleared;
	sfSprite *portal;
} dungeon_t;

bool init_dungeon(win_t *win);
bool init_mini_map(dungeon_t *dungeon);
void free_dungeon(game_t *game);

bool init_rooms(win_t *win);
void place_rooms(dungeon_t *dungeon);

void print_dungeon(dungeon_t *dungeon);

void door_transition(dungeon_t *dungeon);
void render_transition(win_t *win);

bool init_portal(dungeon_t *dungeon, game_t *game);
void draw_portal(dungeon_t *dungeon, win_t *win);
void draw_mini_map(dungeon_t *dungeon, win_t *win);
