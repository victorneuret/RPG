/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** init_game
*/

#include "game.h"
#include "weather.h"

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
	win->game->ui->text_area = load_text_area();
	if (!win->game->ui->buttons || !win->game->ui->text_area)
		return false;
	win->game->weather_type = CLEAR;
	win->game->weather_intensity = NORMAL;
	win->game_state = GAME;
	return true;
}

void free_game(game_t *game)
{
	free_buttons(game->ui->buttons);
	free_text_area(game->ui->text_area);
	free_textures(game->textures);
	free(game->ui);
}
