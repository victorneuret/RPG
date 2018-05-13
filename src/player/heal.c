/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** heal
*/

#include <SFML/Graphics.h>

#include "heal.h"
#include "render_window.h"
#include "particle_heal.h"

void heal_player(win_t *win, heal_t *heal)
{
	particle_heal(win, win->game->player->hp->max_value * heal->prct,
			win->game->player->pos);
}
