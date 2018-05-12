/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** init_mini_map
*/

#include <SFML/Graphics.h>

#include <stdbool.h>

#include "dungeon.h"
#include "my_calloc.h"
#include "rectangle_utils.h"

static sfRectangleShape *init_rect(bool blank, uint8_t i, uint8_t j)
{
	sfColor color = (blank) ? hex_to_rgba(0xFFFFFF00)
				: hex_to_rgb(0x78909C);
	sfVector2f size = {48, 24};
	sfRectangleShape *rect = init_rectangle((sfVector2f)
		{j * size.x + 1500 + 2,
		i * size.y + 32 + 2}, size, color);

	if (!rect)
		return NULL;
	if (!blank) {
		sfRectangleShape_setOutlineColor(rect, hex_to_rgb(0x000000));
		sfRectangleShape_setOutlineThickness(rect, 2);
	}
	return rect;
}

bool init_mini_map(dungeon_t *dungeon)
{
	dungeon->map = my_calloc(sizeof(sfRectangleShape **), ROOM_HEIGHT);
	if (!dungeon->map)
		return false;
	for (size_t i = 0; i < NB_ROOMS_HEIGHT; i++) {
		dungeon->map[i] = my_calloc(sizeof(sfRectangleShape *),
		NB_ROOMS_WIDTH);
		if (!dungeon->map[i])
			return false;
		for (size_t j = 0; j < NB_ROOMS_WIDTH; j++) {
			dungeon->map[i][j] = (dungeon->rooms[i][j] == -1)
			? init_rect(true, i, j) : init_rect(false, i, j);
		}
	}
	return true;
}

static sfColor select_color(int8_t room_nb, room_t **rooms)
{
	sfColor color = hex_to_rgba(0xFFFFFF00);

	if (room_nb > 0)
		color = hex_to_rgb(0x393939);
	if (room_nb == 0)
		color = hex_to_rgb(0x4FC3F7);
	if (room_nb > 0 && rooms[room_nb]->cleared)
		color = hex_to_rgb(0x767676);
	return color;
}

static void update_mini_map(dungeon_t *dungeon, size_t y, size_t x,
				room_t **rooms)
{
	if (dungeon->rooms[y][x] != dungeon->act_room)
		return;
	for (size_t i = 0; i < NB_ROOMS_HEIGHT; i++) {
		for (size_t j = 0; j < NB_ROOMS_WIDTH; j++) {
			sfRectangleShape_setFillColor(dungeon->map[i][j],
			select_color(dungeon->rooms[i][j], rooms));
		}
	}
	sfRectangleShape_setFillColor(dungeon->map[y][x], hex_to_rgb(0xE3C6C5));
}

void draw_mini_map(dungeon_t *dungeon, win_t *win)
{
	for (size_t i = 0; i < NB_ROOMS_HEIGHT; i++)
		for (size_t j = 0; j < NB_ROOMS_WIDTH; j++)
			update_mini_map(dungeon, i, j, win->game->rooms);
	for (size_t i = 0; i < NB_ROOMS_HEIGHT; i++)
		for (size_t j = 0; j < NB_ROOMS_WIDTH; j++)
			sfRenderWindow_drawRectangleShape(win->sf_win,
						dungeon->map[i][j], 0);
}
