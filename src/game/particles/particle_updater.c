/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** particle_manager
*/

#include "utils/my_calloc.h"
#include "window/render_window.h"
#include "game/particles/particle.h"

static void update_particle(win_t *win, sfClock *timer,
			particle_t *particle)
{
	uint64_t current_time = sfTime_asMilliseconds(
					sfClock_getElapsedTime(timer));

	particle->pos.x += particle->speed.x * win->dt;
	particle->pos.y += particle->speed.y * win->dt;
	particle->color.a = 255 -
		((current_time / (float) particle->lifetime_ms) * 255.f);
}

static void update_particle_group(win_t *win, particle_group_t *group)
{
	for (size_t i = 0; group->particles[i]; i++)
		update_particle(win, group->timer, group->particles[i]);
}

void update_particles(win_t *win, particle_manager_t *manager)
{
	particle_manager_t *current = manager;

	for (; current; current = current->next)
		if (current->group && current->group->active &&
					current->group->particles)
			update_particle_group(win, current->group);
}
