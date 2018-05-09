/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** init_npc
*/

#include <SFML/Graphics.h>
#include <stdlib.h>

#include "text_utils.h"
#include "render_window.h"
#include "render.h"
#include "npc.h"

static const char *FONT_PATH = "res/fonts/space_mono_regular.ttf";

npc_t *init_npc(void)
{
	npc_t *npc = malloc(sizeof(npc_t));
	sfFont *font = sfFont_createFromFile(FONT_PATH);

	if (!npc || !font)
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
	sfText_setString(npc->talk, "Press X to interact.");
	center_text(npc->talk, 870);
	return npc;
}

void discuss_npc(win_t *win)
{
	sfVector2f pos = sfSprite_getPosition(win->game->player->sprite);
	sfFloatRect rect = sfSprite_getGlobalBounds(win->game->player->sprite);
	sfFloatRect npc_rect = sfSprite_getGlobalBounds(win->game->npc->skin);

	if (win->game->dungeon->act_room == 0
		&& ((pos.x + rect.width > win->game->npc->pos.x - 30
		&& pos.x + rect.width < win->game->npc->pos.x - 20)
		|| (pos.y + rect. > win->game->npc->pos.x - 30)))
		return;
	create_popup(win->game->ui, "Hi!", INFO);
	pos.x = pos.x + rect.width - 10;
}

void draw_npc(win_t *win, npc_t *npc)
{
	sfVector2f pos = sfSprite_getPosition(win->game->player->sprite);
	sfFloatRect rect = sfSprite_getGlobalBounds(win->game->player->sprite);

	if (win->game->dungeon->act_room != 0)
		return;
	if (pos.x + rect.width > win->game->npc->pos.x - 30
		&& pos.x + rect.width < win->game->npc->pos.x - 20)
		render_object(win->sf_win, TEXT, npc->talk);
	render_object(win->sf_win, RECTANGLE, npc->skin);
}
