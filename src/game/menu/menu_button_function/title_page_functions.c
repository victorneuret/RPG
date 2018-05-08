/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** title_page_functions
*/

#include <SFML/Graphics.h>

#include "popup.h"
#include "change_state.h"
#include "render_window.h"
#include "level.h"
#include "music.h"
#include "enemies.h"

void start_game(win_t *win)
{
	change_state(win, GAME);
	load_level(&win->game->level, DUNGEON, win);
	create_enemy(&win->game->enemy_list, (sfVector2f) {600, 500});
	create_enemy(&win->game->enemy_list, (sfVector2f) {500, 400});
	create_enemy(&win->game->enemy_list, (sfVector2f) {800, 500});
}

void error_test(win_t *win)
{
	create_popup(win->game->ui, "This button is useless", ERROR);
}

void to_option_menu(win_t *win)
{
	play_sfx(win->game->sounds, SWITCH_TITLE);
	sfSprite_setScale(win->game->ui->title_page->options,
					(sfVector2f){0, 0});
	sfSprite_setColor(win->game->ui->title_page->options,
					sfColor_fromRGBA(255, 255, 255, 0));
	change_state(win, OPTION);
}
