/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** animate_enemy
*/

#include <SFML/Graphics.h>

#include "enemies.h"
#include "player.h"

void animate_enemy(enemy_t *enemy)
{
	if (sfClock_getElapsedTime(enemy->enemy_clock).microseconds
							> 300000) {
		animate_sprite(enemy->sprite,
			sfSprite_getGlobalBounds(enemy->sprite).width, 4);
		sfClock_restart(enemy->enemy_clock);
	}
}
