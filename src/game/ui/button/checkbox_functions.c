/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** checkbox_functions
*/

#include "buttons.h"

void change_resolution(win_t *win, __attribute__((unused))
	checkbox_t *checkbox)
{
	static uint8_t mode = 0;
	static sfVector2u resolution = {0, 0};

	switch (mode) {
	case 1: resolution = (sfVector2u) {1280, 720}; break;
	case 2: resolution = (sfVector2u) {1600, 900}; break;
	default: resolution = (sfVector2u) {960, 540}; break;
	}
	if (mode++ == 2)
		mode = 0;
	sfRenderWindow_setSize(win->sf_win, resolution);
}

void manage_music(__attribute__((unused)) win_t *win, __attribute__((unused))
	checkbox_t *checkbox)
{
	return;
}

void checkbox_fullscreen(win_t *win, __attribute__((unused))
	checkbox_t *checkbox)
{
	toggle_fullscreen(win);
}

sfSprite *get_checkbox_sprite(checkbox_t *checkbox)
{
	return checkbox->value ? checkbox->selected : checkbox->unselected;
}
