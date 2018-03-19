/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** text_utils
*/

#pragma once

#include <SFML/Graphics.h>
#include <stdint.h>

sfText *init_text(sfFont *font, char *string, sfVector2f pos,
		uint8_t font_size);
