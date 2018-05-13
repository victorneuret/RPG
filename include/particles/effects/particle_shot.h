/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** particle_shot
*/

#pragma once

#include "particle.h"
#include "inventory.h"

void update_particle_shot(win_t *win, particle_t *particle);
void create_shot(win_t *win, item_t *item, sfVector2f origin, float angle);
