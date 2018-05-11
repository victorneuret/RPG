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
#include "enemies.h"
#include "particle_manager.h"
#include "particle_shot.h"
#include "inventory.h"

static particle_t *create_particle(item_t *weapon, sfVector2f origin,
				float angle)
{
	const float speed = (float) rand_int(1500, 2000);
	particle_t *particle = my_calloc(1, sizeof(particle_t));

	if (!particle)
		return NULL;
	angle += rand_int(-2, 2);
	angle = (angle - 45) * (float) M_PI / 180.f;
	particle->pos = origin;
	particle->color = hex_to_rgb(0xE8BF28);
	particle->alive = true;
	particle->lifetime_ms = 3333;
	particle->weapon = weapon;
	particle->update_shot = &update_particle_shot;
	particle->size = rand_int(6, 8);
	particle->speed = (sfVector2f) {cos(angle) * speed,
					sin(angle) * speed};
	particle->shape = create_shape(particle);
	return particle;
}

void particle_ak(win_t *win, item_t *weapon, sfVector2f origin, float angle)
{
	particle_group_t *group = get_particle_group(win->particle_manager);
	particle_t **p_list = my_calloc(2, sizeof(particle_t *));

	if (!p_list || !group)
		return;
	group->particles = p_list;
	p_list[0] = create_particle(weapon, origin, angle);
	if (!p_list[0]) {
		free(p_list);
		return;
	}
	sfClock_restart(group->timer);
}
