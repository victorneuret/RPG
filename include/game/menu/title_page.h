/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** title_page
*/

#pragma once

#include "buttons.h"
#include "texture.h"

typedef struct title_page {
	sfSprite *background;
	sfSprite *earth;
} title_page_t;

title_page_t *init_title_page(textures_t *texture);
void update_title_page(win_t *win);
