/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** title_page_functions
*/

#include <SFML/Graphics.h>

#include "popup.h"
#include "change_state.h"
#include "render_window.h"
#include "level.h"
#include "music.h"
#include "enemies.h"
#include "xml.h"
#include "hud.h"
#include "stats_menu.h"
#include "inventory.h"
#include "quest.h"
#include "save.h"
#include "popup.h"

static void reset_npc(npc_t *npc, quest_t *quest)
{
	npc->quest_id = 0;
	npc->quest_id = 0;
	for (size_t i = 0; quest_declaration[i].dialog; i++) {
		quest[i].last_quest = false;
		quest[i].quest_popup = false;
		quest[i].kill = quest_declaration[i].kill;
		quest[i].state = quest_declaration[i].state;
	}
}

void start_game(win_t *win)
{
	inventory_t *inventory = win->game->player->inventory;

	change_state(win, CUSTOM);
	wipe_enemies(&win->game->enemy_list);
	win->game->dungeon->cleared = false;
	win->game->player->level = 1;
	win->game->player->alive = true;
	load_level(&win->game->level, DUNGEON, win);
	xml_player(win->game->player);
	init_hud(win->game->player);
	init_skill(win->game->stats_menu->skill_tree, win->game->textures);
	for (uint8_t i = 0; i < INVENTORY_NB; i++)
		inventory->item[i] = NULL;
	for (uint8_t i = 0; i < NB_ITEMS; i++) {
		inventory->item_list[i].pos = (sfVector2f){0, 0};
		inventory->item_list[i].droped = true;
	}
	reset_npc(win->game->npc, win->game->npc->quest);
}

void to_option_menu(win_t *win)
{
	play_sfx(win->game->sounds, SWITCH_TITLE);
	sfSprite_setScale(win->game->ui->title_page->options,
					(sfVector2f){0, 0});
	sfSprite_setColor(win->game->ui->title_page->options,
					sfColor_fromRGBA(255, 255, 255, 0));
	change_state(win, OPTION);
}

void load_game(win_t *win)
{
	if (!save_exist(&win->game->save) || !win->game->player->alive) {
		create_popup(win->game->ui, CANT_FIND, ERROR);
		return;
	}
	if (!open_save(win, &win->game->save)) {
		create_popup(win->game->ui, CORRUPTED, ERROR);
		return;
	}
	load_level(&win->game->level, DUNGEON, win);
	change_state(win, GAME);
	win->game->dungeon->door_open = true;
}
