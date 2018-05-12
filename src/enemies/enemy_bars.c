/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** enemy_bars
*/

#include <SFML/Graphics.h>

#include "enemies.h"
#include "render.h"

sfRectangleShape *get_bar(sfVector2f pos, sfVector2f size, sfColor color)
{
	sfRectangleShape *bar = sfRectangleShape_create();

	if (!bar)
		return NULL;
	sfRectangleShape_setPosition(bar, (sfVector2f)
				{pos.x, pos.y - BAR_HEIGHT - BAR_PADDING});
	sfRectangleShape_setSize(bar, (sfVector2f) {size.x, BAR_HEIGHT});
	sfRectangleShape_setFillColor(bar, color);
	return bar;
}

void draw_bars(sfRenderWindow *win, enemy_t const *enemy)
{
	if (!enemy)
		return;
	if (enemy->hp == enemy->hp_max)
		return;
	render_object(win, RECTANGLE, enemy->bar_bg);
	render_object(win, RECTANGLE, enemy->bar_fg);
}

void update_bars(enemy_t const *enemy)
{
	const double ratio = (double) enemy->hp / (double) enemy->hp_max;
	const sfVector2f size_max = sfRectangleShape_getSize(enemy->bar_bg);
	const sfVector2f pos = sfRectangleShape_getPosition(enemy->shape);
	const sfVector2f new_pos = (sfVector2f) {pos.x - ENEMY_SIZE.x / 2.f,
		pos.y - ENEMY_SIZE.x / 2.f - BAR_HEIGHT - BAR_PADDING};

	sfRectangleShape_setPosition(enemy->bar_bg, new_pos);
	sfRectangleShape_setPosition(enemy->bar_fg, new_pos);
	if (size_max.x * ratio > size_max.x)
		return;
	sfRectangleShape_setSize(enemy->bar_fg,
			(sfVector2f) {size_max.x * ratio, size_max.y});
}
