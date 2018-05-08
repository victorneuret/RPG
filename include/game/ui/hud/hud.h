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

typedef struct hp {
	uint16_t max_hp;
	int16_t hp;
	float hp_mult;
	sfRectangleShape *hp_bar;
	sfRectangleShape *hp_back_bar;
	sfText *text;
} hp_t;

void display_hp_bar(win_t *win);
bool init_hud(player_t *player);
void update_hp_bar(player_t *player);
