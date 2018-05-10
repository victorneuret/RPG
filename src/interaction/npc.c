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
#include "interaction.h"

static void set_npc_elements(npc_t *npc, sfFont *font)
{
	sfRectangleShape_setPosition(npc->skin, npc->pos);
	sfRectangleShape_setFillColor(npc->skin, sfRed);
	sfRectangleShape_setSize(npc->skin, (sfVector2f) {100, 100});
	sfRectangleShape_setOutlineColor(npc->skin, sfBlue);
	sfRectangleShape_setOutlineThickness(npc->skin, 2);
	sfText_setFont(npc->talk, font);
	sfText_setString(npc->talk, "Press A to interact.");
	center_text(npc->talk, 870);
}

npc_t *init_npc(void)
{
	npc_t *npc = malloc(sizeof(npc_t));
	sfFont *font = sfFont_createFromFile(FONT_PATH);

	npc->textbox = init_textbox();
	npc->quest = init_quest();
	npc->skin = sfRectangleShape_create();
	npc->talk = sfText_create();
	if (!npc || !font || !npc->textbox || !npc->quest
		|| !npc->skin || !npc->talk)
		return NULL;
	npc->pos = (sfVector2f) {1600, 180};
	npc->quest_id = 0;
	npc->elem = 0;
	set_npc_elements(npc, font);
	return npc;
}

void npc_interaction(win_t *win)
{
	sfVector2f pos = sfSprite_getPosition(win->game->player->sprite);
	sfFloatRect rect = sfSprite_getGlobalBounds(win->game->player->sprite);
	sfFloatRect npc_rect =
		sfRectangleShape_getGlobalBounds(win->game->npc->skin);
	uint8_t id = win->game->npc->quest_id;
	uint8_t elem = win->game->npc->elem++;

	if (win->game->dungeon->act_room == 0
		&& pos.x + rect.width > win->game->npc->pos.x - 30
		&& pos.y < win->game->npc->pos.y + npc_rect.height + 50) {
		win->game->npc->textbox->state = true;
		if (win->game->npc->quest[id].dialog[elem]) {
			sfText_setString(win->game->npc->quest[id].text,
				win->game->npc->quest[id].dialog[elem]);
		}
	} else
		win->game->npc->elem--;
	if (elem >= win->game->npc->quest->diag_elem)
		win->game->npc->quest_id = 1;
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

void draw_npc(win_t *win, npc_t *npc)
{
	sfVector2f pos = sfSprite_getPosition(win->game->player->sprite);
	sfFloatRect rect = sfSprite_getGlobalBounds(win->game->player->sprite);
	sfFloatRect npc_rect = sfRectangleShape_getGlobalBounds(npc->skin);
	uint8_t id = npc->quest_id;

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
