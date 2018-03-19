/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** text_area
*/

#pragma once

#include <stdint.h>

#include "render_window.h"
#include "rectangle_utils.h"
#include "text_utils.h"
#include "color_utils.h"

typedef struct render_window win_t;

typedef struct text_area {
	game_status game_state;
	sfRectangleShape *box;
	uint8_t nb_char_max;
	sfFont *font;
	sfText *text;
	sfText *label;
	char *input_text;
	char *text_label;
	struct text_area *next;
} text_area_t;

typedef struct {
	game_status game_state;
	sfVector2f pos;
	sfVector2f size;
	char *path_to_font;
	uint8_t font_size;
	char *text_label;
	uint32_t text_area_color;
	uint32_t text_color;
	void (*func)(win_t *win);
} text_area_declaration_t;

static const text_area_declaration_t text_area_declaration[] = {
	{
		GAME,
		(sfVector2f) {80, 10},
		(sfVector2f) {180, 15},
		"res/fonts/space_mono_regular.ttf",
		13,
		"test text area",
		0x000000FF,
		0xFFFFFFFF,
		NULL
	},
	{
		ALL,
		(sfVector2f) {0, 0},
		(sfVector2f) {0, 0},
		NULL,
		0,
		NULL,
		0,
		0,
		NULL
	}
};

text_area_t *load_text_area(void);
void free_text_area(text_area_t *text_area);
