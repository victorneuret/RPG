/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** enemy_list
*/

#include <stdlib.h>
#include <SFML/Graphics.h>

#include "enemies.h"
#include "my_calloc.h"

void add_enemy_to_list(enemy_list_t **enemy_list, enemy_t *enemy)
{
	enemy_list_t *current;

	if (!*enemy_list) {
		*enemy_list = my_calloc(1, sizeof(enemy_list_t));
		if (!*enemy_list)
			return;
	}
	current = *enemy_list;
	while (current && current->next)
		current = current->next;
	if (!current->enemy) {
		current->enemy = enemy;
	} else {
		current->next = my_calloc(1, sizeof(enemy_list_t));
		if (!current->next)
			return;
		current->next->enemy = enemy;
	}
}

static void del_enemy(enemy_t *enemy)
{
	sfRectangleShape_destroy(enemy->shape);
	free(enemy);
}

static void rm_first(enemy_list_t **enemy_list, enemy_t *enemy)
{
	enemy_list_t *save;

	if (!(*enemy_list)->next) {
		free((*enemy_list)->enemy);
		(*enemy_list)->enemy = NULL;
		return;
	}
	save = (*enemy_list)->next;
	del_enemy(enemy);
	free(*enemy_list);
	*enemy_list = save;
}

void rm_enemy_from_list(enemy_list_t **enemy_list, enemy_t *enemy)
{
	enemy_list_t *previous = NULL;
	enemy_list_t *current = *enemy_list;

	if (!current || !enemy)
		return;
	if (current->enemy == enemy)
		return rm_first(enemy_list, enemy);
	while (current) {
		if (current->enemy == enemy) {
			previous->next = current->next;
			del_enemy(current->enemy);
			free(current);
			return;
		}
		previous = current;
		current = current->next;
	}
}
