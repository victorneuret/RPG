/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** text_utils
*/

#include "text_utils.h"

sfText *init_text(sfFont *font, char *string, sfVector2f pos,
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
