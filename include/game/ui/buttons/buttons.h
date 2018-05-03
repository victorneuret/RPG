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

typedef struct hover_text_button {
	sfRectangleShape *rect;
	sfFont *font;
	sfText *text;
} text_hover_button_t;

typedef struct checkbox {
	game_status game_state;
	sfText *text;
	sfColor color;
	sfColor hover_color;
	bool value;
	bool hover;
	struct checkbox *next;
} checkbox_t;

typedef struct slider {
	game_status game_state;
	sfText *selected;
	sfText *unselected;
	sfColor color;
	sfColor hover_color;
	uint8_t size;
	uint64_t elements;
	float max_value;
	float value;
	bool hover;
	struct slider *next;
} slider_t;

typedef struct buttons {
	game_status game_state;
	sfSprite *sprite;
	sfColor color;
	sfColor hover_color;
	bool reset_scale;
	bool hover;
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

#include "menu_button_functions.h"

static const button_declaration_t buttons_declaration[] = {
	{
		TITLE,
		(sfIntRect) {0, 0, 300, 70},
		(sfVector2f) {900, 420},
		"",
		0x26A69AFF,
		0x26A69ABF,
		&start_game
	},
	{
		TITLE,
		(sfIntRect) {300, 0, 300, 70},
		(sfVector2f) {900, 500},
		"",
		0x26A69AFF,
		0x26A69ABF,
		&error_test
	},
	{
		TITLE,
		(sfIntRect) {600, 0, 300, 70},
		(sfVector2f) {900, 580},
		"",
		0x26A69AFF,
		0x26A69ABF,
		&to_option_menu
	},
	{
		TITLE,
		(sfIntRect) {900, 0, 300, 70},
		(sfVector2f) {900, 660},
		"",
		0x26A69AFF,
		0x26A69ABF,
		&close_win
	},
	{
		GAME,
		(sfIntRect) {64, 0, 64, 64},
		(sfVector2f) {1879, 1038},
		"Pause menu",
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
void update_button(buttons_t *button, win_t *win);
void update_text_hover(text_hover_button_t *hover, win_t *win);
text_hover_button_t *init_text_button(void);
void draw_text_hover_button(text_hover_button_t *hover, win_t *win);
void free_hover_text_button(text_hover_button_t *hover);
