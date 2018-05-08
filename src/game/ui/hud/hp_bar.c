/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** hp_bar
*/

#include "player.h"
#include "hud.h"
#include "color_utils.h"
#include "str_utils.h"

void update_hp_bar(player_t *player)
{
	if (player->hp->value < 0)
		player->hp->value = 0;
	else if (player->hp->value > player->hp->max_value)
		player->hp->value = player->hp->max_value;
	sfRectangleShape_setSize(player->hp->bar, (sfVector2f) {HP_WIDTH /
		(float) player->hp->max_value * player->hp->value, HP_HEIGHT});
	sfText_setString(player->hp->text, int_to_str(player->hp->value));
}

void display_hp_bar(win_t *win)
{
	sfRenderWindow_drawRectangleShape(win->sf_win,
		win->game->player->hp->back_bar, 0);
	sfRenderWindow_drawRectangleShape(win->sf_win,
		win->game->player->hp->bar, 0);
	sfRenderWindow_drawText(win->sf_win, win->game->player->hp->text, 0);
}
