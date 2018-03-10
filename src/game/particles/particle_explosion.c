/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** particle
*/

#include <math.h>

#include "utils/my_calloc.h"
#include "utils/nbr/nb_utils.h"
#include "window/render_window.h"
#include "game/particles/particle.h"
#include "game/particles/particle_manager.h"

static particle_t *create_particle(sfVector2f origin, sfColor color)
{
	const float angle = (float) rand_int(1, 360) * (M_PI / 180.f);
	const float speed = (float) rand_int(20, 100);
	particle_t *particle = my_calloc(1, sizeof(particle_t));

	if (!particle)
		return NULL;
	particle->pos = origin;
	particle->color = color;
	particle->alive = true;
	particle->lifetime_ms = rand_int(2500, 3500);
	particle->size = rand_int(3, 6);
	particle->speed = (sfVector2f) {cos(angle) * speed,
					sin(angle) * speed};
	particle->shape = create_shape(particle);
	return particle;
}

void create_explosion(win_t *win, uint16_t count,
		sfVector2f origin, sfColor color)
{
	particle_group_t *group = get_particle_group(win->particle_manager);
	particle_t **p_list = my_calloc(count + 1, sizeof(particle_t *));

	if (!p_list || !group)
		return;
	group->particles = p_list;
	for (size_t i = 0; i < count; i++) {
		p_list[i] = create_particle(origin, color);
		if (!p_list[i]) {
			free(p_list);
			return;
		}
	}
	sfClock_restart(group->timer);
}
