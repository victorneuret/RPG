/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** particle_manager
*/

#pragma once

#include "game/particles/particle.h"

sfRectangleShape *create_shape(particle_t *particle);
particle_group_t *get_particle_group(particle_manager_t *head);
