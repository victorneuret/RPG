/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** stats_menu
*/

#pragma once

#include <SFML/Graphics.h>

#include "hud.h"

typedef struct stats {
	sfSprite *player;
	sfText *slash;
	sfSprite *hp_sprite;
	sfText *hp;
	sfText *hp_max;
	sfSprite *xp_sprite;
	sfText *xp;
	sfText *xp_max;
	sfText *level_text;
	sfText *level;
	sfSprite *sp_sprite;
	sfText *sp;
} stats_t;

// typedef enum {
// 	UNLOCKED,
// 	LOCKED,
// 	DISABLED
// } skill_status_t;

// typedef struct skill {
// 	uint16_t x_pos;
// 	uint8_t y_pos[3];
// 	skill_status_t status[3];
// 	uint8_t level;
// } skill_t;

typedef struct skill_tree {
	sfSprite *sp;
	sfText *nb_sp;
	sfText *active;
	sfText *passive;
} skill_tree_t;

typedef struct stats_menu {
	sfRectangleShape *background;
	sfRectangleShape *separator;
	stats_t *stats;
	skill_tree_t *skill_tree;
} stats_menu_t;

bool init_stat_menu(win_t *win);
void draw_stat_menu(win_t *win, stats_menu_t *menu);
bool update_stat_menu(stats_menu_t *menu, player_t *player);
bool init_skill_tree(stats_menu_t *menu, game_t *game);
void draw_skill_tree(win_t *win, stats_menu_t *stats);
