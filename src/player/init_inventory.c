/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** init_inventory
*/

#include <stdbool.h>
#include <stdlib.h>

#include "render_window.h"
#include "inventory.h"
#include "xml.h"

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

static bool init_inventory_text(inventory_t *inventory)
{
	inventory->text = sfText_create();
	inventory->message = sfText_create();
	inventory->font = sfFont_createFromFile(INVENTORY_FONT);

	if (!inventory->text || !inventory->message || !inventory->font)
		return false;
	sfText_setFont(inventory->text, inventory->font);
	sfText_setFont(inventory->message, inventory->font);
	sfText_setString(inventory->message, INVENTORY_MESSAGE);
	center_text(inventory->message, 870);
	return true;
}

static inventory_t *init_inventory_struct(void)
{
	inventory_t *inventory = malloc(sizeof(inventory_t));

	if (!inventory)
		return NULL;
	inventory->item_list = malloc(sizeof(item_t) * NB_ITEMS);
	inventory->item = malloc(sizeof(item_t*) * INVENTORY_NB);
	if (!inventory->item_list || !inventory->item)
		return NULL;
	inventory->selected = 0;
	inventory->display_message = false;
	return inventory;
}

inventory_t *init_inventory(win_t *win)
{
	inventory_t *inventory = init_inventory_struct();

	if (!inventory || !init_inventory_text(inventory))
		return NULL;
	if (!xml_item(inventory->item_list, win->game->textures))
		return NULL;
	for (size_t i = 0; i < INVENTORY_NB; i++)
		inventory->item[i] = NULL;
	return inventory;
}
