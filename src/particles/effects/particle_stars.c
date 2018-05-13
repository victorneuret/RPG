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

static particle_t *create_particle(void)
{
	const float angle = (float) rand_int(1, 360) * (M_PI / 180.f);
	const float speed = (float) rand_int(3, 5);
	particle_t *particle = my_calloc(1, sizeof(particle_t));

	if (!particle)
		return NULL;
	particle->pos = (sfVector2f) {rand_int(0, WIN_MAX_W),
					rand_int(0, WIN_MAX_H)};
	particle->color = sfYellow;
	particle->alive = true;
	particle->fade_in = true;
	particle->fade_out = true;
	particle->lifetime_ms = rand_int(5500, 6500);
	particle->size = rand_int(2, 4);
	particle->speed = (sfVector2f) {cos(angle) * speed,
					sin(angle) * speed};
	particle->shape = create_shape(particle);
	return particle;
}

void create_star(win_t *win)
{
	particle_group_t *group = get_particle_group(win->particle_manager);
	particle_t **p_list = my_calloc(2, sizeof(particle_t *));

	if (!p_list || !group)
		return;
	group->particles = p_list;
	p_list[0] = create_particle();
	if (!p_list[0]) {
		free(p_list);
		return;
	}
	sfClock_restart(group->timer);
}
