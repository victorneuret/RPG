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
	sfRectangleShape *rect;
	sfText *slash;
	sfSprite *hp_sprite;
	sfText *hp;
	sfText *hp_max;
	sfSprite *xp_sprite;
	sfText *xp;
	sfText *xp_max;
	sfText *level;
	sfText *skill_point;
} stats_t;

typedef struct stats_menu {
	sfRectangleShape *background;
	sfRectangleShape *separator;
	stats_t *stats;
} stats_menu_t;
