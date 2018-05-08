/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** xp_bar
*/

#include <SFML/Graphics.h>

#include "render_window.h"
#include "particle_explosion.h"
#include "color_utils.h"

static void update_xp_bar(player_t *player)
{
	if (player->xp->value < 0)
		player->xp->value = 0;
	else if (player->xp->value >= player->xp->max_value) {
		player->level += 1;
	}
}

static void bar_animation(win_t *win, player_t *player)
{
	float x_pos;
	static uint16_t xp = 0;

	if (xp < player->xp->value && xp < player->xp->max_value) {
		xp += 2 * player->level;
		x_pos = XP_WIDTH / (float) player->xp->max_value * xp;
		sfRectangleShape_setSize(player->xp->bar,
				(sfVector2f) {x_pos, XP_HEIGHT});
		create_explosion(win, 3, (sfVector2f){x_pos, 1070},
				hex_to_rgb(0xFFEB3B));
	} else if (xp >= player->xp->max_value) {
		xp = 0;
		player->xp->value = player->xp->value - player->xp->max_value;
		player->xp->max_value *= player->xp->mult;
		x_pos = XP_WIDTH / (float) player->xp->max_value * xp;
		sfRectangleShape_setSize(player->xp->bar,
				(sfVector2f) {x_pos, XP_HEIGHT});
		create_explosion(win, 3, (sfVector2f){x_pos, 1070},
				hex_to_rgb(0xFFEB3B));
	}
}

void display_xp_bar(win_t *win)
{
	static int16_t value = 0;

	if (value != win->game->player->xp->value)
		update_xp_bar(win->game->player);
	bar_animation(win, win->game->player);
	sfRenderWindow_drawRectangleShape(win->sf_win,
		win->game->player->xp->back_bar, 0);
	sfRenderWindow_drawRectangleShape(win->sf_win,
		win->game->player->xp->bar, 0);
	value = win->game->player->xp->value;
}
