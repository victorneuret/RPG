/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** render_pause
*/

#include <SFML/Graphics.h>

#include "pause.h"
#include "render_window.h"

void render_pause(win_t *win, pause_t *pause)
{
	if (win->game_state != PAUSE)
		return;
	sfRenderWindow_drawSprite(win->sf_win, pause->background, 0);
	display_xp_bar(win);
}
