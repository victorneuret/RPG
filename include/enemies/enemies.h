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

static const sfVector2f ENEMY_SIZE = (sfVector2f) {100, 100};

static const uint16_t ENEMIES_NB = 3;

static const float PROB_TANK = 16.666666666666664f;
static const float PROB_BALANCED = 50.f;
static const float PROB_LIGHT = 100.f;

static const float BAR_HEIGHT = 20.f;
static const float BAR_PADDING = 15.f;

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
} enemy_type_t;

typedef struct enemy {
	enemy_type_t type;
	sfSprite *sprite;
	sfRectangleShape *bar_bg;
	sfRectangleShape *bar_fg;
	sfVector2f pos;
	sfClock *enemy_clock;
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
void animate_enemy(enemy_t *enemy);
void create_enemy(player_t *player, enemy_list_t **enemy_list,
				enemy_t *random_enemy, textures_t *textures);
void create_enemy_group(win_t *win, player_t *player,
			enemy_list_t **enemy_list, enemy_t **enemy_types);

void add_enemy_to_list(enemy_list_t **enemy_list, enemy_t *enemy);
void rm_enemy_from_list(enemy_list_t **enemy_list, enemy_t *enemy);
void nuke_enemies(enemy_list_t *enemy_list);

void enemy_killed(win_t *win, enemy_list_t *enemy_list, enemy_list_t *node);

sfRectangleShape *get_bar(sfVector2f pos, sfVector2f size, sfColor color);
void draw_bars(sfRenderWindow *win, enemy_t const *enemy);
void update_bars(enemy_t const *enemy);
