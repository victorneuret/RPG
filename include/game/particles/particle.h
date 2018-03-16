/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** particle
*/

#pragma once

#include <SFML/Graphics.h>
#include <stdint.h>

#include "render_window.h"

typedef struct particle particle_t;
typedef struct particle_group particle_group_t;
typedef struct particle_manager particle_manager_t;

struct particle {
	sfVector2f pos;
	sfVector2f speed;
	sfColor color;
	uint32_t size;
	uint64_t lifetime_ms;
	sfRectangleShape *shape;
	bool alive;
	bool fade_in;
	bool fade_out;
};

struct particle_group {
	particle_t **particles;
	sfClock *timer;
	bool active;
};

struct particle_manager {
	particle_group_t *group;
	particle_manager_t *next;
};
