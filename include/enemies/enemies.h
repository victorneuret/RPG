/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** enemies
*/

#pragma once

#include <SFML/Graphics.h>
#include <stdint.h>

typedef struct enemy {
	sfRectangleShape *shape;
	sfVector2f pos;
	int32_t hp;
	int32_t hp_max;
	int32_t attack;
} enemy_t;

typedef struct enemy_list {
	enemy_t *enemy;
	struct enemy_list *next;
} enemy_list_t;

void draw_enemies(sfRenderWindow *win, enemy_list_t *enemy_list);
void create_enemy(enemy_list_t **enemy_list, sfVector2f pos);

void add_enemy_to_list(enemy_list_t **enemy_list, enemy_t *enemy);
void rm_enemy_from_list(enemy_list_t **enemy_list, enemy_t *enemy);
