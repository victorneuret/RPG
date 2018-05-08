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

void update_xp_bar(player_t *player, win_t *win)
{
	float x_pos;

	if (player->xp->value < 0)
		player->xp->value = 0;
	else if (player->xp->value > player->xp->max_value)
		player->xp->value = player->xp->max_value;
	x_pos = XP_WIDTH / (float) player->xp->max_value * player->xp->value;
	sfRectangleShape_setSize(player->xp->bar, (sfVector2f)
						{x_pos, XP_HEIGHT});
	sfText_setString(player->xp->text, int_to_str(player->xp->value));
	create_explosion(win, 1, (sfVector2f){x_pos, 1070},
			hex_to_rgb(0xFFEB3B));
}

void display_xp_bar(win_t *win)
{
	sfRenderWindow_drawRectangleShape(win->sf_win,
		win->game->player->xp->back_bar, 0);
	sfRenderWindow_drawRectangleShape(win->sf_win,
		win->game->player->xp->bar, 0);
	sfRenderWindow_drawText(win->sf_win, win->game->player->xp->text, 0);
}
