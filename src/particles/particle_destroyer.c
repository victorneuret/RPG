/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** particle_destroyer
*/

#include "particle.h"

void destroy_particle_group(particle_group_t *group)
{
	for (size_t i = 0; group->particles[i]; i++) {
		sfRectangleShape_destroy(group->particles[i]->shape);
		free(group->particles[i]);
	}
	sfClock_destroy(group->timer);
	free(group);
}

void destroy_particle_manager(particle_manager_t *manager)
{
	particle_manager_t *current = manager;

	for (; current; current = current->next)
		if (current->group)
			destroy_particle_group(current->group);
	free(manager);
}

void remove_unactives(particle_manager_t *head)
{
	particle_manager_t *next = head;
	particle_manager_t *current = head;
	particle_manager_t *previous = current;

	while (next) {
		current = next;
		if (current->group && !current->group->active
				&& current != head) {
			destroy_particle_group(current->group);
			previous->next = current->next;
			next = current->next;
			free(current);
			continue;
		}
		next = current->next;
		previous = current;
	}
}
