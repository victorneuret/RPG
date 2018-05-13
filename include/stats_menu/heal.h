/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** heal
*/

#pragma once

#include <SFML/Graphics.h>
#include <stdint.h>
#include <stdbool.h>

#include "render_window.h"

typedef struct heal {
	uint16_t delay_sec;
	float prct;
} heal_t;

void heal_player(win_t *win, heal_t *heal);
