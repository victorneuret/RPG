/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** sprite_utils
*/

#include "sprite_utils.h"

sfSprite *get_sprite_texture_rect(const sfTexture *texture,
	const sfIntRect *rect)
{
	sfSprite *sprite = sfSprite_create();

	if (!sprite)
		return NULL;
	sfSprite_setTexture(sprite, texture, sfTrue);
	sfSprite_setTextureRect(sprite, *rect);
	return sprite;
}

sfSprite *create_sprite(const sfTexture *texture)
{
	sfSprite *sprite = sfSprite_create();

	if (!sprite)
		return NULL;
	sfSprite_setTexture(sprite, texture, sfTrue);
	return sprite;
}
