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

static const int INVENTORY_NB = 4;
static const int NB_ITEMS = 4;

static const char *item_list[] __attribute__((unused)) = {
	"gun",
	"shotgun",
	"flamethrower",
	NULL
};

typedef struct item {
	const char *name;
	sfSprite *sprite;
	sfVector2f pos;
	bool droped;
	float damages;
	float delay;
} item_t;

typedef struct inventory {
	item_t *item[3];
	item_t *item_list;
} inventory_t;

inventory_t *init_inventory(win_t *win);
