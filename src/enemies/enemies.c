/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** enemies
*/

#include <SFML/Graphics.h>
#include <stdint.h>
#include <stdlib.h>

#include "render.h"
#include "enemies.h"
#include "my_calloc.h"

static sfRectangleShape *create_enemy_shape(sfVector2f pos)
{
	sfRectangleShape *shape = sfRectangleShape_create();

	if (!shape)
		return NULL;
	sfRectangleShape_setPosition(shape, pos);
	sfRectangleShape_setFillColor(shape, sfCyan);
	sfRectangleShape_setSize(shape, (sfVector2f) {100, 100});
	sfRectangleShape_setOutlineColor(shape, sfBlue);
	sfRectangleShape_setOutlineThickness(shape, 2);
	return shape;
}

void draw_enemies(sfRenderWindow *win, enemy_list_t *enemy_list)
{
	if (!enemy_list)
		return;
	for (enemy_list_t *enemy = enemy_list; enemy; enemy = enemy->next)
		render_object(win, RECTANGLE, enemy->enemy->shape);
}

void create_enemy(enemy_list_t **enemy_list, sfVector2f pos)
{
	static uint32_t multiplicator = 1.0f;
	enemy_t *enemy = my_calloc(1, sizeof(enemy_t));

	if (!enemy)
		return;
	enemy->pos = pos;
	enemy->hp = 100 * multiplicator;
	enemy->hp_max = enemy->hp;
	enemy->attack = 20 * multiplicator;
	enemy->shape = create_enemy_shape(pos);
	multiplicator += 0.1f;
	if (!enemy->shape) {
		free(enemy);
		return;
	}
	add_enemy_to_list(enemy_list, enemy);
}
