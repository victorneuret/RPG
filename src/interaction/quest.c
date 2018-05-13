/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** quest
*/

#include <SFML/Graphics.h>

#include <stdlib.h>
#include <stddef.h>

#include "render.h"
#include "interaction.h"
#include "quest.h"

static void set_quest_text(size_t i, quest_t *quest, sfFont *font)
{
	sfText_setFont(quest[i].text, font);
	sfText_setCharacterSize(quest[i].text, 20);
	sfText_setPosition(quest[i].text,
		(sfVector2f) {TEXTBOX_POS_X + 10, TEXTBOX_POS_Y + 40});
}

quest_t *init_quest(void)
{
	quest_t *quest = malloc(sizeof(quest_t) * NB_QUEST_STRUCT);
	sfFont *font = sfFont_createFromFile(FONT_PATH);

	if (!quest || !font)
		return NULL;
	for (size_t i = 0; i < NB_QUEST_STRUCT; i++) {
		quest[i].text = sfText_create();
		if (!quest[i].text)
			return NULL;
		quest[i].last_quest = false;
		quest[i].quest_popup = false;
		quest[i].weapon_quest = quest_declaration[i].weapon_quest;
		quest[i].enemy_quest = quest_declaration[i].enemy_quest;
		quest[i].kill = quest_declaration[i].kill;
		quest[i].quest_id = quest_declaration[i].quest_id;
		quest[i].diag_elem = quest_declaration[i].diag_elem;
		quest[i].dialog = quest_declaration[i].dialog;
		quest[i].state = quest_declaration[i].state;
		set_quest_text(i, quest, font);
	}
	return quest;
}
