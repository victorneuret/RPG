/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** inventory
*/

#pragma once

#include <SFML/Graphics.h>
#include <stdint.h>
#include <stdbool.h>

#include "render_window.h"
#include "inventory.h"
#include "music.h"

typedef struct item_list {
	char *name;
	char *display_name;
	uint8_t sfx;
	uint8_t repeat;
	float delay;
	void (*func)(win_t *win, item_t *weapon, sfVector2f origin,
								float angle);
} item_list_t;

void create_shot(win_t *win, item_t *item, sfVector2f origin, float angle);
void rifle(win_t *win, item_t *weapon, sfVector2f origin, float angle);
void shotgun(win_t *win, item_t *weapon, sfVector2f origin, float angle);
void create_flame(win_t *win, item_t *weapon, sfVector2f origin, float angle);

static const item_list_t item_actions[] __attribute__((unused)) = {
	{"gun", "Bubble", WP_GUN, 1, 0, &create_shot},
	{"shotgun", "The Shotgun", WP_SHOTGUN, 20, 0, &shotgun},
	{"flamethrower", "Flamethrower", WP_FLAMETHROWER, 15, 350.f,
								&create_flame},
	{"uzi", "Uzi", WP_GUN, 1, 0, &rifle},
	{NULL, NULL, 0, 0, 0, NULL}
};
