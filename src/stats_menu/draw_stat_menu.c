/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** draw_stat_menu
*/

#include <SFML/Graphics.h>

#include "stats_menu.h"
#include "render_window.h"
#include "stats_menu.h"

static void print_slash(win_t *win, stats_t *stats)
{
	sfFloatRect rect = sfText_getGlobalBounds(stats->hp);

	sfText_setPosition(stats->slash, (sfVector2f)
				{rect.left + rect.width, rect.top - 35});
	sfRenderWindow_drawText(win->sf_win, stats->slash, 0);
	rect = sfText_getGlobalBounds(stats->xp);
	sfText_setPosition(stats->slash, (sfVector2f)
				{rect.left + rect.width, rect.top - 35});
	sfRenderWindow_drawText(win->sf_win, stats->slash, 0);
}

void draw_stat_menu(win_t *win, stats_menu_t *menu)
{
	update_stat_menu(menu, win->game->player);
	sfRenderWindow_drawRectangleShape(win->sf_win, menu->background, 0);
	sfRenderWindow_drawSprite(win->sf_win, menu->stats->xp_sprite, 0);
	sfRenderWindow_drawSprite(win->sf_win, menu->stats->hp_sprite, 0);
	sfRenderWindow_drawSprite(win->sf_win, menu->stats->sp_sprite, 0);
	sfRenderWindow_drawSprite(win->sf_win, menu->stats->player, 0);
	sfRenderWindow_drawText(win->sf_win, menu->stats->hp, 0);
	sfRenderWindow_drawText(win->sf_win, menu->stats->hp_max, 0);
	sfRenderWindow_drawText(win->sf_win, menu->stats->xp, 0);
	sfRenderWindow_drawText(win->sf_win, menu->stats->xp_max, 0);
	sfRenderWindow_drawText(win->sf_win, menu->stats->level, 0);
	sfRenderWindow_drawText(win->sf_win, menu->stats->level_text, 0);
	sfRenderWindow_drawText(win->sf_win, menu->stats->sp, 0);
	print_slash(win, menu->stats);
	if (sfClock_getElapsedTime(win->game->player->timer).microseconds
							> 500000) {
		animate_sprite(menu->stats->player,
			sfSprite_getGlobalBounds(menu->stats->player).width, 2);
		sfClock_restart(win->game->player->timer);
	}
	display_xp_bar(win);
}
