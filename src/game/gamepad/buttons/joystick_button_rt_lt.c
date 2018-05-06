/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** joystick_button_rt_lt
*/

#include "joystick.h"

void button_lt(win_t *win, bool press)
{
	static bool pressed = false;

	if (!press) {
		pressed = false;
		return;
	} else if (!pressed && press) {
		if (win->game->dungeon->act_room != 0)
			win->game->dungeon->act_room--;
		pressed = true;
	}
}

void button_rt(win_t *win, bool press)
{
	static bool pressed = false;

	if (!press) {
		pressed = false;
		return;
	} else if (!pressed && press) {
		if (win->game->dungeon->act_room
			< win->game->dungeon->nb_rooms - 1)
			win->game->dungeon->act_room++;
		pressed = true;
	}
}
