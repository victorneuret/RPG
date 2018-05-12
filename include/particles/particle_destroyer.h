/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** particle_destroyer
*/

#pragma once

#include "particle.h"

void remove_unactives(particle_manager_t *head);
void destroy_particle_group(particle_group_t *group);
void destroy_particle_manager(particle_manager_t *manager);
