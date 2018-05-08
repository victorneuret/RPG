/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** title_page
*/

#pragma once

#include <SFML/Graphics/Rect.h>

#include "buttons.h"
#include "texture.h"

static const float TITLE_SPEED = 75.0;
static const float OPTION_SPEED = 25.0;
static const float DEFAULT_SPEED = 25.0;

typedef enum title_menu {
	TITLE_OVERLAY,
	TITLE_BG,
	TITLE_MAIN,
	TITLE_OPTIONS
} title_menu;

static const sfIntRect title_rect[] = {
	{0, 0, 1920, 1080},
	{1920, 0, 1920, 1080},
	{0, 1080, 1920, 1080},
	{1920, 1080, 1920, 1080},
	{0, 0, 0, 0}
};

typedef struct title_page {
	sfSprite *overlay;
	sfSprite *background;
	sfSprite *menu_paper;
	sfSprite *pause;
	sfSprite *options;
} title_page_t;

title_page_t *init_title_page(textures_t *texture);
void update_title_page(win_t *win);
void buttons_parallax(win_t *win);
