/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** door_action
*/

#include <SFML/Graphics.h>
#include <stdbool.h>

#include "render_window.h"
#include "dungeon.h"
#include "music.h"

static void move_room(win_t *win, room_t *room, int8_t x, int8_t y)
{
	int8_t **map = win->game->dungeon->rooms;
	size_t i = 0;

	for (size_t j = 0; j < NB_ROOMS_WIDTH && i < NB_ROOMS_HEIGHT; j++) {
		if (map[i][j] == room->id) {
			win->game->dungeon->act_room = map[i + y][j + x];
			win->game->dungeon->door_open = false;
			break;
		}
		if (j + 1 >= NB_ROOMS_WIDTH) {
			j = 0;
			i++;
		}
	}
	win->game->dungeon->transition = true;
}

static void set_sprite_pos(sfVector2f *pos, uint8_t dir, sounds_t *sounds)
{
	switch (dir) {
	case LEFT:
		pos->x = WIN_MAX_W - WALL_SIZE - PLAYER_W;
		break;
	case RIGHT:
		pos->x = WALL_SIZE;
		break;
	case TOP:
		pos->y = WIN_MAX_H - WALL_SIZE - PLAYER_H;
		break;
	case BOTTOM:
		pos->y = WALL_SIZE;
		break;
	default:
		pos->y = WIN_MAX_H / 2 + PLAYER_H / 2;
		pos->x = WIN_MAX_W / 2 + PLAYER_W / 2;
	}
	play_sfx(sounds, UNLOCKED);
}

static bool check_y_door(sfVector2f *pos)
{
	return ((pos->y + PLAYER_H / 2 > Y_DOOR_LEFT - 62
		&& pos->y + PLAYER_H / 2 < Y_DOOR_LEFT + 62)
		|| (pos->y + PLAYER_H > Y_DOOR_LEFT - 62
		&& pos->y + PLAYER_H < Y_DOOR_LEFT + 62));
}

static bool check_x_door(sfVector2f *pos)
{
	return ((pos->x > X_DOOR_UP - 62 && pos->x < X_DOOR_UP + 62)
		|| (pos->x + PLAYER_W > X_DOOR_UP - 62
		&& pos->x + PLAYER_W < X_DOOR_UP + 62));
}

void door_action(win_t *win, sfVector2f *pos, room_t *room)
{
	if (room->door_left && pos->x < WALL_SIZE && check_y_door(pos)) {
		move_room(win, room, -1, 0);
		set_sprite_pos(pos, LEFT, win->game->sounds);
	}
	if (room->door_right && pos->x + PLAYER_W > WIN_MAX_W - WALL_SIZE
		&& check_y_door(pos)) {
		move_room(win, room, 1, 0);
		set_sprite_pos(pos, RIGHT, win->game->sounds);
	}
	if (room->door_up && pos->y < WALL_SIZE && check_x_door(pos)) {
		move_room(win, room, 0, -1);
		set_sprite_pos(pos, TOP, win->game->sounds);
	}
	if (room->door_down && pos->y + PLAYER_H > WIN_MAX_H - WALL_SIZE - 16
		&& check_x_door(pos)) {
		move_room(win, room, 0, 1);
		set_sprite_pos(pos, BOTTOM, win->game->sounds);
	}
}
