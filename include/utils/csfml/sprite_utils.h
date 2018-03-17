/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** sprite_utils
*/

#include <SFML/Graphics.h>

sfSprite *get_sprite_texture_rect(const sfTexture *texture,
	const sfIntRect *rect);
sfSprite *create_sprite(const sfTexture *texture);
