/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** init_hud
*/

#include <SFML/Graphics.h>

#include <stdbool.h>

#include "player.h"
#include "hud.h"
#include "color_utils.h"
#include "str_utils.h"
#include "text_utils.h"

static bool init_hp_bar(sfRectangleShape **bar, player_t *player)
{
	sfFont *font =
		sfFont_createFromFile("res/fonts/space_mono_regular.ttf");

	if (!font)
		return false;
	player->hp->text = init_text(font, int_to_str(player->hp->value),
				(sfVector2f) {50, 958}, 40);
	if (!player->hp->text)
		return false;
	sfText_setStyle(player->hp->text, sfTextBold);
	*bar = sfRectangleShape_create();
	if (!bar)
		return false;
	sfRectangleShape_setSize(*bar, (sfVector2f) {HP_WIDTH, HP_HEIGHT});
	sfRectangleShape_setScale(*bar, (sfVector2f) {1, 1});
	sfRectangleShape_setPosition(*bar, (sfVector2f) {40, 1008});
	return true;
}

static bool init_xp_bar(sfRectangleShape **bar)
{
	*bar = sfRectangleShape_create();
	if (!bar)
		return false;
	sfRectangleShape_setSize(*bar, (sfVector2f) {XP_WIDTH, XP_HEIGHT});
	sfRectangleShape_setScale(*bar, (sfVector2f) {1, 1});
	sfRectangleShape_setPosition(*bar, (sfVector2f) {0, 1070});
	return true;
}

bool init_hud(player_t *player)
{
	if (!init_hp_bar(&player->hp->bar, player)
		|| !init_hp_bar(&player->hp->back_bar, player))
		return false;
	sfRectangleShape_setFillColor(player->hp->bar, hex_to_rgb(0xF44336));
	sfRectangleShape_setFillColor(player->hp->back_bar,
					hex_to_rgba(0xFFFFFF55));
	if (!init_xp_bar(&player->xp->bar)
		|| !init_xp_bar(&player->xp->back_bar))
		return false;
	sfRectangleShape_setFillColor(player->xp->bar, hex_to_rgb(0xFFEB3B));
	sfRectangleShape_setFillColor(player->xp->back_bar,
					hex_to_rgba(0xFFFFFF55));
	sfRectangleShape_setSize(player->xp->bar, (sfVector2f) {0, XP_HEIGHT});
	return true;
}
