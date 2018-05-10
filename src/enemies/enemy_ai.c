/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** enemy_ai
*/

#include <SFML/Graphics.h>

#include "enemies.h"
#include "coord_utils.h"

static void move_ai(float dt, enemy_t *enemy, sfVector2f player_pos)
{
	sfVector2f dir;

	dir = get_direction(player_pos, enemy->pos);
	enemy->pos = (sfVector2f) {enemy->pos.x + dir.x * enemy->speed * dt,
				enemy->pos.y + dir.y * enemy->speed * dt};
	sfRectangleShape_setPosition(enemy->shape, enemy->pos);
}

void update_enemy_ai(float dt, enemy_t *enemy, sfVector2f player_pos)
{
	if (!enemy)
		return;
	move_ai(dt, enemy, player_pos);
}
