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

static const float HP_WIDTH_MULT = 1.4;
static const uint8_t HP_HEIGHT = 16;

typedef struct hud {
	sfRectangleShape *hp_bar;
	sfRectangleShape *hp_back_bar;
} hud_t;

void display_hp_bar(win_t *win);
bool init_hud(player_t *player);
