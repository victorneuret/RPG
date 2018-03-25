/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** title_page_functions
*/

#include "popup.h"
#include "render_window.h"

void start_game(win_t *win)
{
	win->game_state = GAME;
}

void error_test(win_t *win)
{
	create_popup(win->game->ui, "This button is useless", ERROR);
}

void to_option_menu(win_t *win)
{
	win->game_state = OPTION;
}
