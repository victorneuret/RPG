/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** init_music
*/

#include <stdbool.h>
#include <SFML/Audio.h>

#include "music.h"

static size_t music_len(const music_declaration_t *music)
{
	size_t i = 0;

	while (music[i].path)
		i++;
	return i;
}

static bool init_sounds_sfx(music_t *music)
{
	for (size_t i = 0; sfx_declaration[i].path; i++) {
		music = malloc(sizeof(music_t));
		if (!music)
			return false;
		music->music = sfMusic_createFromFile(sfx_declaration[i].path);
		if (!music->music)
			return false;
		sfMusic_setVolume(music->music, sfx_declaration[i].volume);
		music->game_state = sfx_declaration[i].game_state;
	}
	return true;
}

static bool init_sounds_music(music_t *music)
{
	for (size_t i = 0; music_declaration[i].path; i++) {
		music = malloc(sizeof(music_t));
		if (!music)
			return false;
		music->music = sfMusic_createFromFile(music_declaration[i].path);
		if (!music->music)
			return false;
		sfMusic_setVolume(music->music, music_declaration[i].volume);
		music->game_state = music_declaration[i].game_state;
	}
	return true;
}

bool init_music(sounds_t *sounds)
{
	sounds = malloc(sizeof(sounds_t));

	if (!sounds)
		return false;
	sounds->sfx_vol = 100;
	sounds->music_vol = 100;
	sounds->music = malloc(sizeof(music_t) * music_len(music_declaration));
	sounds->sfx = malloc(sizeof(music_t) * music_len(sfx_declaration));
	if (!sounds->music || !sounds->sfx)
		return false;
	if (!init_sounds_music(sounds->music) || !init_sounds_sfx(sounds->sfx))
		return false;
	return true;
}
