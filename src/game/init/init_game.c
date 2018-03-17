/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** init_game
*/

#include "game.h"

bool init_game(win_t *win)
{
	win->game = malloc(sizeof(game_t));
	win->game->ui = malloc(sizeof(ui_t));
	if (!win->game || !win->game->ui)
		return false;
	win->game->textures = load_textures();
	if (!win->game->textures)
		return false;
	win->game->ui->buttons = load_buttons(win->game->textures);
	if (!win->game->ui->buttons)
		return false;
	win->game_state = GAME;
	return true;
}

void free_game(game_t *game)
{
	free_buttons(game->ui->buttons);
	free_textures(game->textures);
	free(game->ui);
}
