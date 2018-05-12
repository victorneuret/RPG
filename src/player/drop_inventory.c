/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** draw_inventory
*/

#include <stdint.h>

#include "render_window.h"
#include "inventory.h"
#include "nb_utils.h"
#include "music.h"
#include "inventory_list.h"

void enemy_drop_item(sfVector2f enemy_pos, win_t *win)
{
	uint8_t item_nb = rand_int(SHOTGUN, NB_ITEMS - 1);
	uint8_t random = rand_int(0, 100);
	item_t *item_list = win->game->player->inventory->item_list;

	play_sfx(win->game->sounds, DEATH);
	if (!item_list[item_nb].droped || item_list[item_nb].pos.x != 0 ||
					item_list[item_nb].rate < random)
		return;
	item_list[item_nb].pos = enemy_pos;
	sfSprite_setPosition(item_list[item_nb].sprite, item_list[item_nb].pos);
}
