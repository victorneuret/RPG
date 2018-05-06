/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** music.h
*/

#pragma once

#include "render_window.h"
#include <SFML/Audio/Types.h>

typedef struct music {
	game_status game_state;
	sfMusic *music;
} music_t;

typedef struct music_declaration {
	game_status game_state;
	char *path;
	float volume;
} music_declaration_t;

typedef struct sounds {
	float sfx_vol;
	float music_vol;
	music_t *music;
	music_t *sfx;
} sounds_t;

static const music_declaration_t music_declaration[] = {
	{
		TITLE,
		"res/sounds/menu.ogg",
		100
	},
	{
		GAME,
		"res/sounds/menu.ogg",
		100
	},
	{
		0,
		NULL,
		0
	}
};

static const music_declaration_t sfx_declaration[] = {
	{
		GAME,
		"res/sounds/click.ogg",
		100
	},
	{
		0,
		NULL,
		0
	}
};

bool init_music(sounds_t *sounds);
