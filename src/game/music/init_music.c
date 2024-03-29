/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** init_music
*/

#include <stdbool.h>
#include <SFML/Audio.h>

#include "music.h"
#include "settings.h"

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
	size_t i = 0;

	while (sfx_declaration[i].path) {
		sfx[i].music = sfMusic_createFromFile(sfx_declaration[i].path);
		if (!sfx[i].music)
			return false;
		sfMusic_setVolume(sfx[i].music, sfx_declaration[i].volume);
		sfx[i].max_volume = sfx_declaration[i].volume;
		sfx[i].game_state = sfx_declaration[i].game_state;
		i++;
	}
	sfx[i].music = NULL;
	return true;
}

static bool init_sounds_music(music_t *music)
{
	size_t i = 0;

	while (music_declaration[i].path) {
		music[i].music =
			sfMusic_createFromFile(music_declaration[i].path);
		if (!music[i].music)
			return false;
		sfMusic_setVolume(music[i].music, 0);
		music[i].max_volume = music_declaration[i].volume;
		music[i].game_state = music_declaration[i].game_state;
		i++;
	}
	music[i].music = NULL;
	return true;
}

sounds_t *init_music(settings_t *settings)
{
	sounds_t *sounds = malloc(sizeof(sounds_t));

	if (!sounds)
		return false;
	sounds->music = malloc(sizeof(music_t) * music_len(music_declaration));
	sounds->sfx = malloc(sizeof(music_t) * music_len(sfx_declaration));
	if (!sounds->music || !sounds->sfx)
		return NULL;
	sounds->no_sound = settings->no_sound;
	sounds->sfx_vol = DEFAULT_SFX_VOL;
	sounds->music_vol = DEFAULT_MUSIC_VOL;
	if (!init_sounds_music(sounds->music) || !init_sounds_sfx(sounds->sfx))
		return NULL;
	return sounds;
}
