/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** inventory
*/

#include <stdint.h>

#include "render_window.h"
#include "render.h"
#include "inventory.h"
#include "xml.h"
#include "nb_utils.h"
#include "str_utils.h"

void get_item(sfSprite *player, inventory_t *inventory)
{
	const sfFloatRect rect = sfSprite_getGlobalBounds(player);
	sfFloatRect item_rect;
	item_t *item_list = inventory->item_list;

	for (uint8_t i = 0; item_list[i].name; i++) {
		if (!item_list[i].droped && item_list[i].pos.x != 0)
			continue;
		item_rect = sfSprite_getGlobalBounds(item_list[i].sprite);
		if (sfFloatRect_intersects(&rect, &item_rect,
							&item_rect) == sfTrue) {
			inventory->display_message = true;
			return;
		}
	}
	inventory->display_message = false;
}

void add_item(inventory_t *inventory, uint8_t place,
			item_type item_nb)
{
	if (!inventory->item_list[item_nb].droped)
		return;
	for (size_t i = 0; i < INVENTORY_NB; i++) {
		if (!inventory->item[i] || inventory->item[i]->droped) {
			inventory->item[i] = &inventory->item_list[item_nb];
			inventory->item[i]->droped = false;
			inventory->item[i]->pos = (sfVector2f) {0, 0};
			sfSprite_setRotation(inventory->item[i]->sprite, 0);
			return;
		}
	}
	if (str_eq(inventory->item[place]->name, "Bubble"))
		return;
	inventory->item[place]->droped = true;
	inventory->item_list[item_nb].droped = false;
	inventory->item[place] = &inventory->item_list[item_nb];
}

void drop_item(win_t *win, inventory_t *inventory, uint8_t place)
{
	sfVector2f player_pos;

	if (!inventory->item[place] || !inventory->item[place]->name ||
				str_eq(inventory->item[place]->name, "Bubble"))
		return;
	player_pos = sfSprite_getPosition(win->game->player->sprite);
	player_pos.y += 66;
	inventory->item[place]->droped = true;
	inventory->item[place]->pos = player_pos;
	sfSprite_setPosition(inventory->item[place]->sprite,
						inventory->item[place]->pos);
	sfSprite_setRotation(inventory->item[place]->sprite, rand_int(0, 360));
	inventory->item[place] = NULL;
	inventory->selected = get_next_inventory(inventory, 1);
}

void free_inventory(inventory_t *inventory)
{
	sfText_destroy(inventory->text);
	sfFont_destroy(inventory->font);

	for (ssize_t i = 0; i < (INVENTORY_NB - 1); i++)
		sfSprite_destroy(inventory->item_list[i].sprite);
	free(inventory->item);
	free(inventory->item_list);
	free(inventory);
}

inventory_t *init_inventory(win_t *win)
{
	inventory_t *inventory = malloc(sizeof(inventory_t));

	inventory->item_list = malloc(sizeof(item_t) * NB_ITEMS);
	inventory->item = malloc(sizeof(item_t*) * INVENTORY_NB);
	inventory->selected = 0;
	inventory->display_message = false;
	inventory->text = sfText_create();
	inventory->message = sfText_create();
	inventory->font = sfFont_createFromFile(INVENTORY_FONT);
	if (!inventory->item_list || !inventory->item || !inventory->text ||
							!inventory->font)
		return NULL;
	sfText_setFont(inventory->text, inventory->font);
	sfText_setFont(inventory->message, inventory->font);
	sfText_setString(inventory->message, INVENTORY_MESSAGE);
	if (!xml_item(inventory->item_list, win->game->textures))
		return NULL;
	for (size_t i = 0; i < INVENTORY_NB; i++) {
		inventory->item[i] = malloc(sizeof(item_t));
		inventory->item[i]->droped = true;
		inventory->item[i]->name = NULL;
	}
	return inventory;
}
