/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** weather
*/

#pragma once

#include "render_window.h"

typedef struct render_window win_t;

typedef enum weather_intensity {
	LOWEST,
	LOW,
	NORMAL,
	HIGH,
	HIGHEST,
	INSANE,

	INTENSITY_COUNT
} weather_intensity_t;

typedef enum weather_type {
	CLEAR,
	RAIN,
	THUNDER,
	SNOW,

	WEATHER_COUNT
} weather_type_t;

typedef struct weather {
	weather_type_t weather_type;
	void (*update)(win_t *win);
} weather_t;

void update_weather(win_t *win);

void update_rain(win_t *win);

static const weather_t weather_list[] = {
	{RAIN,	&update_rain},
	{0,	NULL}
};