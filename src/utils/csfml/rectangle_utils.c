/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** rectangle_utils
*/

#include "rectangle_utils.h"

sfRectangleShape *init_rectangle(sfVector2f pos, sfVector2f size,
				sfColor color)
{
	sfRectangleShape *rect = sfRectangleShape_create();

	if (!rect)
		return NULL;
	sfRectangleShape_setSize(rect, size);
	sfRectangleShape_setPosition(rect, pos);
	sfRectangleShape_setFillColor(rect, color);
	return rect;
}
