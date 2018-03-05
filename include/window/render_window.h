/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** Struct window
*/

#pragma once

#include <SFML/Graphics.h>

#include "settings.h"

typedef struct render_window {
	float dt;
	size_t width;
	size_t height;
	settings_t *settings;
	sfClock *timer;
	sfRenderWindow *sf_win;
} win_t;

#include "window/destroy.h"

win_t *create_window(size_t width, size_t height, settings_t *settings);
