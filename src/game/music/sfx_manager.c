/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** sfx_manager.c
*/

#include <SFML/Audio.h>

#include "music.h"

void play_sfx(sounds_t *sounds, sfx_type sfx)
{
	sfMusic_play(sounds->sfx[sfx].music);
}
