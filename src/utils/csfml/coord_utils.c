/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** coord_equal
*/

#include <SFML/Graphics.h>
#include <stdbool.h>

#include "macros.h"

bool is_coord_equal(sfVector2f one, sfVector2f two)
{
	if (one.x != two.x)
		return false;
	if (one.y != two.y)
		return false;
	return true;
}

bool is_coord_equal_i(sfVector2i one, sfVector2i two)
{
	if (one.x != two.x)
		return false;
	if (one.y != two.y)
		return false;
	return true;
}

sfVector2f vec2i_to_2f(sfVector2i coord)
{
	return ((sfVector2f) {coord.x, coord.y});
}

sfVector2i vec2f_to_2i(sfVector2f coord)
{
	return ((sfVector2i) {coord.x, coord.y});
}

sfVector2f get_direction(sfVector2f from, sfVector2f to)
{
	float total = 0.0;
	sfVector2f absolute_dir = {0.0, 0.0};
	sfVector2f relative_dir = {0.0, 0.0};

	absolute_dir.x = from.x - to.x;
	absolute_dir.y = from.y - to.y;
	total = ABS(absolute_dir.x) + ABS(absolute_dir.y);
	relative_dir.x = absolute_dir.x / total;
	relative_dir.y = absolute_dir.y / total;
	return relative_dir;
}
