/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** mouse_utils
*/

#include "window/render_window.h"

sfVector2f get_mouse_pos(win_t *win)
{
	sfVector2i pos1 = sfMouse_getPositionRenderWindow(win->sf_win);
	sfVector2f pos2 = sfRenderWindow_mapPixelToCoords(win->sf_win,
							pos1, win->view);

	return pos2;
}
