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
	change_state(win, GAME);
	load_level(&win->game->level, DUNGEON, win);
	xml_player(win->game->player);
	init_hud(win->game->player);
	init_skill(win->game->stats_menu->skill_tree, win->game->textures);
	for (uint8_t i = 0; i < INVENTORY_NB; i++)
    		win->game->player->inventory->item[i] = NULL;
	win->game->player->inventory->item[0] =
				&win->game->player->inventory->item_list[0];
	reset_npc(win->game->npc, win->game->npc->quest);
}

void error_test(win_t *win)
{
	create_popup(win->game->ui, "This button is useless", ERROR);
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
