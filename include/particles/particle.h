/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** particle
*/

#pragma once

#include <SFML/Graphics.h>
#include <stdint.h>

#include "inventory.h"
#include "render_window.h"

typedef struct item item_t;
typedef struct render_window win_t;

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
	item_t *weapon;
	bool alive;
	bool gravity;
	bool fade_in;
	bool fade_out;
	bool screen_collision;
	void (*update)(win_t *win, particle_t *particle, uint64_t current_time);
	void (*update_shot)(win_t *win, particle_t *particle);
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
