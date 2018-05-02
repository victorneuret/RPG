/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** init_game
*/

#include "game.h"
#include "weather.h"
#include "my_calloc.h"
#include "title_page.h"
#include "change_state.h"
#include "player.h"

static bool init_ui(win_t *win)
{
	win->game->textures = load_textures();
	if (!win->game->textures)
		return false;
	win->game->ui->buttons = load_buttons(win->game->textures);
	win->game->ui->text_area = load_text_area();
	win->game->ui->hover_text_button = init_text_button();
	win->game->ui->title_page = init_title_page(win->game->textures);
	win->game->ui->popup_list = my_calloc(1, sizeof(popup_list_t));
	if (!win->game->ui->buttons || !win->game->ui->text_area
		|| !win->game->ui->hover_text_button
		|| !win->game->ui->title_page || !win->game->ui->popup_list)
		return false;
	return true;
}

static bool init_gamepad(win_t *win)
{
	win->joystick->switch_gamepad = my_calloc(1, sizeof(switch_gamepad_t));
	if (!win->joystick->switch_gamepad)
		return false;
	win->joystick->switch_gamepad->clock = sfClock_create();
	if (!win->joystick->switch_gamepad)
		return false;
	return true;
}

bool init_game(win_t *win)
{
	win->game = my_calloc(1, sizeof(game_t));
	win->game->ui = my_calloc(1, sizeof(ui_t));
	win->joystick = my_calloc(1, sizeof(joystick_t));
	if (!win->game || !win->game->ui || !win->joystick
		|| !init_ui(win) || !init_gamepad(win))
		return false;
	win->game->player = init_player(win);
	if (!win->game->player)
		return false;
	win->game->weather_type = CLEAR;
	win->game->weather_intensity = NORMAL;
	change_state(win, INTRO);
	return true;
}

void free_game(game_t *game)
{
	free_buttons(game->ui->buttons);
	free_hover_text_button(game->ui->hover_text_button);
	free_text_area(game->ui->text_area);
	destroy_player(game->player);
	free_textures(game->textures);
	free(game->ui);
}
