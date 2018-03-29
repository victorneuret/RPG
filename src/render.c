/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** render
*/

#include "render_window.h"
#include "render.h"


void render_object(sfRenderWindow *sf_win, shape_type type, void *obj_ptr)
{
	const sfFloatRect screen = (sfFloatRect) {0, 0, WIN_MAX_W, WIN_MAX_H};
	sfFloatRect obj_rect = {0};
	sfFloatRect inter = {0};

	if (type < 0 || type >= SHAPE_COUNT)
		return;
	obj_rect = shape_list[type].get_global_bounds(obj_ptr);
	if (!sfFloatRect_intersects(&obj_rect, &screen, &inter))
		return;
	shape_list[type].draw_shape(sf_win, obj_ptr, NULL);
}
