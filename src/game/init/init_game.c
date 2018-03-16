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
	if (!win->game)
		return false;
	win->game->textures = load_textures();
	if (!win->game->textures)
		return false;
	win->game_state = GAME;
	return true;
}
