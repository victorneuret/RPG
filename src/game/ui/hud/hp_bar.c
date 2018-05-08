/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** hp_bar
*/

#include <stdbool.h>

#include "player.h"
#include "hud.h"
#include "color_utils.h"
#include "str_utils.h"

// static void set_origin_top_right(player_t *player)
// {
// 	sfFloatRect rect = sfRectangleShape_getGlobalBounds(
// 							player->hud->hp_bar);

// 	sfRectangleShape_setOrigin(player->hud->hp_bar, (sfVector2f)
// 				{rect.width, rect.top});
// 	rect = sfRectangleShape_getGlobalBounds(player->hud->hp_back_bar);
// 	sfRectangleShape_setOrigin(player->hud->hp_back_bar, (sfVector2f)
// 				{rect.width, rect.top});
// 	sfRectangleShape_setPosition(player->hud->hp_bar,
// 					(sfVector2f) {1840, 40});
// 	sfRectangleShape_setPosition(player->hud->hp_back_bar,
// 					(sfVector2f) {1840, 40});
// }

void update_hp_bar(player_t *player)
{
	if (player->hp->hp < 0)
		player->hp->hp = 0;
	else if (player->hp->hp > player->hp->max_hp)
		player->hp->hp = player->hp->max_hp;
	sfRectangleShape_setSize(player->hp->hp_bar, (sfVector2f) {HP_WIDTH /
		(float) player->hp->max_hp * player->hp->hp, HP_HEIGHT});
	sfText_setString(player->hp->text, int_to_str(player->hp->hp));
}

void display_hp_bar(win_t *win)
{
	sfRenderWindow_drawRectangleShape(win->sf_win,
		win->game->player->hp->hp_back_bar, 0);
	sfRenderWindow_drawRectangleShape(win->sf_win,
		win->game->player->hp->hp_bar, 0);
	sfRenderWindow_drawText(win->sf_win, win->game->player->hp->text, 0);
}
