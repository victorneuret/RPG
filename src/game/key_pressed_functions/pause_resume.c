/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** pause_resume
*/

#include <SFML/Graphics.h>

#include "window/render_window.h"

void pause_game(win_t *win)
{
	if (win->game_state == PAUSE)
		win->game_state = GAME;
	else if (win->game_state == GAME)
		win->game_state = PAUSE;
}
