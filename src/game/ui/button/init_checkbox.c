/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** init_checkbox
*/

#include "buttons.h"
#include "my_calloc.h"

static checkbox_t *init_checkbox_list(checkbox_t *checkbox)
{
	checkbox_t *tmp = checkbox;

	if (!tmp) {
		checkbox = my_calloc(1, sizeof(checkbox_t));
		if (!checkbox)
			return NULL;
		checkbox->next = NULL;
		checkbox->prev = NULL;
	} else {
		for (; tmp->next; tmp = tmp->next);
		tmp->next = my_calloc(1, sizeof(checkbox_t));
		if (!tmp->next)
			return NULL;
		tmp->next->next = NULL;
		tmp->next->prev = tmp;
	}
	return checkbox;
}

static void set_checkbox_sprite(const checkbox_declaration_t list,
	checkbox_t *tmp)
{
	sfSprite_setOrigin(tmp->selected,
	(sfVector2f) {list.selected.width / 2, list.selected.height / 2});
	sfSprite_setOrigin(tmp->unselected,
	(sfVector2f) {list.unselected.width / 2, list.unselected.height / 2});
	sfSprite_setPosition(tmp->selected, list.pos);
	sfSprite_setPosition(tmp->unselected, list.pos);
	sfSprite_setColor(tmp->selected, tmp->color);
	sfSprite_setColor(tmp->unselected, tmp->color);
}

static bool fill_checkbox_list(const checkbox_declaration_t list,
	checkbox_t *checkbox, textures_t *textures)
{
	checkbox_t *tmp = checkbox;
	textures_t *tex = textures;

	for (; tmp->next; tmp = tmp->next);
	for (; tex && !str_eq(tex->name, "ui"); tex = tex->next);
	tmp->game_state = list.game_state;
	tmp->selected = get_sprite_texture_rect(tex->texture, &list.selected);
	tmp->unselected = get_sprite_texture_rect(tex->texture,
							&list.unselected);
	if (!tmp->selected || !tmp->unselected)
		return false;
	tmp->color = hex_to_rgba(list.color);
	tmp->func = list.func;
	tmp->hover_color = hex_to_rgba(list.hover_color);
	tmp->checkbox_clock = sfClock_create();
	set_checkbox_sprite(list, tmp);
	return true;
}

checkbox_t *load_checkbox(textures_t *textures)
{
	checkbox_t *checkbox = NULL;

	for (size_t i = 0; checkbox_declaration[i].game_state != 0; i++) {
		checkbox = init_checkbox_list(checkbox);
		if (!checkbox)
			return NULL;
		if (!fill_checkbox_list(checkbox_declaration[i],
					checkbox, textures))
			return NULL;
	}
	return checkbox;
}

void free_checkbox(checkbox_t *checkbox)
{
	if (checkbox && checkbox->next)
		free_checkbox(checkbox->next);
	sfSprite_destroy(checkbox->selected);
	sfSprite_destroy(checkbox->unselected);
	sfClock_destroy(checkbox->checkbox_clock);
	free(checkbox);
}
