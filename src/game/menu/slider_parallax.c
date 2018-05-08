/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** slider_parallax
*/

#include <SFML/Graphics.h>

#include "render_window.h"
#include "slider.h"

void slider_parallax(win_t *win, int speed, sfVector2f mouse)
{
	for (slider_t *tmp = win->game->ui->slider; tmp; tmp = tmp->next) {
		if (tmp->game_state == win->game_state) {
			sfText_setPosition(tmp->unselected,
				(sfVector2f) {mouse.x / speed * -1 + tmp->pos.x,
				mouse.y / speed * -1 + tmp->pos.y});
			sfText_setPosition(tmp->selected,
				(sfVector2f) {mouse.x / speed * -1 + tmp->pos.x,
				mouse.y / speed * -1 + tmp->pos.y});
		}
	}
}
