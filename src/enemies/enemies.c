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

void apply_type(sfSprite *sprite, uint8_t type)
{
	sfSprite_setColor(sprite, hex_to_rgba(0xFFFFFFFF));
	if (type == BALANCED) {
		sfSprite_setScale(sprite, (sfVector2f) {1.3, 1.3});
		sfSprite_setColor(sprite, hex_to_rgba(0x616161FF));
	} else if (type == HEAVY)
		sfSprite_setScale(sprite, (sfVector2f) {2, 2});
}

static sfSprite *create_enemy_sprite(enemy_t *enemy, uint8_t type,
				textures_t *textures)
{
	const sfIntRect rect = {0, 0, ENEMY_SIZE.x, ENEMY_SIZE.y};
	sfTexture *texture = get_texture(textures, "ghost")->texture;
	sfSprite *sprite;

	if (!texture)
		return NULL;
	sprite = get_sprite_texture_rect(texture, &rect);
	if (!sprite)
		return NULL;
	apply_type(sprite, type);
	sfSprite_setOrigin(sprite, (sfVector2f)
			{ENEMY_SIZE.x / 2.f, ENEMY_SIZE.y / 2.f});
	sfSprite_setPosition(sprite, enemy->pos);
	enemy->enemy_clock = sfClock_create();
	if (!enemy->enemy_clock)
		return false;
	return sprite;
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
				enemy_t *rdm_enemy, textures_t *textures)
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
	enemy->speed += (rdm_enemy->speed + enemy->speed) *
		(player->level > 12 ? 12 : player->level) * 0.2;
	enemy->pos = (sfVector2f) {rand_int(600, 1400), rand_int(400, 600)};
	enemy->sprite = create_enemy_sprite(enemy, enemy->type, textures);
	enemy->bar_fg = get_bar(enemy->pos, ENEMY_SIZE, HP_COLOR);
	enemy->bar_bg = get_bar(enemy->pos, ENEMY_SIZE, BACK_BAR_COLOR);
	if (!enemy->sprite || !enemy->bar_fg || !enemy->bar_bg) {
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
		create_enemy(player, enemy_list, enemy_types[enemy_index],
				win->game->textures);
	}
}
