/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** draw_inventory
*/

#include <stdint.h>

#include "render_window.h"
#include "render.h"
#include "inventory.h"
#include "nb_utils.h"

void enemy_drop_item(sfVector2f enemy_pos, item_t *item_list)
{
	uint8_t item_nb = rand_int(SHOTGUN, FLAMETHROWER);
	uint8_t random = rand_int(0, 100);

	if (!item_list[item_nb].droped || item_list[item_nb].pos.x != 0 ||
					item_list[item_nb].rate < random)
		return;
	item_list[item_nb].pos = enemy_pos;
	sfSprite_setPosition(item_list[item_nb].sprite, item_list[item_nb].pos);
}
