/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** color utils header
*/

#pragma once

#include <stdint.h>
#include <stdbool.h>
#include <SFML/Graphics.h>

sfColor hex_to_rgb(int32_t hex);
sfColor hex_to_rgba(int32_t hex);
uint8_t get_particle_alpha(bool fade_in, bool fade_out,
			uint32_t current, uint32_t lifetime);
