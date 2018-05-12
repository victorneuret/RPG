/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** skills
*/

#pragma once

#include <stdbool.h>
#include <SFML/Graphics.h>

#include "render_window.h"
#include "stats_menu.h"
#include "player.h"

static const float DASH_MULT = 0.015;
static const float DASH_DISTANCE = 20;
static const float DASH_DELAY = 10;

typedef struct skill_tree skill_tree_t;

typedef struct dash {
	float delay;
	float distance;
	bool display;
	bool unlocked;
	sfSprite *sprite;
	uint32_t current_time;
} dash_t;

void draw_dash(win_t *win, player_t *player);
bool init_dash_sprite(skill_tree_t *skill_tree, sfTexture *tex);
void player_dash(win_t *win, player_t *player, bool press, bool pressed);
