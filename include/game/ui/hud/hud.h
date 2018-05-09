/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** hud
*/

#pragma once

#include <SFML/Graphics.h>

#include <stdint.h>

#include "player.h"
#include "render_window.h"

typedef struct player player_t;

static const uint16_t HP_HEIGHT = 32;
static const uint16_t HP_WIDTH = 400;

static const uint16_t XP_HEIGHT = 10;
static const uint16_t XP_WIDTH = 1920;

typedef struct bar {
	uint16_t max_value;
	int16_t value;
	float mult;
	sfRectangleShape *bar;
	sfRectangleShape *back_bar;
	sfText *text;
} bar_t;

void display_hp_bar(win_t *win);
bool init_hud(player_t *player);

void display_xp_bar(win_t *win);
