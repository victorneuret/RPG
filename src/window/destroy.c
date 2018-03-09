/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** destroy CSFML
*/

#include "window/destroy.h"

#include "game/particles/particle_destroyer.h"

void destroy_window(win_t *win)
{
	destroy_particle_manager(win->particle_manager);
	sfClock_destroy(win->timer);
	sfRenderWindow_destroy(win->sf_win);
	free(win);
}
