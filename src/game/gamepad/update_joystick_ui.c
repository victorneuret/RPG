/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** update_joystick_ui
*/

#include "joystick.h"

static bool is_coord_equal(sfVector2f one, sfVector2f two)
{
	if (one.x != two.x)
		return false;
	if (one.y != two.y)
		return false;
	return true;
}

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
			return;
		}
	}
	for (buttons_t *tmp = win->game->ui->buttons; tmp; tmp = tmp->next) {
		if (tmp->game_state == win->game_state) {
			ui_gamepad_move_mouse(win,
				sfSprite_getPosition(tmp->sprite));
			return;
		}
	}
}

static void to_prev_button(joystick_t *joystick, win_t *win)
{
	sfVector2f pos;
	sfVector2f last_pos;

	for (buttons_t *tmp = win->game->ui->buttons; tmp; tmp = tmp->next)
		if (tmp->game_state == win->game_state)
			last_pos = sfSprite_getPosition(tmp->sprite);
	for (buttons_t *tmp = win->game->ui->buttons; tmp; tmp = tmp->next) {
		if (tmp->game_state == win->game_state && is_coord_equal(
			sfSprite_getPosition(tmp->sprite),
			(sfVector2f) {joystick->switch_gamepad->gamepad_pos.x,
			joystick->switch_gamepad->gamepad_pos.y})) {
			break;
		}
		if (tmp->game_state == win->game_state)
			pos = sfSprite_getPosition(tmp->sprite);
	}
	if (pos.x <= 0.001 && pos.y <= 0.001)
		ui_gamepad_move_mouse(win, last_pos);
	else if (pos.x != 0 && pos.y != 0)
		ui_gamepad_move_mouse(win, pos);
}

void update_ui_joystick(joystick_t *joystick, win_t *win)
{
	if (!joystick->switch_gamepad->gamepad || sfClock_getElapsedTime(
		joystick->switch_gamepad->clock).microseconds < 140000)
		return;
	sfClock_restart(joystick->switch_gamepad->clock);
	if (joystick->diry <= -60)
		return (to_prev_button(joystick, win));
	for (buttons_t *tmp = win->game->ui->buttons; tmp; tmp = tmp->next) {
		if (!tmp->next)
			to_next_button(win, win->game->ui->buttons);
		if (tmp->game_state == win->game_state && is_coord_equal(
			sfSprite_getPosition(tmp->sprite),
			(sfVector2f) {joystick->switch_gamepad->gamepad_pos.x,
			joystick->switch_gamepad->gamepad_pos.y})) {
			to_next_button(win, tmp->next);
			break;
		}
	}
}
