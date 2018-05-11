/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** joystick_button_one
*/

#include "joystick.h"
#include "events.h"
#include "render_window.h"
#include "key_pressed_functions.h"
#include "hud.h"
#include "npc.h"

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
		else if (win->game_state == GAME)
			get_item(win, win->game->player->inventory,
					win->game->player->sprite, true);
		button_click_released(win, &event);
		npc_interaction(win);
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
		if (win->game_state == STATS)
			win->game_state = GAME;
		pressed = true;
	}
}

void button_x(__attribute__((unused)) win_t *win, bool press)
{
	static bool pressed = false;

	if (!press) {
		pressed = false;
		return;
	} else if (!pressed && press)
		pressed = true;
}

void button_y(win_t *win, bool press)
{
	static bool pressed = false;

	if (!press) {
		pressed = false;
		return;
	} else if (!pressed && press) {
		pressed = true;
		if (win->game_state == GAME)
			drop_gun(win);
	}
}
