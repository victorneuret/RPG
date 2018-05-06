/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** checkbox_functions
*/

#pragma once

#include <stdint.h>
#include <SFML/Graphics.h>
#include "render_window.h"

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
