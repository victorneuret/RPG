/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** player_utils
*/

#include <SFML/Graphics.h>
#include <stdbool.h>

#include "player.h"

void player_touched(player_t *player)
{
	sfColor color;

	if (player->touched && player->hp->value > 0) {
		color = sfRectangleShape_getFillColor(player->shade);
		color.a -= 5;
		if (color.a <= 5) {
			color.a = 150;
			player->touched = false;
		}
		sfRectangleShape_setFillColor(player->shade, color);
	}
}

bool is_player_immune(sfClock *timer)
{
	return sfTime_asSeconds(sfClock_getElapsedTime(timer)) < 1.f;
}
