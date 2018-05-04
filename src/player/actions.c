/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** actions
*/

#include <SFML/Graphics.h>

#include "player.h"
#include "particle_shot.h"

void player_shoot(win_t *win, player_t *player)
{
	const sfVector2f pl_pos = sfSprite_getPosition(player->sprite);

	create_shot(win, pl_pos, sfYellow, player->aim_angle);
}
