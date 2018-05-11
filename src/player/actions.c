/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** actions
*/

#include <SFML/Graphics.h>

#include "player.h"
#include "particle_shot.h"
#include "particle_rifle.h"
#include "particle_flame.h"
#include "particle_shotgun.h"
#include "dungeon.h"
#include "music.h"
#include "inventory.h"
#include "inventory_list.h"

static void shoot(win_t *win, item_t *weapon, player_t *player, sfVector2f pos)
{
	static sfClock *timer;
	uint32_t current_time = timer ? sfTime_asMilliseconds(
				sfClock_getElapsedTime(timer)) : 0;

	if (!timer)
		timer = sfClock_create();
	for (uint8_t i = 0; item_actions[i].name; i++) {
		if (!str_eq(weapon->name, item_actions[i].display_name))
			continue;
		if (current_time > item_actions[i].delay) {
			play_sfx(win->game->sounds, item_actions[i].sfx);
			sfClock_restart(timer);
		}
		for (uint8_t j = 0; j < item_actions[i].repeat; j++)
			item_actions[i].func(win, weapon, pos,
							player->aim_angle);
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
	sfClock_restart(win->game->player->immu);
}

void player_dash(player_t *player, bool press)
{
	static bool pressed = false;

	(void) player;
	if (!press && pressed) {
		write(1, "DASH!", 5);
		pressed = false;
		return;
	}
	if (!press)
		return;
	if (!pressed)
		pressed = true;
	write(1, ".", 1);
}
