/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** heal
*/

#include <SFML/Graphics.h>

#include "heal.h"
#include "render_window.h"
#include "particle_heal.h"

void heal_player(win_t *win, heal_t *heal)
{
	const player_t *player = win->game->player;

	if (!heal->timer) {
		heal->timer = sfClock_create();
		if (!heal->timer)
			return;
	}
	if (!heal->unlocked || player->hp->value >= player->hp->max_value)
		return;
	if (sfTime_asSeconds(sfClock_getElapsedTime(heal->timer))
						< heal->delay_sec)
		return;
	particle_heal(win, player->hp->max_value * heal->prct, player->pos);
	sfClock_restart(heal->timer);
}
