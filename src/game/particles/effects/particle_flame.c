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

static sfColor get_fire_color(void)
{
	const sfColor colors[] = {
		hex_to_rgb(0xFF5722),
		hex_to_rgb(0xFF9800),
		hex_to_rgb(0xFFCA28)
	};
	return colors[rand_int(0, 2)];
}

static particle_t *create_particle(item_t *weapon, sfVector2f origin,
				float angle)
{
	const float speed = (float) rand_int(1000, 1250);
	particle_t *particle = my_calloc(1, sizeof(particle_t));

	if (!particle)
		return NULL;
	angle += rand_int(-25, 25);
	angle = (angle - 45) * (float) M_PI / 180.f;
	particle->pos = origin;
	particle->color = get_fire_color();
	particle->alive = true;
	particle->fade_out = true;
	particle->lifetime_ms = 500;
	particle->weapon = weapon;
	particle->update_shot = &update_particle_shot;
	particle->size = rand_int(5, 8);
	particle->speed = (sfVector2f) {cos(angle) * speed,
					sin(angle) * speed};
	particle->shape = create_shape(particle);
	return particle;
}

void create_flame(win_t *win, item_t *weapon, sfVector2f origin, float angle)
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
