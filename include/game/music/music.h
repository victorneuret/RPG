/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** music.h
*/

#pragma once

#include "render_window.h"

typedef struct music {
	game_status game_state;
	sfMusic *music;
	struct music *next;
} music_t;

typedef struct {
	game_status game_state;
	char *path;
	float volume;
} music_declaration_t;

static const music_declaration_t musics_declaration[] = {
	{
		TITLE,
		"res/musics/menu.mp3",
		100
	},
	{
		GAME,
		"res/musics/game.mp3",
		100
	}
};
