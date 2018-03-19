/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** ui
*/

#pragma once

#include "buttons.h"
#include "text_area.h"

typedef struct buttons buttons_t;
typedef struct text_area text_area_t;

typedef struct ui {
	buttons_t *buttons;
	text_area_t *text_area;
} ui_t;
