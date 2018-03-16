/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** particle_manager
*/

#include "my_calloc.h"

#include "particle.h"

sfRectangleShape *create_shape(particle_t *particle)
{
	sfRectangleShape *shape = sfRectangleShape_create();

	if (!shape)
		return NULL;
	sfRectangleShape_setSize(shape, (sfVector2f)
					{particle->size, particle->size});
	sfRectangleShape_setOrigin(shape, (sfVector2f) {particle->size / 2.f,
					particle->size / 2.f});
	sfRectangleShape_setPosition(shape, particle->pos);
	sfRectangleShape_setFillColor(shape, particle->color);
	return shape;
}

particle_group_t *get_particle_group(particle_manager_t *head)
{
	particle_manager_t *current = head;

	if (!current)
		return NULL;
	for (; current && current->next; current = current->next);
	current->next = my_calloc(1, sizeof(particle_manager_t));
	if (!current->next)
		return NULL;
	current = current->next;
	current->group = my_calloc(1, sizeof(particle_group_t));
	if (!current->group)
		return NULL;
	current->group->active = true;
	current->group->timer = sfClock_create();
	if (!current->group->timer)
		return NULL;
	return current->group;
}
