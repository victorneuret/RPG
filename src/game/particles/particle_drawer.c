/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** particle_drawer
*/

#include "render.h"
#include "particle.h"

static void draw_particle_group(win_t *win, particle_group_t *group)
{
	for (size_t i = 0; group->particles[i]; i++)
		if (group->particles[i]->alive)
			render_object(win->sf_win, RECTANGLE,
					group->particles[i]->shape);
}

void draw_particles(win_t *win)
{
	particle_manager_t *current = win->particle_manager;

	if (win->game_state == TITLE || win->game_state == OPTION)
		return;
	for (; current; current = current->next)
		if (current->group && current->group->active)
			draw_particle_group(win, current->group);
}
