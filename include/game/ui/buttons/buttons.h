/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** buttons
*/

#pragma once

#include "render_window.h"
#include "sprite_utils.h"
#include "str_utils.h"
#include "color_utils.h"
#include "key_pressed_functions.h"

typedef struct render_window win_t;
typedef struct textures textures_t;

#include "mouse_utils.h"

typedef struct buttons {
	game_status game_state;
	sfSprite *sprite;
	sfColor color;
	sfColor hover_color;
	char *text_hover;
	void (*func)(win_t *win);
	sfClock *button_clock;
	struct buttons *next;
} buttons_t;

typedef struct {
	game_status game_state;
	sfIntRect rect;
	sfVector2f pos;
	char *text_hover;
	uint32_t color;
	uint32_t hover_color;
	void (*func)(win_t *win);
} button_declaration_t;

static const button_declaration_t buttons_declaration[] = {
	{
		GAME | PAUSE,
		(sfIntRect) {64, 0, 64, 64},
		(sfVector2f) {-100, -100},
		"load",
		0x26A69AFF,
		0x26A69ABF,
		&pause_game
	},
	{
		ALL,
		(sfIntRect) {0, 0, 0, 0},
		(sfVector2f) {0, 0},
		NULL,
		0,
		0,
		NULL
	}
};

buttons_t *load_buttons(textures_t *textures);
void free_buttons(buttons_t *buttons);
void draw_buttons(win_t *win);
void button_animation(win_t *win);
void button_click_animation(buttons_t *button);
void button_click_released(win_t *win, const sfEvent *event);
void button_click_pressed(win_t *win, const sfEvent *event);
