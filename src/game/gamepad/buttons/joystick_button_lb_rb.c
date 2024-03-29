/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** joystick_button_LB_RB
*/

#include "player.h"
#include "joystick.h"

void button_lb(win_t *win, bool press)
{
	static bool pressed = false;

	if (win->game_state == GAME && win->game->player->alive)
		player_dash(win, win->game->player, press, pressed);
	if (!press)
		pressed = false;
	if (!pressed && press)
		pressed = true;
}

void button_rb(win_t *win, bool press)
{
	static bool pressed = false;

	win->game->player->shooting = press;
	if (press && win->game_state == GAME && win->game->player->alive)
		player_shoot(win, win->game->player);
	if (!press) {
		pressed = false;
		return;
	} else if (!pressed && press) {
		pressed = true;
	}
}
