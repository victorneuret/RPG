/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** rectangle_utils
*/

#pragma once

#include <SFML/Graphics.h>
#include "color_utils.h"

sfRectangleShape *init_rectangle(sfVector2f pos, sfVector2f size,
				sfColor color);
