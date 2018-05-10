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

typedef struct stats_menu {
	sfRectangleShape *background;
	sfRectangleShape *separator;
	stats_t *stats;
} stats_menu_t;

bool init_stat_menu(win_t *win);
void draw_stat_menu(win_t *win, stats_menu_t *menu);
bool update_stat_menu(stats_menu_t *menu, player_t *player);
