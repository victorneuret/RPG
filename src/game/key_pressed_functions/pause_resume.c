/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** pause_resume
*/

#include <SFML/Graphics.h>

#include "change_state.h"
#include "render_window.h"

void pause_game(win_t *win)
{
	if (win->game_state == OPTION)
		change_state(win, GAME);
	else if (win->game_state == GAME)
		change_state(win, OPTION);
}
