/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** music.h
*/

#pragma once

#include <SFML/Audio/Types.h>

#include "settings.h"
#include "render_window.h"

static const float DEFAULT_SFX_VOL = 100;
static const float DEFAULT_MUSIC_VOL = 100;

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
	bool no_sound;
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

typedef enum sfx {
	SWITCH_TITLE,
	CLICK,
	DEATH,
	SHOOT,
	HIT,
	UNLOCKED,
	OPEN
} sfx_type;

static const music_declaration_t sfx_declaration[] = {
	{
		TITLE | OPTION,
		"res/sounds/sfx/switch_title.ogg",
		100
	},
	{
		GAME,
		"res/sounds/sfx/click.ogg",
		100
	},
	{
		GAME,
		"res/sounds/sfx/death.ogg",
		100
	},
	{
		GAME,
		"res/sounds/sfx/shoot.ogg",
		100
	},
	{
		GAME,
		"res/sounds/sfx/hit.ogg",
		100
	},
	{
		GAME,
		"res/sounds/sfx/unlocked.ogg",
		100
	},
	{
		GAME,
		"res/sounds/sfx/open.ogg",
		100
	},
	{
		0,
		NULL,
		0
	}
};

sounds_t *init_music(settings_t *settings);
void free_music_struct(sounds_t *sounds);
void play_sfx(sounds_t *sounds, sfx_type sfx);
void set_global_volume(sounds_t *sounds);
