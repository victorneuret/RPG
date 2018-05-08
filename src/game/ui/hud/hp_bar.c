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

bool init_hud(player_t *player)
{
	player->hud = malloc(sizeof(hud_t));
	sfFloatRect rect;

	if (!player->hud)
		return false;
	player->hud->hp_bar = sfRectangleShape_create();
	if (!player->hud->hp_bar)
		return false;
	sfRectangleShape_setSize(player->hud->hp_bar, (sfVector2f)
		{player->hp * (player->level * player->hp_mult) * HP_WIDTH_MULT,
		HP_HEIGHT});
	sfRectangleShape_setScale(player->hud->hp_bar, (sfVector2f) {1, 1});
	rect = sfRectangleShape_getGlobalBounds(player->hud->hp_bar);
	sfRectangleShape_setOrigin(player->hud->hp_bar, (sfVector2f)
				{rect.width, rect.top});
	sfRectangleShape_setPosition(player->hud->hp_bar,
					(sfVector2f) {1900, 20});
	sfRectangleShape_setFillColor(player->hud->hp_bar,
				hex_to_rgb(0xFF0000));
	return true;
}

void display_hp_bar(win_t *win)
{
	sfRenderWindow_drawRectangleShape(win->sf_win,
		win->game->player->hud->hp_bar, 0);
}
