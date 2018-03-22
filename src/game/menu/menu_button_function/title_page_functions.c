/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** title_page_functions
*/

#include "render_window.h"

void start_game(win_t *win)
{
	win->game_state = GAME;
}

void to_option_menu(win_t *win)
{
	win->game_state = OPTION;
}
