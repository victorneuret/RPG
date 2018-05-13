/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** init_npc
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdbool.h>

#include "text_utils.h"
#include "render_window.h"
#include "render.h"
#include "npc.h"
#include "textbox.h"
#include "quest.h"
#include "hud.h"
#include "music.h"
#include "particle_xp.h"
#include "interaction.h"

static void check_interaction(win_t *win, npc_t *npc)
{
	sfVector2f pos = sfSprite_getPosition(win->game->player->sprite);
	sfFloatRect rect = sfSprite_getGlobalBounds(win->game->player->sprite);
	sfFloatRect npc_rect = sfSprite_getGlobalBounds(npc->skin);
	sfVector2f xp_pos = {npc->pos.x + npc_rect.width / 2,
		npc->pos.y + npc_rect.height / 2};

	if (win->game->dungeon->act_room == 0
			&& pos.x + rect.width > npc->pos.x - 30
			&& pos.y < npc->pos.y + npc_rect.height + 50) {
		npc->textbox->state = true;
		if (npc->quest[npc->quest_id].dialog[npc->elem])
			sfText_setString(npc->quest[npc->quest_id].text,
				npc->quest[npc->quest_id].dialog[npc->elem]);
		npc->elem++;
		if (npc->quest[npc->quest_id].last_quest) {
			particle_xp(win, 500 * npc->quest_id, xp_pos);
			npc->quest[npc->quest_id].last_quest = false;
		}
	}
}

void npc_interaction(win_t *win)
{
	npc_t *npc = win->game->npc;
	uint8_t id = npc->quest_id;
	item_t *item_list = win->game->player->inventory->item_list;

	check_interaction(win, npc);
	if (npc->elem > npc->quest[id].diag_elem && !npc->quest[id].quest_popup
			&& npc->quest[id].weapon_quest != NONE_WEAPON_QUEST) {
		create_popup(win->game->ui, "New quest.", INFO);
		play_sfx(win->game->sounds, NEW_QUEST);
		npc->quest[id].quest_popup = true;
	}
	if (npc->elem > npc->quest[id].diag_elem && id == 0) {
		item_list[0].pos = (sfVector2f){1920 / 2, 1080 / 2};
		sfSprite_setPosition(item_list[0].sprite, item_list[0].pos);
	}
	if (npc->elem > npc->quest[id].diag_elem
			&& npc->quest[id].state) {
		npc->quest_id++;
		npc->elem = 0;
	}
}

static void manage_npc_interaction(uint8_t id, npc_t *npc, win_t *win)
{
	sfIntRect rect = sfSprite_getTextureRect(npc->skin);

	rect.left = 0;
	if (npc->textbox->state && npc->elem != 0
			&& npc->elem <= npc->quest[id].diag_elem) {
		render_object(win->sf_win, RECTANGLE, npc->textbox->rect);
		render_object(win->sf_win, TEXT, npc->textbox->name);
		render_object(win->sf_win, TEXT, npc->quest[id].text);
		if (sfClock_getElapsedTime(npc->timer).microseconds > 200000) {
			animate_sprite(npc->skin,
				sfSprite_getGlobalBounds(npc->skin).width, 2);
			sfClock_restart(npc->timer);
		}
	} else {
		sfSprite_setTextureRect(npc->skin, rect);
		render_object(win->sf_win, TEXT, npc->talk);
		npc->elem = 0;
	}
}

static void check_current_quest(win_t *win, npc_t *npc)
{
	if (npc->quest[npc->quest_id].weapon_quest == NONE_WEAPON_QUEST
			&& npc->quest_id == 0
			&& win->game->player->inventory->item[0]) {
		play_sfx(win->game->sounds, OPEN);
		open_door(win);
		npc->quest[npc->quest_id++].state = true;
	}
	if (npc->quest[npc->quest_id].weapon_quest != NONE_WEAPON_QUEST
			&& npc->quest[npc->quest_id].kill <= 0) {
		npc->quest[npc->quest_id++].state = true;
		npc->quest[npc->quest_id].last_quest = true;
		create_popup(win->game->ui, "Quest complete!", SUCCESS);
		play_sfx(win->game->sounds, END_QUEST);
		npc->elem = 0;
	}
	if (npc->quest_id == (NB_QUEST_STRUCT - 1)
			&& npc->quest[npc->quest_id].kill == 0
			&& npc->elem > 0) {
		create_popup(win->game->ui, "Game finished!", SUCCESS);
		npc->quest[npc->quest_id].kill += 1;
	}
}

void draw_npc(win_t *win, npc_t *npc)
{
	sfVector2f pos = sfSprite_getPosition(win->game->player->sprite);
	sfFloatRect rect = sfSprite_getGlobalBounds(win->game->player->sprite);
	sfFloatRect npc_rect = sfSprite_getGlobalBounds(npc->skin);
	sfIntRect skin_rect = sfSprite_getTextureRect(npc->skin);

	skin_rect.left = 0;
	check_current_quest(win, npc);
	if (win->game->dungeon->act_room != 0)
		return;
	if (win->game->dungeon->act_room == 0
			&& pos.x + rect.width > npc->pos.x - 30
			&& pos.y < npc->pos.y + npc_rect.height + 30) {
		manage_npc_interaction(npc->quest_id, npc, win);
	} else {
		sfSprite_setTextureRect(npc->skin, skin_rect);
		npc->textbox->state = false;
	}
	render_object(win->sf_win, SPRITE, npc->skin);
	render_object(win->sf_win, SPRITE, npc->help);
}
