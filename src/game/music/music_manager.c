/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** music_manager.c
*/

#include <SFML/Audio/Types.h>
#include <SFML/Audio.h>
#include <SFML/Audio/SoundStatus.h>
#include <stdbool.h>

#include "render_window.h"
#include "music.h"

void set_global_volume(sounds_t *sounds)
{
	for (size_t i = 0; sounds->music[i].music; i++)
		sfMusic_setVolume(sounds->music[i].music,
		(sounds->music_vol * (sounds->music[i].max_volume / 100)));
	for (size_t i = 0; sounds->sfx[i].music; i++)
		sfMusic_setVolume(sounds->sfx[i].music,
		(sounds->sfx_vol * (sounds->sfx[i].max_volume / 100)));
}

static bool is_music_playing(sounds_t *sounds)
{
	for (size_t i = 0; sounds->music[i].music; i++) {
		if (sfMusic_getStatus(sounds->music[i].music) == sfPlaying)
			return true;
	}
	return false;
}

static void tansition_effect(music_t *music, game_status game_state,
	sounds_t *sounds)
{
	float volume = 0;

	if (!(music->game_state & game_state) &&
			sfMusic_getStatus(music->music) == sfPlaying) {
		volume = sfMusic_getVolume(music->music);
		if (volume >= 1)
			sfMusic_setVolume(music->music, volume - 1);
		else
			sfMusic_pause(music->music);
	} else if (music->game_state & game_state &&
			sfMusic_getStatus(music->music) == sfPlaying) {
		volume = sfMusic_getVolume(music->music);
		if (volume < (sounds->music_vol * (music->max_volume / 100)))
			sfMusic_setVolume(music->music, volume + 1);
	}

}

static void play_music(music_t *music)
{
	if (sfMusic_getStatus(music->music) == sfPlaying)
		return;
	sfMusic_play(music->music);
}

void music_management(sounds_t *sounds, game_status game_state)
{
	for (size_t i = 0; sounds->music[i].music; i++) {
		if (sounds->music[i].game_state & game_state &&
				!is_music_playing(sounds)) {
			play_music(&sounds->music[i]);
			break;
		}
		tansition_effect(&sounds->music[i], game_state, sounds);
	}
}
