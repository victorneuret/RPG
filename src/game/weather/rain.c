/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** rain
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
	particle->color = hex_to_rgb(0x42A5F5);
	particle->alive = true;
	particle->lifetime_ms = rand_int(2500, 3500);
	particle->size = rand_int(3, 5);
	particle->speed = (sfVector2f) {cos(angle) * speed,
					sin(angle) * speed};
	particle->shape = create_shape(particle);
	return particle;
}

void update_rain(win_t *win)
{
	const size_t count = 5;
	particle_group_t *group = get_particle_group(win->particle_manager);
	particle_t **p_list = my_calloc(count + 1, sizeof(particle_t *));
	sfVector2f origin = (sfVector2f) {rand_int(-WIN_MAX_W, WIN_MAX_W),
					rand_int(-WIN_MAX_H, 0)};
	const float angle = 45 * (M_PI / 180.f);
	const float speed = (float) rand_int(900, 1300);

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
