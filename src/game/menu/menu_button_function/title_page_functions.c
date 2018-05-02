/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** title_page_functions
*/

#include "popup.h"
#include "change_state.h"
#include "render_window.h"
#include <SFML/Graphics.h>

void start_game(win_t *win)
{
	change_state(win, GAME);
}

void error_test(win_t *win)
{
	create_popup(win->game->ui, "This button is useless", ERROR);
}

void to_option_menu(win_t *win)
{
	sfSprite_setScale(win->game->ui->title_page->options,
					(sfVector2f){0, 0});
	sfSprite_setColor(win->game->ui->title_page->options,
					sfColor_fromRGBA(255, 255, 255, 0));
	change_state(win, OPTION);
}
