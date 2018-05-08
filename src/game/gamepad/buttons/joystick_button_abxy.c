/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** joystick_button_one
*/

#include "joystick.h"
#include "events.h"
#include "render_window.h"
#include "hud.h"

void button_a(win_t *win, bool press)
{
	static bool pressed = false;
	sfEvent event;

	event.mouseButton.button = sfMouseLeft;
	if (!press && pressed) {
		pressed = false;
	} else if (!pressed && press) {
		if (win->game_state == INTRO)
			exit_intro(win, NULL);
		button_click_released(win, &event);
		pressed = true;
	}
}

void button_b(win_t *win, bool press)
{
	static bool pressed = false;

	if (!press && pressed) {
		pressed = false;
		return;
	} else if (!pressed && press) {
		if (win->game_state == OPTION)
			win->game_state = TITLE;
		else if (win->game_state == PAUSE)
			win->game_state = GAME;
		pressed = true;
	}
}

void button_x(win_t *win, bool press)
{
	static bool pressed = false;

	if (!press) {
		pressed = false;
		return;
	} else if (!pressed && press) {
		win->game->player->hp->hp += 1;
		update_hp_bar(win->game->player);
		pressed = true;
	} else {
		win->game->player->hp->hp += 1;
		update_hp_bar(win->game->player);
	}
}

void button_y(win_t *win, bool press)
{
	static bool pressed = false;

	if (!press) {
		pressed = false;
		return;
	} else if (!pressed && press) {
		win->game->player->hp->hp -= 1;
		update_hp_bar(win->game->player);
		pressed = true;
	} else {
		win->game->player->hp->hp -= 1;
		update_hp_bar(win->game->player);
	}
}
