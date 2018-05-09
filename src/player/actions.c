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
#include "inventory.h"

void player_shoot(win_t *win, player_t *player)
{
	static sfClock *delay = NULL;
	const sfVector2f pl_pos = sfSprite_getPosition(player->sprite);
	inventory_t *inv = win->game->player->inventory;
	item_t *weapon = inv->item[inv->selected];

	if (!delay) {
		delay = sfClock_create();
		if (!delay)
			return;
	}
	if (!weapon || !weapon->name)
		return;
	if (sfTime_asSeconds(sfClock_getElapsedTime(delay)) < weapon->delay)
		return;
	play_sfx(win->game->sounds, SHOOT);
	create_shot(win, weapon, pl_pos, player->aim_angle);
	sfClock_restart(delay);
}

void player_door(win_t *win, sfVector2f *pos, room_t *room)
{
	door_transition(win->game->dungeon);
	if (!win->game->dungeon->door_open)
		return;
	door_action(win, pos, room);
}
