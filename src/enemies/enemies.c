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
#include "quest.h"
#include "xml.h"
#include "hud.h"

static sfRectangleShape *create_enemy_shape(sfVector2f pos, uint8_t type)
{
	const sfVector2f size = ENEMY_SIZE;
	sfRectangleShape *shape = sfRectangleShape_create();
	sfColor color = (sfColor) {100, 0, 255, 255};

	if (!shape)
		return NULL;
	sfRectangleShape_setPosition(shape, pos);
	switch (type) {
	case BALANCED: color = sfYellow; break;
	case HEAVY: color = (sfColor) {255, 100, 0, 255}; break;
	}
	sfRectangleShape_setFillColor(shape, color);
	sfRectangleShape_setSize(shape, size);
	sfRectangleShape_setOrigin(shape,
				(sfVector2f) {size.x / 2.f, size.y / 2.f});
	sfRectangleShape_setOutlineColor(shape, sfWhite);
	sfRectangleShape_setOutlineThickness(shape, 2);
	return shape;
}

void draw_enemies(sfRenderWindow *win, enemy_list_t *enemy_list)
{
	if (!enemy_list)
		return;
	for (enemy_list_t *node = enemy_list; node; node = node->next) {
		if (node->enemy) {
			render_object(win, RECTANGLE, node->enemy->shape);
			draw_bars(win, node->enemy);
		}
	}
}

void update_enemies(win_t *win, enemy_list_t *enemy_list,
		sounds_t *sounds, bool *door_open)
{
	static bool doors = false;

	if (!enemy_list)
		return;
	for (enemy_list_t *node = enemy_list; node; node = node->next) {
		if (!node->enemy)
			continue;
		if (node->enemy->hp <= 0) {
			enemy_killed(win, enemy_list, node);
			break;
		}
		update_enemy_ai(win, node->enemy, win->game->player);
		update_bars(node->enemy);
	}
	*door_open = enemy_list->enemy == NULL;
	if (*door_open && !doors) {
		play_sfx(sounds, OPEN);
		doors = true;
	} else if (!*door_open)
		doors = false;
}

void create_enemy(player_t *player, enemy_list_t **enemy_list,
							enemy_t *rdm_enemy)
{
	enemy_t *enemy = my_calloc(1, sizeof(enemy_t));

	if (!enemy || !rdm_enemy)
		return;
	enemy->type = rdm_enemy->type;
	enemy->hp_max = rdm_enemy->hp_max + (rdm_enemy->hp_max / 5)
			* player->level;
	enemy->hp = enemy->hp_max;
	enemy->attack = rdm_enemy->attack +
			(rdm_enemy->attack / 5) * player->level;
	enemy->speed += rdm_enemy->speed + (enemy->speed / 5) *
		(player->level > 6 ? 6 : player->level) + rand_int(0, 50);
	enemy->pos = (sfVector2f) {rand_int(600, 1400), rand_int(400, 600)};
	enemy->shape = create_enemy_shape(enemy->pos, enemy->type);
	enemy->bar_fg = get_bar(enemy->pos, ENEMY_SIZE, HP_COLOR);
	enemy->bar_bg = get_bar(enemy->pos, ENEMY_SIZE, BACK_BAR_COLOR);
	if (!enemy->shape || !enemy->bar_fg || !enemy->bar_bg) {
		free(enemy);
		return;
	}
	add_enemy_to_list(enemy_list, enemy);
}

void create_enemy_group(win_t *win, player_t *player,
			enemy_list_t **enemy_list, enemy_t **enemy_types)
{
	const int enemy_count = rand_int(4, 6);
	float rand_enemy;
	size_t enemy_index = 0;

	if (win->game->dungeon->act_room == 0)
		return;
	if (win->game->rooms[win->game->dungeon->act_room]->cleared)
		return;
	for (int i = 0; i < enemy_count; i++) {
		rand_enemy = (float) rand_int(0, 100);
		if (rand_enemy <= PROB_TANK)
			enemy_index = 2;
		else if (rand_enemy <= PROB_BALANCED)
			enemy_index = 1;
		else
			enemy_index = 0;
		create_enemy(player, enemy_list, enemy_types[enemy_index]);
	}
}
