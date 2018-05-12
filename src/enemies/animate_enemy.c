/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** animate_enemy
*/

#include <SFML/Graphics.h>

#include "enemies.h"
#include "player.h"
#include "render.h"

void animate_enemy(enemy_t *enemy)
{
	if (sfClock_getElapsedTime(enemy->enemy_clock).microseconds
							> 300000) {
		animate_sprite(enemy->sprite, 100, 4);
		sfClock_restart(enemy->enemy_clock);
	}
}

void draw_enemies(sfRenderWindow *win, enemy_list_t *enemy_list)
{
	if (!enemy_list)
		return;
	for (enemy_list_t *node = enemy_list; node; node = node->next) {
		if (node->enemy) {
			animate_enemy(node->enemy);
			render_object(win, SPRITE, node->enemy->sprite);
			draw_bars(win, node->enemy);
		}
	}
}
