/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** text_utils
*/

#pragma once

#include <SFML/Graphics.h>
#include <stdint.h>

void center_text(sfText *text, float x);
void text_right(sfText *text, float x, float y);
sfText *init_text(sfFont *font, char const *string, sfVector2f pos,
		uint8_t font_size);
