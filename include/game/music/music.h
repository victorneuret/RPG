/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** .h
*/

#pragma once

#include "render_window.h"

typedef struct {
	game_status game_state;
	sf *;
	struct *next;
} _t;

typedef struct {
	game_status game_state;
	char *path;
	float volume;
} _declaration_t;

static const _declaration_t s_declaration[] = {
	{
		TITLE,
		"res/s/menu.mp3",
		100
	},
	{
		GAME,
		"res/s/game.mp3",
		100
	}
};
