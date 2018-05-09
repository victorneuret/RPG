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

static sfVector2f get_direction(sfVector2f player_pos, sfVector2f particle_pos)
{
	float total = 0.0;
	sfVector2f absolute_dir = {0.0, 0.0};
	sfVector2f relative_dir = {0.0, 0.0};

	absolute_dir.x = player_pos.x - particle_pos.x;
	absolute_dir.y = player_pos.y - particle_pos.y;
	total = ABS(absolute_dir.x) + ABS(absolute_dir.y);
	relative_dir.x = absolute_dir.x / total;
	relative_dir.y = absolute_dir.y / total;
	return relative_dir;
}

void update_particle_xp(win_t *win,
			particle_t *particle, uint64_t current_time)
{
	const float new_speed = 1700.f;
	sfVector2f player_pos = sfSprite_getPosition(win->game->player->sprite);
	sfVector2f particle_pos = particle->pos;
	sfVector2f dir;

	if (current_time < 500)
		return;
	dir = get_direction(player_pos, particle_pos);
	particle->speed = (sfVector2f) {dir.x * new_speed, dir.y * new_speed};
	if (distance(player_pos, particle_pos) < 42)
		particle->alive = false;
}

static particle_t *create_particle(sfVector2f origin, sfColor color)
{
	const float angle = (float) rand_int(1, 360) * (M_PI / 180.f);
	const float speed = (float) rand_int(250, 350);
	particle_t *particle = my_calloc(1, sizeof(particle_t));

	if (!particle)
		return NULL;
	particle->pos = origin;
	particle->color = color;
	particle->alive = true;
	particle->update = &update_particle_xp;
	particle->lifetime_ms = (uint64_t) -1;
	particle->size = rand_int(3, 6);
	particle->speed = (sfVector2f) {cos(angle) * speed,
					sin(angle) * speed};
	particle->shape = create_shape(particle);
	return particle;
}

void particle_xp(win_t *win, uint16_t count,
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
