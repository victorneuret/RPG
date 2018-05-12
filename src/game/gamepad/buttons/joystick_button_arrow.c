/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** joystick_button_arrow
*/

#include "joystick.h"
#include "events.h"
#include "render_window.h"

void button_left(win_t *win)
{
	static sfClock *timer;
	uint32_t current_time = timer ? sfTime_asMilliseconds(
				sfClock_getElapsedTime(timer)) : 0;

	if (!timer)
		timer = sfClock_create();
	if (current_time < 150.f)
		return;
	if (win->game_state == GAME)
		win->game->player->inventory->selected =
			get_next_inventory(win->game->player->inventory, 1);
	sfClock_restart(timer);
}

void button_right(win_t *win)
{
	static sfClock *timer;
	uint32_t current_time = timer ? sfTime_asMilliseconds(
				sfClock_getElapsedTime(timer)) : 0;

	if (!timer)
		timer = sfClock_create();
	if (current_time < 150.f)
		return;
	if (win->game_state == GAME)
		win->game->player->inventory->selected =
		get_next_inventory(win->game->player->inventory, -1);
	sfClock_restart(timer);
}
