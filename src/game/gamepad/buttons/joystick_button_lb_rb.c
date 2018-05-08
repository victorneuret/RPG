/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** joystick_button_LB_RB
*/

#include "player.h"
#include "joystick.h"

void button_lb(__attribute__((unused)) win_t *win, bool press)
{
	static bool pressed = false;

	if (!press) {
		pressed = false;
		return;
	}
	if (!pressed && press)
		pressed = true;
}

void button_rb(__attribute__((unused)) win_t *win, bool press)
{
	static bool pressed = false;

	if (!press) {
		pressed = false;
		return;
	} else if (!pressed && press) {
		if (win->game_state == GAME)
			player_shoot(win, win->game->player);
		pressed = true;
	} else
		player_shoot(win, win->game->player);
}
