/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** draw_stat_menu
*/

#include <SFML/Graphics.h>

#include "stats_menu.h"
#include "render_window.h"

void draw_stat_menu(win_t *win, stats_menu_t *menu)
{
	sfRenderWindow_drawRectangleShape(win->sf_win, menu->background, 0);
	sfRenderWindow_drawText(win->sf_win, menu->stats->slash, 0);
	sfRenderWindow_drawSprite(win->sf_win, menu->stats->xp_sprite, 0);
}
