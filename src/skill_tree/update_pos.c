/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** update_pos
*/

#include "stats_menu.h"
#include "render_window.h"

static void gamepad_move_mouse(win_t *win, sfVector2f orig_pos)
{
	sfVector2i pos = sfRenderWindow_mapCoordsToPixel(win->sf_win, orig_pos,
							win->view);
	sfVector2i view_pos = (sfVector2i) {orig_pos.x, orig_pos.y};

	win->joystick->switch_gamepad->gamepad_pos = view_pos;
	sfMouse_setPositionRenderWindow(pos, win->sf_win);
}

static void set_cursor_pos(win_t *win, sfSprite *sprite)
{
	sfFloatRect rect = sfSprite_getGlobalBounds(sprite);
	sfVector2f pos = {rect.left + rect.width / 2,
			rect.top + rect.height / 2};

	gamepad_move_mouse(win, pos);
}

void update_pos(skill_t **skill, win_t *win)
{
	static uint8_t x = 0;
	static uint8_t y = 0;

	if (sfClock_getElapsedTime(
		win->joystick->switch_gamepad->clock).microseconds < 100000)
		return;
	if (win->joystick->dirx > 60 && x < 3)
		x++;
	else if (win->joystick->dirx < -60 && x > 0)
		x--;
	if (win->joystick->diry > 60 && y > 0)
		y--;
	if (win->joystick->diry < -60 && y < 2)
		y++;
	set_cursor_pos(win, skill[x]->sprite[y]);
	sfClock_restart(win->joystick->switch_gamepad->clock);
}
