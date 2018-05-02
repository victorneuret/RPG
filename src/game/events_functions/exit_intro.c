/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** exit_intro
*/

#include <SFML/Graphics.h>

#include "change_state.h"
#include "render_window.h"

void exit_intro(win_t *win, __attribute__((unused)) sfEvent *event)
{
	change_state(win, TITLE);
}
