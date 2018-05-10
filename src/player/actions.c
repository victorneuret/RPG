/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** actions
*/

#include <SFML/Graphics.h>

#include "player.h"
#include "particle_shot.h"
#include "particle_flame.h"
#include "particle_shotgun.h"
#include "dungeon.h"
#include "music.h"
#include "inventory.h"

static void shoot(win_t *win, item_t *weapon, player_t *player, sfVector2f pos)
{
	static sfClock *timer;
	uint32_t current_time = timer ? sfTime_asMilliseconds(
				sfClock_getElapsedTime(timer)) : 0;

	if (!timer)
		timer = sfClock_create();
	if (str_eq(weapon->name, "Bubble")) {
		play_sfx(win->game->sounds, WP_GUN);
		create_shot(win, weapon, pos, player->aim_angle);
	}
	if (str_eq(weapon->name, "The Shotgun")) {
		play_sfx(win->game->sounds, WP_SHOTGUN);
		for (size_t i = 0; i < 20; i++)
			shotgun(win, weapon, pos, player->aim_angle);
	}
	if (str_eq(weapon->name, "Flamethrower")) {
		if (current_time > 350.f) {
			play_sfx(win->game->sounds, WP_FLAMETHROWER);
			sfClock_restart(timer);
		}
		for (size_t i = 0; i < 15; i++)
			create_flame(win, weapon, pos, player->aim_angle);
	}
}

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
	shoot(win, weapon, player, pl_pos);
	sfClock_restart(delay);
}

void player_door(win_t *win, sfVector2f *pos, room_t *room)
{
	door_transition(win->game->dungeon);
	if (!win->game->dungeon->door_open)
		return;
	door_action(win, pos, room);
}
