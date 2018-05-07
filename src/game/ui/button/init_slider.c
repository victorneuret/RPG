/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** sliders
*/

#include <SFML/Graphics.h>
#include <stdbool.h>
#include <stdint.h>

#include "slider.h"
#include "my_calloc.h"

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
		tmp->next = my_calloc(1, sizeof(buttons_t));
		if (!tmp->next)
			return NULL;
		tmp->next->next = NULL;
	}
	return slider;
}

static bool fill_slider_list(const slider_declaration_t list, slider_t *slider)
{
	slider_t *tmp = slider;

	for (; tmp->next; tmp = tmp->next);
	tmp->selected = sfText_create();
	tmp->unselected = sfText_create();
	if (!tmp->selected || !tmp->unselected)
		return false;
	sfText_setString(tmp->unselected, "llllllllll");
	sfText_setCharacterSize(tmp->unselected, 50);
	sfText_setColor(tmp->unselected, sfBlue);
	sfText_setPosition(tmp->unselected, (sfVector2f){500, 500});
	tmp->game_state = list.game_state;
	tmp->color = list.color;
	tmp->hover_color = list.hover_color;
	tmp->size = list.size;
	tmp->elements = list.elements;
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
