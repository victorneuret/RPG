/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** particle
*/

#include <SFML/Graphics.h>
#include <math.h>

#include "macros.h"
#include "my_calloc.h"
#include "nb_utils.h"
#include "render_window.h"
#include "particle.h"
#include "particle_manager.h"
#include "coord_utils.h"

void update_particle_heal(win_t *win,
			particle_t *particle, uint64_t current_time)
{
	const float new_speed = 1700.f;
	sfVector2f bar_pos = sfRectangleShape_getPosition(
				win->game->player->hp->bar);
	sfVector2f particle_pos = particle->pos;
	sfVector2f dir;

	if (current_time < 500)
		return;
	dir = get_direction(bar_pos, particle_pos);
	particle->speed = (sfVector2f) {dir.x * new_speed, dir.y * new_speed};
	if (distance(bar_pos, particle_pos) < 42) {
		particle->alive = false;
		win->game->player->hp->value += 1;
	}
}

static particle_t *create_particle(sfVector2f origin)
{
	static uint64_t count = 0;
	const float angle = (float) rand_int(1, 360) * (M_PI / 180.f);
	const float speed = (float) rand_int(200, 350);
	particle_t *particle = my_calloc(1, sizeof(particle_t));

	if (!particle)
		return NULL;
	particle->pos = origin;
	particle->color = ++count % 2 == 0 ? sfWhite : hex_to_rgb(0xFF1111);
	particle->alive = true;
	particle->update = &update_particle_heal;
	particle->lifetime_ms = (uint64_t) -1;
	particle->size = rand_int(3, 6);
	particle->speed = (sfVector2f) {cos(angle) * speed,
					sin(angle) * speed};
	particle->shape = create_shape(particle);
	return particle;
}

void particle_heal(win_t *win, uint16_t count, sfVector2f origin)
{
	particle_group_t *group = get_particle_group(win->particle_manager);
	particle_t **p_list = my_calloc(count + 1, sizeof(particle_t *));

	if (!p_list || !group)
		return;
	group->particles = p_list;
	for (size_t i = 0; i < count; i++) {
		p_list[i] = create_particle(origin);
		if (!p_list[i]) {
			free(p_list);
			return;
		}
	}
	sfClock_restart(group->timer);
}
