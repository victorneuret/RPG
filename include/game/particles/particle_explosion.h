/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** particle_explosion
*/

#pragma once

#include "game/particles/particle.h"

void create_explosion(win_t *win, uint16_t count,
		sfVector2f origin, sfColor color);
