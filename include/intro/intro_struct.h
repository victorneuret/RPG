/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** intro_struct
*/

#pragma once

#include <SFML/Graphics.h>


static const char INTRO_FONT[] = "res/fonts/isaac_sans.ttf";
static const char TEAM_TEXT[] = "CROCUS CLAN";
static const char PRESENT_TEXT[] = "PRESENTS";

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
