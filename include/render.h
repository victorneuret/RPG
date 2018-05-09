/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** render
*/

#pragma once

#include "render_window.h"

typedef enum shape_type {
	CIRCLE,
	RECTANGLE,
	TEXT,
	SPRITE,
	CONVEX,
	SHAPE,

	SHAPE_COUNT
} shape_type;

typedef struct {
	shape_type type;
	void (*draw_shape)();
	sfFloatRect (*get_global_bounds)();
} shape_t;

static const shape_t shape_list[] = {
	{
		CIRCLE,
		&sfRenderWindow_drawCircleShape,
		&sfCircleShape_getGlobalBounds
	},
	{
		RECTANGLE,
		&sfRenderWindow_drawRectangleShape,
		&sfRectangleShape_getGlobalBounds
	},
	{
		TEXT,
		&sfRenderWindow_drawText,
		&sfText_getGlobalBounds
	},
	{
		SPRITE,
		&sfRenderWindow_drawSprite,
		&sfSprite_getGlobalBounds
	},
	{
		CONVEX,
		&sfRenderWindow_drawConvexShape,
		&sfConvexShape_getGlobalBounds
	},
	{
		SHAPE,
		&sfRenderWindow_drawShape,
		&sfShape_getGlobalBounds
	},
	{
		-1,
		NULL,
		NULL
	}
};

void render_object(sfRenderWindow *sf_win, shape_type type, void *obj_ptr);
void render(win_t *win);
