/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** particle
*/

#include <math.h>

#include "my_calloc.h"
#include "nb_utils.h"
#include "render_window.h"
#include "particle.h"
#include "particle_manager.h"

static particle_t *create_particle(sfVector2f origin, sfColor color,
				float angle)
{
	const float speed = (float) rand_int(1200, 1400);
	particle_t *particle = my_calloc(1, sizeof(particle_t));

	if (!particle)
		return NULL;
	angle = (angle - 45) * (float) M_PI / 180.f;
	particle->pos = origin;
	particle->color = color;
	particle->alive = true;
	particle->fade_in = false;
	particle->fade_out = true;
	particle->lifetime_ms = 3333;
	particle->size = rand_int(10, 15);
	particle->speed = (sfVector2f) {cos(angle) * speed,
					sin(angle) * speed};
	particle->shape = create_shape(particle);
	return particle;
}

void create_shot(win_t *win, sfVector2f origin, sfColor color, float angle)
{
	particle_group_t *group = get_particle_group(win->particle_manager);
	particle_t **p_list = my_calloc(2, sizeof(particle_t *));

	if (!p_list || !group)
		return;
	group->particles = p_list;
	p_list[0] = create_particle(origin, color, angle);
	if (!p_list[0]) {
		free(p_list);
		return;
	}
	sfClock_restart(group->timer);
}