/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** coord_utils
*/

#pragma once

#include <SFML/Graphics.h>
#include <stdbool.h>

bool is_coord_equal(sfVector2f one, sfVector2f two);
bool is_coord_equal_i(sfVector2i one, sfVector2i two);
sfVector2f vec2i_to_2f(sfVector2i coord);
sfVector2i vec2f_to_2i(sfVector2f coord);
sfVector2f get_direction(sfVector2f from, sfVector2f to);
