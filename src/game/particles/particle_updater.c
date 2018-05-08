/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** particle_manager
*/

#include "macros.h"
#include "my_calloc.h"
#include "render_window.h"
#include "color_utils.h"
#include "particle.h"
#include "particle_destroyer.h"

static void update_particle_position(win_t *win, particle_t *particle)
{
	particle->pos.y += particle->speed.y * win->dt;
	particle->pos.x += particle->speed.x * win->dt;
	if (particle->screen_collision) {
		particle->pos.x = MAX(0, MIN(particle->pos.x, WIN_MAX_W));
		particle->pos.y = MAX(0, MIN(particle->pos.y, WIN_MAX_H));
	}
}

static void update_particle(win_t *win, sfClock *timer, particle_t *particle)
{
	uint64_t current_time = sfTime_asMilliseconds(
					sfClock_getElapsedTime(timer));

	if (current_time > particle->lifetime_ms)
		particle->alive = false;
	if (!particle->alive)
		return;
	if (particle->update)
		particle->update(win, particle, current_time);
	if (particle->gravity)
		particle->pos.y += (current_time /
		(float) particle->lifetime_ms) * 1000 * win->dt;
	update_particle_position(win, particle);
	particle->color.a = get_particle_alpha(particle->fade_in,
		particle->fade_out, current_time, particle->lifetime_ms);
	sfRectangleShape_setFillColor(particle->shape, particle->color);
	sfRectangleShape_setPosition(particle->shape, particle->pos);
}

static bool is_anim_over(particle_group_t *group)
{
	uint64_t current_time = sfTime_asMilliseconds(
					sfClock_getElapsedTime(group->timer));

	for (size_t i = 0; group->particles[i]; i++)
		if (current_time < group->particles[i]->lifetime_ms)
			return false;
	group->active = false;
	return true;
}

static void update_particle_group(win_t *win, particle_group_t *group)
{
	if (is_anim_over(group))
		return;
	for (size_t i = 0; group->particles[i]; i++)
		update_particle(win, group->timer, group->particles[i]);
}

void update_particles(win_t *win, particle_manager_t *manager)
{
	particle_manager_t *current = manager;

	remove_unactives(manager);
	for (; current; current = current->next)
		if (current->group && current->group->active &&
					current->group->particles)
			update_particle_group(win, current->group);
}
