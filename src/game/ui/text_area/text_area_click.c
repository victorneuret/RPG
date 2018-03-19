/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** text_area_click
*/

#include "text_area.h"

static bool check_text_box_hit_box(text_area_t *text_area, win_t *win)
{
	sfFloatRect rect = sfRectangleShape_getGlobalBounds(text_area->box);
	sfVector2f mouse = get_mouse_pos(win);

	if (mouse.x >= rect.left && mouse.x <= rect.left + rect.width
		&& mouse.y >= rect.top && mouse.y <= rect.top + rect.height) {
		return true;
	}
	return false;
}


static void reset_box_size(text_area_t *text_area)
{
	int i = 0;
	sfVector2f scale = (sfVector2f) {1, 1};


	for (text_area_t *tmp = text_area; tmp; tmp = tmp->next) {
		sfRectangleShape_setScale(tmp->box, scale);
		i++;
	}
}

static void disable_text_area(text_area_t *text_area)
{
	for (text_area_t *tmp = text_area; tmp; tmp = tmp->next) {
		if (tmp->active)
			tmp->active = false;
		reset_box_size(tmp);
	}
}

static void change_box_size(text_area_t *text_area)
{
	sfVector2f scale = (sfVector2f) {1.04, 1.04};

	sfRectangleShape_setScale(text_area->box, scale);
}

bool text_area_click(win_t *win)
{
	for (text_area_t *tmp = win->game->ui->text_area; tmp;
		tmp = tmp->next) {
		if (check_text_box_hit_box(tmp, win)) {
			disable_text_area(win->game->ui->text_area);
			tmp->active = true;
			change_box_size(tmp);
			return true;
		}
		tmp->active = false;
	}
	reset_box_size(win->game->ui->text_area);
	return false;
}
