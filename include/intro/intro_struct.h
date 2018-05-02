/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** intro_struct
*/

#pragma once

#include <SFML/Graphics.h>

typedef enum intro_text {
	TEAM,
	PRESENT
} intro_text;

typedef struct {
	sfText *text[2];
	sfFont *intro_font;
	sfClock *timer;
	uint16_t i;
	uint16_t j;
} intro_t;
