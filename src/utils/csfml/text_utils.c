/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** text_utils
*/

#include <SFML/Graphics.h>
#include <stdint.h>

#include "text_utils.h"

void center_text(sfText *text, float x)
{
	sfFloatRect rect;

	rect = sfText_getLocalBounds(text);
	sfText_setOrigin(text, (sfVector2f) {rect.left + rect.width / 2,
		rect.top + rect.height / 2});
	sfText_setPosition(text, (sfVector2f) {1920 / 2, x});
}

sfText *init_text(sfFont *font, char const *string, sfVector2f pos,
		uint8_t font_size)
{
	sfText *text = sfText_create();

	if (!text)
		return NULL;
	sfText_setString(text, string);
	sfText_setFont(text, font);
	sfText_setCharacterSize(text, font_size);
	sfText_setColor(text, sfWhite);
	sfText_setPosition(text, pos);
	return text;
}
