/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** backgrounds
*/

#include "my_rpg.h"

void update_fireworks(win_t *win)
{
	static sfClock *timer;
	static uint16_t index = 0;
	const sfColor colors[] = {
		sfRed, sfGreen,
		sfBlue, sfYellow,
		sfMagenta, sfCyan
	};
	uint32_t current_time = timer ? sfTime_asMilliseconds(
				sfClock_getElapsedTime(timer)) : 0;
	sfVector2f pos = (sfVector2f) {rand_int(0, WIN_MAX_W),
					rand_int(0, WIN_MAX_H)};

	if (!timer)
		timer = sfClock_create();
	if (current_time >= 200) {
		create_explosion(win, 100, pos, colors[(++index) % 6]);
		sfClock_restart(timer);
	}
}

void update_campfire(win_t *win)
{
	static sfClock *timer;
	uint32_t current_time = timer ? sfTime_asMilliseconds(
				sfClock_getElapsedTime(timer)) : 0;

	if (!timer)
		timer = sfClock_create();
	if (current_time >= 25) {
		for (size_t i = 0; i < 25; i++)
			create_fire_particle(win,
			(sfVector2f) {rand_int(0, WIN_MAX_W), WIN_MAX_H});
		sfClock_restart(timer);
	}
}
