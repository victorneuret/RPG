/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** sliders
*/

#include <SFML/Graphics.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#include "slider.h"
#include "my_calloc.h"

char *get_string_from_char(char c, uint8_t len)
{
	char *str = malloc(sizeof(char) * (len + 1));

	if (len == 0 || !str)
		return NULL;
	for (uint8_t i = 0; i < len; i++)
		str[i] = c;
	str[len] = '\0';
	return str;
}

static slider_t *init_slider_list(slider_t *slider)
{
	slider_t *tmp = slider;

	if (!tmp) {
		slider = my_calloc(1, sizeof(slider_t));
		if (!slider)
			return NULL;
		slider->next = NULL;
	} else {
		for (; tmp->next; tmp = tmp->next);
		tmp->next = my_calloc(1, sizeof(slider_t));
		if (!tmp->next)
			return NULL;
		tmp->next->next = NULL;
	}
	return slider;
}

static bool set_slider_text(slider_t *tmp)
{
	sfFont *font = sfFont_createFromFile("res/fonts/isaac_sans.ttf");
	char *str1 = get_string_from_char('\'', tmp->elements / 2);
	char *str2 = get_string_from_char('\'', tmp->elements);

	if (!str1 || !str2)
		return false;
	sfText_setFont(tmp->selected, font);
	sfText_setFont(tmp->unselected, font);
	sfText_setString(tmp->selected, str1);
	sfText_setString(tmp->unselected, str2);
	sfText_setCharacterSize(tmp->selected, tmp->size);
	sfText_setCharacterSize(tmp->unselected, tmp->size);
	sfText_setColor(tmp->selected, tmp->hover_color);
	sfText_setColor(tmp->unselected, tmp->color);
	sfText_setPosition(tmp->selected, tmp->pos);
	sfText_setPosition(tmp->unselected, tmp->pos);
	free(str1);
	free(str2);
	return true;
}

static bool fill_slider_list(const slider_declaration_t list, slider_t *slider)
{
	slider_t *tmp = slider;

	for (; tmp->next; tmp = tmp->next);
	tmp->selected = sfText_create();
	tmp->unselected = sfText_create();
	if (!tmp->selected || !tmp->unselected)
		return false;
	tmp->color = list.color;
	tmp->hover_color = list.hover_color;
	tmp->pos = list.pos;
	tmp->size = list.size;
	tmp->elements = list.elements;
	if (!set_slider_text(tmp))
		return false;
	tmp->game_state = list.game_state;
	tmp->max_value = list.max_value;
	tmp->func = list.func;
	tmp->hover = false;
	return true;
}

slider_t *init_slider(void)
{
	slider_t *slider = NULL;

	for (uint8_t i = 0; slider_declaration[i].max_value > 0; i++) {
		slider = init_slider_list(slider);
		if (!slider)
			return NULL;
		if (!fill_slider_list(slider_declaration[i], slider))
			return NULL;
	}
	return slider;
}
