/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** move_joystick
*/

#include "joystick.h"

static void set_joystick_limit(sfVector2i new_pos, win_t *win)
{
	int max_x = sfRenderWindow_mapCoordsToPixel(win->sf_win,
			(sfVector2f) {WIN_MAX_W, 0}, win->view).x - 1;
	int max_y = sfRenderWindow_mapCoordsToPixel(win->sf_win,
			(sfVector2f) {0, WIN_MAX_H}, win->view).y - 1;

	if (new_pos.x < 0)
		new_pos = (sfVector2i) {0, new_pos.y};
	if (sfRenderWindow_mapPixelToCoords(win->sf_win, new_pos, win->view).x
		> WIN_MAX_W)
		new_pos = (sfVector2i) {max_x, new_pos.y};
	if (new_pos.y < 0)
		new_pos = (sfVector2i) {new_pos.x, 0};
	if (sfRenderWindow_mapPixelToCoords(win->sf_win, new_pos, win->view).y
		> WIN_MAX_H)
		new_pos = (sfVector2i) {new_pos.x, max_y};
	sfMouse_setPositionRenderWindow(new_pos, win->sf_win);
}

void update_mouse_pos_joystick(joystick_t *joystick, win_t *win)
{
	sfVector2i pos = sfMouse_getPositionRenderWindow(win->sf_win);
	sfVector2i new_pos;

	update_deadzone_joystick(win->joystick);
	new_pos = (sfVector2i) {pos.x + (int) joystick->lx / 4,
				pos.y + (int) joystick->ly / 4};
	set_joystick_limit(new_pos, win);
}
