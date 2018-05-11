/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** enemies
*/

#pragma once

#include <SFML/Graphics.h>
#include <stdint.h>
#include <stdbool.h>

#include "music.h"
#include "player.h"
#include "render_window.h"

typedef struct sounds sounds_t;
typedef struct player player_t;
typedef struct render_window win_t;

static const uint16_t ENEMIES_NB = 3;

static const char *enemies_name[] __attribute__((unused)) = {
	"light",
	"balanced",
	"heavy",
	NULL
};

typedef enum enemy_type {
	LIGHT,
	BALANCED,
	HEAVY
} ENEMY_TYPE;

typedef struct enemy {
	ENEMY_TYPE type;
	sfRectangleShape *shape;
	sfVector2f pos;
	uint64_t hp;
	uint64_t hp_max;
	uint64_t attack;
	float speed;
} enemy_t;

typedef struct enemy_list {
	enemy_t *enemy;
	struct enemy_list *next;
} enemy_list_t;

void update_enemy_ai(win_t *win, enemy_t *enemy, player_t *player);
void update_enemies(win_t *win, enemy_list_t *enemy_list, sounds_t *sounds,
							bool *door_open);
void draw_enemies(sfRenderWindow *win, enemy_list_t *enemy_list);
void create_enemy(player_t *player, enemy_list_t **enemy_list,
							enemy_t *random_enemy);
void create_enemy_group(player_t *player, enemy_list_t **enemy_list,
						enemy_t **enemies_declaration);

void add_enemy_to_list(enemy_list_t **enemy_list, enemy_t *enemy);
void rm_enemy_from_list(enemy_list_t **enemy_list, enemy_t *enemy);
void nuke_enemies(enemy_list_t *enemy_list);
