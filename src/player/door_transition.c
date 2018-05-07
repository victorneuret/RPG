/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** door_action
*/

#include <SFML/Graphics.h>
#include <stdbool.h>

#include "render_window.h"
#include "render.h"
#include "dungeon.h"
#include "music.h"

void render_transition(win_t *win)
{
	if (win->game->dungeon->transition)
		render_object(win->sf_win,
					RECTANGLE, win->game->dungeon->shade);
}

void door_transition(dungeon_t *dungeon)
{
	sfColor color;

	if (dungeon->transition) {
		color = sfRectangleShape_getFillColor(dungeon->shade);
		color.a -= 10;
		if (color.a <= 10) {
			color.a = 255;
			dungeon->transition = false;
		}
		sfRectangleShape_setFillColor(dungeon->shade, color);
	}
}
