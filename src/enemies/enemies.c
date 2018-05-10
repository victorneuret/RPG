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
#include "music.h"
#include "xml.h"

static sfRectangleShape *create_enemy_shape(sfVector2f pos, uint8_t type)
{
	const sfVector2f size = (sfVector2f) {100, 100};
	sfRectangleShape *shape = sfRectangleShape_create();
	sfColor color = sfCyan;

	if (!shape)
		return NULL;
	sfRectangleShape_setPosition(shape, pos);
	switch (type) {
	case BALANCED: color = sfYellow; break;
	case HEAVY: color = sfRed; break;
	}
	sfRectangleShape_setFillColor(shape, color);
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

void update_enemies(win_t *win, enemy_list_t *enemy_list,
		sounds_t *sounds, bool *door_open)
{
	static bool doors = false;

	if (!enemy_list)
		return;
	for (enemy_list_t *current = enemy_list; current;
						current = current->next) {
		if (current->enemy && current->enemy->hp <= 0) {
			particle_xp(win, 50, current->enemy->pos,
					hex_to_rgb(0xFFEB3B));
			play_sfx(sounds, DEATH);
			rm_enemy_from_list(&enemy_list, current->enemy);
			break;
		}
	}
	*door_open = enemy_list->enemy == NULL;
	if (*door_open && !doors) {
		play_sfx(sounds, OPEN);
		doors = true;
	} else if (!*door_open)
		doors = false;
}

void create_enemy(enemy_list_t **enemy_list, enemy_t *random_enemy)
{
	enemy_t *enemy = my_calloc(1, sizeof(enemy_t));

	if (!enemy || !random_enemy)
		return;
	enemy->type = random_enemy->type;
	enemy->attack = random_enemy->attack;
	enemy->hp = random_enemy->hp;
	enemy->hp_max = random_enemy->hp_max;
	enemy->attack = random_enemy->attack;
	enemy->pos = (sfVector2f) {rand_int(200, 1600), rand_int(200, 800)};
	enemy->shape = create_enemy_shape(enemy->pos, enemy->type);
	if (!enemy->shape) {
		free(enemy);
		return;
	}
	add_enemy_to_list(enemy_list, enemy);
}

void create_enemy_group(enemy_list_t **enemy_list, enemy_t **enemy_declaration)
{
	for (int i = 0; i < rand_int(4, 6); i++)
		create_enemy(enemy_list,
				enemy_declaration[rand_int(0, ENEMIES_NB)]);
}
