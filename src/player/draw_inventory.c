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
#include "xml.h"
#include "nb_utils.h"

static void draw_droped_items(win_t *win, inventory_t *inventory)
{
	for (uint8_t i = 0; i < (NB_ITEMS - 1); i++) {
		if (inventory->item_list[i].droped &&
				(inventory->item_list[i].pos.x != 0 &&
				inventory->item_list[i].pos.y != 0)) {
			render_object(win->sf_win, SPRITE,
					inventory->item_list[i].sprite);
		}
	}
}

static void draw_selected_item(win_t *win, item_t *item, inventory_t *inventory,
			sfVector2f pos)
{
	sfFloatRect rect;

	sfText_setString(inventory->text, item->name);
	sfText_setCharacterSize(inventory->text, 25);
	pos.y += 30;
	rect = sfText_getGlobalBounds(inventory->text);
	sfText_setOrigin(inventory->text,
			(sfVector2f){rect.width / 2, rect.height / 2});
	sfText_setPosition(inventory->text, pos);
	sfSprite_setScale(item->sprite, (sfVector2f){1.2, 1.2});
	render_object(win->sf_win, SPRITE, item->sprite);
	render_object(win->sf_win, TEXT, inventory->text);
	sfSprite_setScale(item->sprite, (sfVector2f){1.0, 1.0});
}

static void draw_item(win_t *win, item_t *item)
{
	sfSprite_setColor(item->sprite, sfColor_fromRGBA(255, 255, 255, 90));
	render_object(win->sf_win, SPRITE, item->sprite);
	sfSprite_setColor(item->sprite, sfColor_fromRGBA(255, 255, 255, 255));
}

static void draw_selected(win_t *win, uint8_t i, inventory_t *inventory,
			sfVector2f pos)
{
	if (i == inventory->selected)
		draw_selected_item(win, inventory->item[i], inventory, pos);
	else
		draw_item(win, inventory->item[i]);
}

void draw_inventory(win_t *win, inventory_t *inventory)
{
	sfVector2f pos = {1400, 1010};

	for (uint8_t i = 0; i < INVENTORY_NB; i++) {
		if (inventory->item[i] && !inventory->item[i]->droped) {
			sfSprite_setPosition(inventory->item[i]->sprite, pos);
			draw_selected(win, i, inventory, pos);
		}
		pos.x += 150;
	}
	draw_droped_items(win, inventory);
	if (inventory->display_message)
		render_object(win->sf_win, TEXT, inventory->message);
}
