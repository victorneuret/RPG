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

static particle_t *create_particle(sfVector2f origin, sfColor color, float angle)
{
	const float speed = (float) rand_int(500, 1100);
	particle_t *particle = my_calloc(1, sizeof(particle_t));


	if (!particle)
		return NULL;
	angle = (angle + rand_int(-1, 1)) * (float) M_PI / 180.f;
	particle->pos = origin;
	particle->color = color;
	particle->alive = true;
	particle->fade_in = false;
	particle->fade_out = true;
	particle->screen_collision = true;
	particle->lifetime_ms = rand_int(300, 500);
	particle->size = rand_int(3, 6);
	particle->speed = (sfVector2f) {cos(angle) * speed,
					sin(angle) * speed};
	particle->shape = create_shape(particle);
	return particle;
}

void create_dash(win_t *win, uint16_t count, float angle,
		sfVector2f origin)
{
	particle_group_t *group = get_particle_group(win->particle_manager);
	particle_t **p_list = my_calloc(count + 1, sizeof(particle_t *));

	if (!p_list || !group)
		return;
	group->particles = p_list;
	for (size_t i = 0; i < count; i++) {
		p_list[i] = create_particle(origin, sfBlue, angle);
		if (!p_list[i]) {
			free(p_list);
			return;
		}
	}
	sfClock_restart(group->timer);
}
