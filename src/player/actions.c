/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** actions
*/

#include <SFML/Graphics.h>

#include "player.h"
#include "particle_shot.h"
#include "dungeon.h"
#include "music.h"

void player_shoot(win_t *win, player_t *player)
{
	const sfVector2f pl_pos = sfSprite_getPosition(player->sprite);

	play_sfx(win->game->sounds, SHOOT);
	create_shot(win, pl_pos, sfYellow, player->aim_angle);
}

void player_door(win_t *win, sfVector2f *pos, room_t *room)
{
	if (!win->game->dungeon->door_open)
		return;
	door_action(win, pos, room);
}
