/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** idle
*/

#include "player.h"

void update_idle(player_t *player, uint8_t dir)
{
	sfIntRect rect = sfSprite_getTextureRect(player->sprite);

	switch (dir) {
	case LEFT:
		rect.top = 792;
		break;
	case RIGHT:
		rect.top = 660;
		break;
	case TOP:
		rect.top = 528;
		break;
	case BOTTOM:
		rect.top = 924;
		break;
	}
	sfSprite_setTextureRect(player->sprite, rect);
	animate_sprite(player->sprite,
			sfSprite_getGlobalBounds(player->sprite).width, 2);
}
