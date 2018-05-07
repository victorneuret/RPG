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
	uint8_t size;
	uint64_t elements;
	float max_value;
	float value;
	bool hover;
	void (*func)(win_t *win, slider_t *slider);
	struct slider *next;
} slider_t;

typedef struct slider_declaration {
	game_status game_state;
	sfColor color;
	sfColor hover_color;
	uint8_t size;
	uint64_t elements;
	float max_value;
	void (*func)(win_t *win, slider_t *slider);
} slider_declaration_t;

static const slider_declaration_t slider_declaration[] = {
	{
		OPTION,
		{0, 0, 0, 100},
		{0, 0, 0, 255},
		50,
		8,
		100,
		NULL
	},
	{
		0,
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		0,
		0,
		0,
		NULL
	}
};

slider_t *init_slider(void);
