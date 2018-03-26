/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** coord_equal
*/

#include "render_window.h"

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
