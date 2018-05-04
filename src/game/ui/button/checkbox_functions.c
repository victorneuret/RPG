/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** checkbox_functions
*/

#include "buttons.h"

void checkbox_fullscreen(win_t *win, __attribute__((unused))
	checkbox_t *checkbox)
{
	toggle_fullscreen(win);
}

sfSprite *get_checkbox_sprite(checkbox_t *checkbox)
{
	return checkbox->value ? checkbox->selected : checkbox->unselected;
}
