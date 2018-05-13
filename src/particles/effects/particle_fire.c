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
#include "color_utils.h"

void update_fire_particle(__attribute__((unused)) win_t *win,
			particle_t *particle, uint64_t current_time)
{
	const double lifetime_ratio = (double) current_time /
					(double) particle->lifetime_ms;
	const sfColor color_state[] = {
		hex_to_rgb(0xFFE808), hex_to_rgb(0xFFCE00),
		hex_to_rgb(0xFF9A00), hex_to_rgb(0xFF5A00),
		hex_to_rgb(0xFF0000), hex_to_rgb(0x2A2A2A)
	};
	const size_t index = lifetime_ratio * 5.f;

	particle->color = color_state[index];
}

static particle_t *create_particle(sfVector2f pos)
{
	const float angle = (float) (rand_int(-25, 25) - 90) * (M_PI / 180.f);
	const float speed = (float) rand_int(10, 50);
	particle_t *particle = my_calloc(1, sizeof(particle_t));

	if (!particle)
		return NULL;
	particle->pos = pos;
	particle->color = sfYellow;
	particle->alive = true;
	particle->lifetime_ms = rand_int(1500, 3000);
	particle->size = rand_int(2, 4);
	particle->update = &update_fire_particle;
	particle->speed = (sfVector2f) {cos(angle) * speed,
					sin(angle) * speed};
	particle->shape = create_shape(particle);
	return particle;
}

void create_fire_particle(win_t *win, sfVector2f pos)
{
	particle_group_t *group = get_particle_group(win->particle_manager);
	particle_t **p_list = my_calloc(2, sizeof(particle_t *));

	if (!p_list || !group)
		return;
	group->particles = p_list;
	p_list[0] = create_particle(pos);
	if (!p_list[0]) {
		free(p_list);
		return;
	}
	sfClock_restart(group->timer);
}
