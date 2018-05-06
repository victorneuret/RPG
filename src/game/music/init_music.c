/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** init_music
*/

#include <stdbool.h>
#include <SFML/Audio.h>

#include "music.h"

void free_music_struct(sounds_t *sounds)
{
	for (size_t i = 0; sounds->music[i].music; i++) {
		sfMusic_stop(sounds->music[i].music);
		sfMusic_destroy(sounds->music[i].music);
	}
	for (size_t i = 0; sounds->sfx[i].music; i++) {
		sfMusic_stop(sounds->sfx[i].music);
		sfMusic_destroy(sounds->sfx[i].music);
	}
}

static size_t music_len(const music_declaration_t *music)
{
	size_t i = 0;

	while (music[i].path)
		i++;
	return i + 1;
}

static bool init_sounds_sfx(music_t *sfx)
{
	for (size_t i = 0; sfx_declaration[i].path; i++) {
		sfx[i].music = sfMusic_createFromFile(sfx_declaration[i].path);
		if (!sfx[i].music)
			return false;
		sfMusic_setVolume(sfx[i].music, sfx_declaration[i].volume);
		sfx[i].max_volume = sfx_declaration[i].volume;
		sfx[i].game_state = sfx_declaration[i].game_state;
	}
	return true;
}

static bool init_sounds_music(music_t *music)
{
	for (size_t i = 0; music_declaration[i].path; i++) {
		music[i].music = sfMusic_createFromFile(music_declaration[i].path);
		if (!music[i].music)
			return false;
		sfMusic_setVolume(music[i].music, 0);
		music[i].max_volume = music_declaration[i].volume;
		music[i].game_state = music_declaration[i].game_state;
	}
	return true;
}

sounds_t *init_music()
{
	sounds_t *sounds = malloc(sizeof(sounds_t));

	if (!sounds)
		return false;
	sounds->music = malloc(sizeof(music_t) * music_len(music_declaration));
	sounds->sfx = malloc(sizeof(music_t) * music_len(sfx_declaration));
	if (!sounds->music || !sounds->sfx)
		return NULL;
	sounds->sfx_vol = default_sfx_vol;
	sounds->music_vol = default_music_vol;
	if (!init_sounds_music(sounds->music) || !init_sounds_sfx(sounds->sfx))
		return NULL;
	return sounds;
}
