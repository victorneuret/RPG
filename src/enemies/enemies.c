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
#include "nb_utils.h"
#include "my_calloc.h"
#include "particle_xp.h"

static sfRectangleShape *create_enemy_shape(sfVector2f pos)
{
	const sfVector2f size = (sfVector2f) {100, 100};
	sfRectangleShape *shape = sfRectangleShape_create();

	if (!shape)
		return NULL;
	sfRectangleShape_setPosition(shape, pos);
	sfRectangleShape_setFillColor(shape, sfCyan);
	sfRectangleShape_setSize(shape, size);
	sfRectangleShape_setOrigin(shape,
				(sfVector2f) {size.x / 2.f, size.y / 2.f});
	sfRectangleShape_setOutlineColor(shape, sfBlue);
	sfRectangleShape_setOutlineThickness(shape, 2);
	return shape;
}

void draw_enemies(sfRenderWindow *win, enemy_list_t *enemy_list)
{
	if (!enemy_list)
		return;
	for (enemy_list_t *current = enemy_list; current;
						current = current->next)
		if (current->enemy)
			render_object(win, RECTANGLE, current->enemy->shape);
}

void update_enemies(win_t *win, enemy_list_t *enemy_list, bool *door_open)
{
	if (!enemy_list)
		return;
	for (enemy_list_t *current = enemy_list; current;
						current = current->next) {
		if (current->enemy && current->enemy->hp <= 0) {
			particle_xp(win, 50, current->enemy->pos,
					hex_to_rgb(0xFFEB3B));
			rm_enemy_from_list(&enemy_list, current->enemy);
			break;
		}
	}
	*door_open = enemy_list->enemy == NULL;
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

void create_enemy_group(enemy_list_t **enemy_list)
{
	for (int i = 0; i < rand_int(4, 6); i++)
		create_enemy(enemy_list,
			(sfVector2f) {rand_int(200, 1600), rand_int(200, 800)});
}
