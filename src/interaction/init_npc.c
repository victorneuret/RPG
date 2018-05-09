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

npc_t *init_npc(void)
{
	npc_t *npc = malloc(sizeof(npc_t));
	sfFont *font = sfFont_createFromFile(FONT_PATH);

	npc->textbox = init_textbox();
	if (!npc || !font || !npc->textbox)
		return NULL;
	npc->pos = (sfVector2f) {1600, 180};
	npc->skin = sfRectangleShape_create();
	npc->talk = sfText_create();
	if (!npc->skin || !npc->talk)
		return NULL;
	sfRectangleShape_setPosition(npc->skin, npc->pos);
	sfRectangleShape_setFillColor(npc->skin, sfRed);
	sfRectangleShape_setSize(npc->skin, (sfVector2f) {100, 100});
	sfRectangleShape_setOutlineColor(npc->skin, sfBlue);
	sfRectangleShape_setOutlineThickness(npc->skin, 2);
	sfText_setFont(npc->talk, font);
	sfText_setString(npc->talk, "Press A to interact.");
	center_text(npc->talk, 870);
	return npc;
}

void npc_interaction(win_t *win)
{
	sfVector2f pos = sfSprite_getPosition(win->game->player->sprite);
	sfFloatRect rect = sfSprite_getGlobalBounds(win->game->player->sprite);
	sfFloatRect npc_rect =
		sfRectangleShape_getGlobalBounds(win->game->npc->skin);

	if (win->game->dungeon->act_room == 0
		&& pos.x + rect.width > win->game->npc->pos.x - 30
		&& pos.y < win->game->npc->pos.y + npc_rect.height + 50)
		win->game->npc->textbox->state = true;

}

void draw_npc(win_t *win, npc_t *npc)
{
	sfVector2f pos = sfSprite_getPosition(win->game->player->sprite);
	sfFloatRect rect = sfSprite_getGlobalBounds(win->game->player->sprite);
	sfFloatRect npc_rect = sfRectangleShape_getGlobalBounds(npc->skin);

	if (win->game->dungeon->act_room != 0)
		return;
	if (win->game->dungeon->act_room == 0
		&& pos.x + rect.width > win->game->npc->pos.x - 30
		&& pos.y < win->game->npc->pos.y + npc_rect.height + 30) {
		render_object(win->sf_win, TEXT, npc->talk);
		if (npc->textbox->state)
			render_object(win->sf_win, RECTANGLE,
				win->game->npc->textbox->rect);
	} else
		npc->textbox->state = false;
	render_object(win->sf_win, RECTANGLE, npc->skin);
}
