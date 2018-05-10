/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** quest
*/

#include <SFML/Graphics.h>

#include <stdlib.h>

#include "render.h"
#include "interaction.h"
#include "quest.h"

quest_t *init_quest(void)
{
	quest_t *quest = malloc(sizeof(quest_t) * 2);
	sfFont *font = sfFont_createFromFile(FONT_PATH);

	if (!quest || !font)
		return NULL;
	for (size_t i = 0; quest_declaration[i].dialog; i++) {
		quest[i].text = sfText_create();
		if (!quest[i].text)
			return NULL;
		quest[i].quest_id = quest_declaration[i].quest_id;
		quest[i].diag_elem = quest_declaration[i].diag_elem;
		quest[i].dialog = quest_declaration[i].dialog;
		quest[i].state = quest_declaration[i].state;
		sfText_setFont(quest[i].text, font);
		sfText_setCharacterSize(quest[i].text, 20);
		sfText_setPosition(quest[i].text,
			(sfVector2f) {TEXTBOX_POS_X + 10, TEXTBOX_POS_Y + 40});
	}
	return quest;
}
