/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** options
*/

#include <stdbool.h>

#include "options.h"

void options_animation(sfSprite *sprite, win_t *win)
{
	sfVector2f scale = sfSprite_getScale(sprite);
	sfColor color = sfSprite_getColor(sprite);

	if (win->game_state != OPTION) {
		if (scale.x > 0) {
			scale.x -= 0.1;
			scale.y -= 0.1;
		}
		if (color.a > 0)
			color.a -= 17;
	} else {
		if (scale.x < 1) {
			scale.x += 0.07;
			scale.y += 0.07;
		}
		if (color.a < 255)
			color.a += 17;
	}
	sfSprite_setColor(sprite, color);
	sfSprite_setScale(sprite, scale);
}

void update_options_page(win_t *win)
{
	sfVector2f mouse = get_mouse_pos(win);
	sfVector2f vect = {900, 420};

	sfSprite_setPosition(win->game->ui->title_page->options,
	(sfVector2f) {mouse.x / 25 * -1, mouse.y / 25 * -1});
	options_animation(win->game->ui->title_page->options, win);
	for (buttons_t *tmp = win->game->ui->buttons; tmp; tmp = tmp->next) {
		if (tmp->game_state == OPTION) {
			sfSprite_setPosition(tmp->sprite,
				(sfVector2f) {mouse.x / 75 * -1 + vect.x,
				mouse.y / 75 * -1 + vect.y});
			vect.y += 80;
		}
	}
}
