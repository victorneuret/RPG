/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** game
*/

#pragma once

#include <stdint.h>
#include <stdbool.h>

#include "render_window.h"

static const uint8_t SAVE_SIZE = 40;

typedef struct save_elements {
	uint8_t level;
	uint16_t skill_point;
	int64_t hp;
	int64_t xp;
	int32_t inventory;
	uint8_t quest_id;
	int8_t quest_kill;
	bool quest_popup;
	int32_t skills;
} save_elements_t;

typedef struct save {
	int fd;
	save_elements_t save_elements;
} save_t;

bool save_exist(save_t *save);
void create_save(win_t *win, save_t *save);
bool open_save(win_t *win, save_t *save);
