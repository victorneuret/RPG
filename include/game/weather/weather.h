/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** weather
*/

#pragma once

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
