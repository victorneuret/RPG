/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** checkbox_functions
*/

#pragma once

#include <SFML/Graphics.h>
#include <stdint.h>
#include <stdbool.h>

#include "render_window.h"

typedef struct slider slider_t;

typedef struct slider {
	game_status game_state;
	sfText *selected;
	sfText *unselected;
	sfColor color;
	sfColor hover_color;
	sfVector2f pos;
	uint8_t size;
	uint64_t elements;
	float max_value;
	float value;
	bool hover;
	void (*func)(win_t *win, float value);
	struct slider *next;
} slider_t;

typedef struct slider_declaration {
	game_status game_state;
	sfColor color;
	sfColor hover_color;
	sfVector2f pos;
	uint8_t size;
	uint64_t elements;
	float max_value;
	void (*func)(win_t *win, float value);
} slider_declaration_t;

void manage_sfx(win_t *win, float value);
void manage_music(win_t *win, float value);

static const slider_declaration_t slider_declaration[] = {
	{
		OPTION,
		{0, 0, 0, 25},
		{0, 0, 0, 255},
		{1100, 340},
		200,
		8,
		100,
		&manage_sfx
	},
	{
		OPTION,
		{0, 0, 0, 25},
		{0, 0, 0, 255},
		{1100, 410},
		200,
		8,
		100,
		&manage_music
	},
	{
		0,
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0},
		0,
		0,
		0,
		NULL
	}
};

slider_t *init_slider(void);
void draw_slider(win_t *win, slider_t *slider);
void slider_click_pressed(win_t *win, const sfEvent *event);
char *get_string_from_char(char c, uint8_t len);
