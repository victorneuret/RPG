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
#include "particle_explosion.h"
#include "inventory.h"
#include "inventory_list.h"

void spit_blood(win_t *win, sfVector2f pos)
{
	const inventory_t *inventory = win->game->player->inventory;

	if (inventory->item[inventory->selected]->type == FLAMETHROWER)
		return;
	create_explosion(win, 3, pos, sfRed);
}

void update_particle_shot(win_t *win, particle_t *particle)
{
	enemy_list_t *current = win->game->enemy_list;
	sfFloatRect enemy_rect;
	const sfFloatRect particle_rect =
		sfRectangleShape_getGlobalBounds(particle->shape);

	if (!particle->weapon)
		return;
	while (current) {
		if (!current->enemy)
			return;
		enemy_rect = sfSprite_getGlobalBounds(
			current->enemy->sprite);
		if (sfFloatRect_intersects(&enemy_rect, &particle_rect, NULL)) {
			particle->alive = false;
			spit_blood(win, particle->pos);
			current->enemy->hp -= particle->weapon->damages
					+ win->game->player->dmg;
			play_sfx(win->game->sounds, HIT);
		}
		current = current->next;
	}
}

static particle_t *create_particle(item_t *weapon, sfVector2f origin,
				float angle)
{
	const float speed = (float) rand_int(1500, 1750);
	particle_t *particle = my_calloc(1, sizeof(particle_t));

	if (!particle)
		return NULL;
	angle = (angle - 45) * (float) M_PI / 180.f;
	particle->pos = origin;
	particle->color = hex_to_rgb(0x90A4AE);
	particle->alive = true;
	particle->fade_in = false;
	particle->fade_out = true;
	particle->lifetime_ms = 3333;
	particle->weapon = weapon;
	particle->update_shot = &update_particle_shot;
	particle->size = rand_int(5, 10);
	particle->speed = (sfVector2f) {cos(angle) * speed,
					sin(angle) * speed};
	particle->shape = create_shape(particle);
	return particle;
}

void create_shot(win_t *win, item_t *weapon, sfVector2f origin, float angle)
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
