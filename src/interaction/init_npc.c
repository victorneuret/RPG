/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** init_npc
*/

#include <stdlib.h>

#include "interaction.h"
#include "npc.h"

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
