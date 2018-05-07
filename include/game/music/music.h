/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** music.h
*/

#pragma once

#include "render_window.h"
#include <SFML/Audio/Types.h>

static const float default_sfx_vol = 100;
static const float default_music_vol = 100;

typedef enum sfx {
	SWITCH_TITLE
} sfx_type;

typedef struct music {
	game_status game_state;
	sfMusic *music;
	float max_volume;
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
		INTRO | TITLE | OPTION | PAUSE,
		"res/sounds/musics/title.ogg",
		20
	},
	{
		GAME,
		"res/sounds/musics/boss.ogg",
		20
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
		"res/sounds/sfx/switch_title.ogg",
		100
	},
	{
		0,
		NULL,
		0
	}
};

sounds_t *init_music();
void free_music_struct(sounds_t *sounds);
void play_sfx(sounds_t *sounds, sfx_type sfx);
