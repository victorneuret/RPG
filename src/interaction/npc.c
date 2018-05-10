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

void npc_interaction(win_t *win)
{
	npc_t *npc = win->game->npc;
	sfVector2f pos = sfSprite_getPosition(win->game->player->sprite);
	sfFloatRect rect = sfSprite_getGlobalBounds(win->game->player->sprite);
	sfFloatRect npc_rect = sfRectangleShape_getGlobalBounds(npc->skin);

	if (win->game->dungeon->act_room == 0
		&& pos.x + rect.width > npc->pos.x - 30
		&& pos.y < npc->pos.y + npc_rect.height + 50) {
		win->game->npc->textbox->state = true;
		if (npc->quest[npc->quest_id].dialog[npc->elem])
			sfText_setString(npc->quest[npc->quest_id].text,
				npc->quest[npc->quest_id].dialog[npc->elem]);
		npc->elem++;
	}
	if (npc->elem > npc->quest->diag_elem
		&& npc->quest[npc->quest_id].state)
		npc->quest_id++;
}

static void manage_npc_interaction(uint8_t id, npc_t *npc, win_t *win)
{
	if (npc->textbox->state && npc->elem != 0
		&& npc->elem <= npc->quest[id].diag_elem) {
		render_object(win->sf_win, RECTANGLE,
			win->game->npc->textbox->rect);
		render_object(win->sf_win, TEXT, npc->textbox->name);
		render_object(win->sf_win, TEXT, npc->quest[id].text);
	} else {
		render_object(win->sf_win, TEXT, npc->talk);
		npc->elem = 0;
	}
}

static void check_current_quest(win_t *win, npc_t *npc)
{
	switch (npc->quest[npc->quest_id].quest_type) {
	case KILL:
	case WEAPON:
		if (npc->quest[npc->quest_id].kill <= 0) {
			npc->quest[npc->quest_id++].state = true;
			create_popup(win->game->ui, "Quest finished!", SUCCESS);
			npc->elem = 0;
		}
		break;
	default:
		break;
	}
}

void draw_npc(win_t *win, npc_t *npc)
{
	sfVector2f pos = sfSprite_getPosition(win->game->player->sprite);
	sfFloatRect rect = sfSprite_getGlobalBounds(win->game->player->sprite);
	sfFloatRect npc_rect = sfRectangleShape_getGlobalBounds(npc->skin);
	uint8_t id = npc->quest_id;

	check_current_quest(win, npc);
	if (win->game->dungeon->act_room != 0)
		return;
	if (win->game->dungeon->act_room == 0
		&& pos.x + rect.width > win->game->npc->pos.x - 30
		&& pos.y < win->game->npc->pos.y + npc_rect.height + 30) {
		manage_npc_interaction(id, npc, win);
	} else
		npc->textbox->state = false;
	render_object(win->sf_win, RECTANGLE, npc->skin);
}
