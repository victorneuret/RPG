/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** init_text_area
*/

#include "text_area.h"

static text_area_t *init_text_area_list(text_area_t *text_area)
{
	text_area_t *tmp = text_area;

	if (!tmp) {
		text_area = malloc(sizeof(text_area_t));
		if (!text_area)
			return NULL;
		text_area->next = NULL;
	} else {
		for (; tmp->next; tmp = tmp->next);
		tmp->next = malloc(sizeof(text_area_t));
		if (!tmp->next)
			return NULL;
		tmp->next->next = NULL;
	}
	return text_area;
}

static bool fill_text_area_list(const text_area_declaration_t list,
	text_area_t *text_area)
{
	text_area_t *tmp = text_area;
	sfVector2f text_pos = (sfVector2f) {list.pos.x + 5, list.pos.y / 2};

	for (; tmp->next; tmp = tmp->next);
	tmp->game_state = list.game_state;
	tmp->nb_char_max = list.font_size / list.size.x * 2 + 10;
	tmp->box = sfRectangleShape_create();
	tmp->font = sfFont_createFromFile(list.path_to_font);
	tmp->box = init_rectangle(list.pos, list.size,
				hex_to_rgba(list.text_area_color));
	if (!tmp->box || !tmp->font)
		return false;
	tmp->text = init_text(tmp->font, "", text_pos, list.font_size);
	tmp->text_label = list.text_label;
	tmp->label = init_text(tmp->font, tmp->text_label, text_pos,
				list.font_size);
	if (!tmp->text || !tmp->text_label)
		return false;
	tmp->input_text = malloc(sizeof(char) * tmp->nb_char_max);
	tmp->text_label = list.text_label;
	return true;
}

text_area_t *load_text_area(void)
{
	text_area_t *text_area = NULL;

	for (size_t i = 0; text_area_declaration[i].path_to_font; i++) {
		text_area = init_text_area_list(text_area);
		if (!text_area)
			return NULL;
		if (!fill_text_area_list(text_area_declaration[i],
					text_area))
			return NULL;
	}
	return text_area;
}

void free_text_area(text_area_t *text_area)
{
	if (text_area && text_area->next)
		free_text_area(text_area->next);
	sfRectangleShape_destroy(text_area->box);
	sfFont_destroy(text_area->font);
	sfText_destroy(text_area->text);
	free(text_area->input_text);
	free(text_area);
}
