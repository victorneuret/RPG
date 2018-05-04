/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** update_joystick_ui
*/

#include "joystick.h"
#include "coord_utils.h"

static void ui_gamepad_move_mouse(win_t *win, sfVector2f orig_pos)
{
	sfVector2i pos = sfRenderWindow_mapCoordsToPixel(win->sf_win, orig_pos,
							win->view);
	sfVector2i view_pos = (sfVector2i) {orig_pos.x, orig_pos.y};

	win->joystick->switch_gamepad->gamepad_pos = view_pos;
	sfMouse_setPositionRenderWindow(pos, win->sf_win);
}

static void to_next_button(win_t *win, buttons_t *button)
{
	for (buttons_t *tmp = button; tmp; tmp = tmp->next) {
		if (tmp->game_state == win->game_state) {
			ui_gamepad_move_mouse(win,
				sfSprite_getPosition(tmp->sprite));
			tmp->selected = true;
			return;
		}
	}
	for (buttons_t *tmp = win->game->ui->buttons; tmp; tmp = tmp->next) {
		if (tmp->game_state == win->game_state) {
			ui_gamepad_move_mouse(win,
				sfSprite_getPosition(tmp->sprite));
			tmp->selected = true;
			return;
		}
	}
}

static void to_prev_button(win_t *win, bool one_selected)
{
	buttons_t *current = win->game->ui->buttons;
	buttons_t *last = win->game->ui->buttons;

	for (buttons_t *tmp = win->game->ui->buttons; tmp; tmp = tmp->next)
		if (tmp->game_state == win->game_state)
			last = tmp;
	if (!one_selected)
		return;
	while (current && !current->selected)
		current = current->next;
	current->selected = false;
	current = current->prev;
	while (current && current->game_state != win->game_state)
		current = current->prev;
	if (!current)
		current = last;
	current->selected = true;
	ui_gamepad_move_mouse(win, sfSprite_getPosition(current->sprite));
}

void update_ui_joystick(joystick_t *joystick, win_t *win)
{
	bool one_selected = false;
	buttons_t *current = win->game->ui->buttons;

	if (!joystick->switch_gamepad->gamepad || sfClock_getElapsedTime(
		joystick->switch_gamepad->clock).microseconds < 140000)
		return;
	for (buttons_t *tmp = win->game->ui->buttons; tmp; tmp = tmp->next)
		if (tmp->game_state == win->game_state && tmp->selected)
			one_selected = true;
	if (joystick->diry >= 60 && !one_selected)
		to_next_button(win, win->game->ui->buttons);
	else if (joystick->diry >= 60 && one_selected) {
		for (; current && !current->selected; current = current->next);
		if (current) {
			to_next_button(win, current->next);
			current->selected = false;
		}
	}
	if (joystick->diry <= -60)
		to_prev_button(win, one_selected);
	sfClock_restart(joystick->switch_gamepad->clock);
}
