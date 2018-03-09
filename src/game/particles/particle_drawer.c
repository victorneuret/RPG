/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** particle_drawer
*/

#include "game/particles/particle.h"

static void draw_particle_group(win_t *win, particle_group_t *group)
{
	for (size_t i = 0; group->particles[i]; i++)
		if (group->particles[i]->alive)
			sfRenderWindow_drawRectangleShape(win->sf_win,
					group->particles[i]->shape, NULL);
}

void draw_particles(win_t *win)
{
	particle_manager_t *current = win->particle_manager;

	for (; current; current = current->next)
		if (current->group && current->group->active)
			draw_particle_group(win, current->group);
}
