/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** checkbox_functions
*/

#pragma once

#include <SFML/Graphics.h>
#include <stdbool.h>
#include <stdint.h>

#include "render_window.h"
#include "sprite_utils.h"
#include "buttons.h"

typedef struct render_window win_t;
typedef struct textures textures_t;
typedef struct checkbox checkbox_t;

void checkbox_fullscreen(win_t *win, checkbox_t *checkbox);
void change_resolution(win_t *win, checkbox_t *checkbox);

typedef struct checkbox {
	game_status game_state;
	sfText *text;
	sfColor color;
	sfColor hover_color;
	sfSprite *selected;
	sfSprite *unselected;
	sfVector2f pos;
	bool value;
	bool reset_scale;
	bool hover;
	sfClock *checkbox_clock;
	struct checkbox *next;
	struct checkbox *prev;
	void (*func)(win_t *win, checkbox_t *checkbox);
} checkbox_t;

typedef struct {
	game_status game_state;
	sfIntRect selected;
	sfIntRect unselected;
	sfVector2f pos;
	uint32_t color;
	uint32_t hover_color;
	bool value;
	void (*func)(win_t *win, checkbox_t *checkbox);
} checkbox_declaration_t;

static const checkbox_declaration_t checkbox_declaration[] = {
	{
		OPTION,
		(sfIntRect) {0, 0, 300, 70},
		(sfIntRect) {300, 0, 300, 70},
		(sfVector2f) {1200, 560},
		0x26A69AFF,
		0x26A69ABF,
		false,
		&change_resolution
	},
	{
		OPTION,
		(sfIntRect) {0, 0, 300, 70},
		(sfIntRect) {300, 0, 300, 70},
		(sfVector2f) {1200, 630},
		0x26A69AFF,
		0x26A69ABF,
		false,
		&checkbox_fullscreen
	},
	{
		0,
		(sfIntRect) {0, 0, 0, 0},
		(sfIntRect) {0, 0, 0, 0},
		(sfVector2f) {0, 0},
		0,
		0,
		false,
		NULL
	}
};

void checkbox_click_animation(checkbox_t *checkbox);
void checkbox_click_released(win_t *win, const sfEvent *event);
void checkbox_click_pressed(win_t *win, const sfEvent *event);
checkbox_t *load_checkbox(textures_t *textures);
void free_checkbox(checkbox_t *buttons);
void checkbox_animation(win_t *win);
void draw_checkbox(win_t *win);
void checkbox_click_animation(checkbox_t *checkbox);
sfSprite *get_checkbox_sprite(checkbox_t *checkbox);
