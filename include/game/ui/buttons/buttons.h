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
#include "checkbox.h"
#include "checkbox.h"

typedef struct render_window win_t;
typedef struct textures textures_t;
typedef struct checkbox checkbox_t;

#include "mouse_utils.h"

typedef struct hover_text_button {
	sfRectangleShape *rect;
	sfFont *font;
	sfText *text;
} text_hover_button_t;

typedef struct buttons {
	game_status game_state;
	sfSprite *sprite;
	sfColor color;
	sfVector2f pos;
	sfColor hover_color;
	bool reset_scale;
	bool hover;
	bool selected;
	char *text_hover;
	void (*func)(win_t *win);
	sfClock *button_clock;
	struct buttons *next;
	struct buttons *prev;
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
#include "skills.h"

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
		STATS,
		(sfIntRect) {0, 128, 128, 128},
		(sfVector2f) {1065, 365},
		"HP: level 3\n+1200",
		0x00000000,
		0xFFEE5844,
		&hp_level_three
	},
	{
		STATS,
		(sfIntRect) {0, 128, 128, 128},
		(sfVector2f) {1065, 565},
		"HP: level 2\n+600",
		0x00000000,
		0xFFEE5844,
		&hp_level_two
	},
	{
		STATS,
		(sfIntRect) {0, 128, 128, 128},
		(sfVector2f) {1065, 765},
		"HP: level 1\n+250",
		0x00000000,
		0xFFEE5844,
		&hp_level_one
	},
	{
		STATS,
		(sfIntRect) {0, 128, 128, 128},
		(sfVector2f) {1265, 365},
		"Damage: level 3\n+8 per bullet",
		0x00000000,
		0xFFEE5844,
		&weapon_level_three
	},
	{
		STATS,
		(sfIntRect) {0, 128, 128, 128},
		(sfVector2f) {1265, 565},
		"Damage: level 2\n+4 per bullet",
		0x00000000,
		0xFFEE5844,
		&weapon_level_two
	},
	{
		STATS,
		(sfIntRect) {0, 128, 128, 128},
		(sfVector2f) {1265, 765},
		"Damage: level 1\n+2 per bullet",
		0x00000000,
		0xFFEE5844,
		&weapon_level_one
	},
	{
		STATS,
		(sfIntRect) {0, 128, 128, 128},
		(sfVector2f) {1515, 365},
		"Dash: level 3\n+2m",
		0x00000000,
		0xFFEE5844,
		NULL
	},
	{
		STATS,
		(sfIntRect) {0, 128, 128, 128},
		(sfVector2f) {1515, 565},
		"Dash: level 2\n+2m",
		0x00000000,
		0xFFEE5844,
		NULL
	},
	{
		STATS,
		(sfIntRect) {0, 128, 128, 128},
		(sfVector2f) {1515, 765},
		"Dash: level 1\nUnlock dash (2m)",
		0x00000000,
		0xFFEE5844,
		NULL
	},
	{
		STATS,
		(sfIntRect) {0, 128, 128, 128},
		(sfVector2f) {1715, 365},
		"Heal: level 3\n+200HP -2s",
		0x00000000,
		0xFFEE5844,
		NULL
	},
	{
		STATS,
		(sfIntRect) {0, 128, 128, 128},
		(sfVector2f) {1715, 565},
		"Heal: level 2\n+200HP",
		0x00000000,
		0xFFEE5844,
		NULL
	},
	{
		STATS,
		(sfIntRect) {0, 128, 128, 128},
		(sfVector2f) {1715, 765},
		"Heal: level 1\nUnlock heal (200HP)",
		0x00000000,
		0xFFEE5844,
		NULL
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

/* Buttons */
buttons_t *load_buttons(textures_t *textures);
void free_buttons(buttons_t *buttons);
void box(win_t *win);
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
