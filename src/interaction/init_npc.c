/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** init_npc
*/

#include <stdlib.h>

#include "interaction.h"
#include "npc.h"
#include "texture.h"
#include "sprite_utils.h"

static void set_npc_elements(npc_t *npc, sfFont *font)
{
	sfSprite_setPosition(npc->skin, npc->pos);
	sfText_setFont(npc->talk, font);
	sfText_setString(npc->talk, "Press A to interact.");
	center_text(npc->talk, 870);
}

npc_t *init_npc(textures_t *textures)
{
	npc_t *npc = malloc(sizeof(npc_t));
	sfFont *font = sfFont_createFromFile(FONT_PATH);
	sfTexture *texture = get_texture(textures, "npc")->texture;

	if (!texture)
		return NULL;
	npc->skin =
		get_sprite_texture_rect(texture, &(sfIntRect) {0, 0, 128, 128});
	npc->textbox = init_textbox();
	npc->quest = init_quest();
	npc->talk = sfText_create();
	npc->timer = sfClock_create();
	if (!npc || !font || !npc->textbox || !npc->quest
		|| !npc->skin || !npc->talk || !npc->skin || !npc->timer)
		return NULL;
	npc->pos = (sfVector2f) {1600, 180};
	npc->quest_id = 0;
	npc->elem = 0;
	set_npc_elements(npc, font);
	return npc;
}
