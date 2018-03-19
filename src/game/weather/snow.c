/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** snow
*/

#include <math.h>

#include "my_calloc.h"
#include "nb_utils.h"
#include "render_window.h"
#include "particle.h"
#include "particle_manager.h"

static particle_t *create_particle(sfVector2f origin, float angle, float speed)
{
	particle_t *particle = my_calloc(1, sizeof(particle_t));

	if (!particle)
		return NULL;
	particle->pos = origin;
	particle->color = sfWhite;
	particle->alive = true;
	particle->lifetime_ms = 40000;
	particle->size = rand_int(3, 5);
	particle->speed = (sfVector2f) {cos(angle) * speed,
					sin(angle) * speed};
	particle->shape = create_shape(particle);
	return particle;
}

void update_snow(win_t *win)
{
	const size_t count = 1;
	particle_group_t *group = get_particle_group(win->particle_manager);
	particle_t **p_list = my_calloc(count + 1, sizeof(particle_t *));
	sfVector2f origin = (sfVector2f) {rand_int(-WIN_MAX_W, WIN_MAX_W),
					rand_int(-WIN_MAX_H, 0)};
	const float angle = 85 * (M_PI / 180.f);
	const float speed = (float) rand_int(50, 75);

	if (!p_list || !group)
		return;
	group->particles = p_list;
	for (size_t i = 0; i < count; i++) {
		p_list[i] = create_particle(origin, angle, speed);
		origin.x -= 10;
		origin.y -= 10;
		if (!p_list[i])
			return;
	}
	sfClock_restart(group->timer);
}
