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

typedef struct render_window win_t;

static const uint8_t INVENTORY_NB = 3;
static const uint8_t NB_ITEMS = 5;
static const char *INVENTORY_FONT __attribute__((unused)) =
					"res/fonts/space_mono_regular.ttf";
static const char *INVENTORY_MESSAGE __attribute__((unused)) =
					"Press I to pick up item";

typedef struct item {
	const char *name;
	sfSprite *sprite;
	sfVector2f pos;
	bool droped;
	float damages;
	float delay;
	uint8_t rate;
} item_t;

typedef struct inventory {
	uint8_t selected;
	sfText *text;
	sfText *message;
	sfFont *font;
	bool display_message;
	item_t **item;
	item_t *item_list;
} inventory_t;

typedef enum item_type {
	GUN,
	SHOTGUN,
	FLAMETHROWER,
	EMPTY
} item_type;

inventory_t *init_inventory(win_t *win);
void drop_item(win_t *win, inventory_t *inventory, uint8_t place);
void add_item(win_t *win, inventory_t *inventory, uint8_t place,
							item_type item_nb);
void draw_inventory(win_t *win, inventory_t *inventory);
uint8_t get_next_inventory(inventory_t *inventory, int8_t negative);
void free_inventory(inventory_t *inventory);
void get_item(win_t *win, inventory_t *inventory,
						sfSprite *player, bool pick_up);
void enemy_drop_item(sfVector2f enemy_pos, win_t *win);
