/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** init_button
*/

#include "buttons.h"

static buttons_t *init_buttons_list(buttons_t *buttons)
{
	buttons_t *tmp = buttons;

	if (!tmp) {
		buttons = malloc(sizeof(buttons_t));
		if (!buttons)
			return NULL;
		buttons->next = NULL;
	} else {
		for (; tmp->next; tmp = tmp->next);
		tmp->next = malloc(sizeof(buttons_t));
		if (!tmp->next)
			return NULL;
		tmp->next->next = NULL;
	}
	return buttons;
}

static bool fill_buttons_list(const button_declaration_t list,
	buttons_t *button, textures_t *textures)
{
	buttons_t *tmp = button;
	textures_t *tex = textures;

	for (; tmp->next; tmp = tmp->next);
	for (; tex && !str_eq(tex->name, "ui"); tex = tex->next);
	tmp->game_state = list.game_state;
	tmp->sprite = get_sprite_texture_rect(tex->texture, &list.rect);
	if (!tmp->sprite)
		return false;
	sfSprite_setOrigin(tmp->sprite,
		(sfVector2f) {list.rect.width / 2, list.rect.height / 2});
	sfSprite_setPosition(tmp->sprite, list.pos);
	tmp->color = hex_to_rgba(list.color);
	tmp->hover_color = hex_to_rgba(list.hover_color);
	sfSprite_setColor(tmp->sprite, tmp->color);
	tmp->text_hover = list.text_hover;
	tmp->func = list.func;
	tmp->button_clock = sfClock_create();
	tmp->reset_scale = false;
	tmp->hover = false;
	return true;
}

buttons_t *load_buttons(textures_t *textures)
{
	buttons_t *buttons = NULL;

	for (size_t i = 0; buttons_declaration[i].text_hover; i++) {
		buttons = init_buttons_list(buttons);
		if (!buttons)
			return NULL;
		if (!fill_buttons_list(buttons_declaration[i],
					buttons, textures))
			return NULL;
	}
	return buttons;
}

void free_buttons(buttons_t *buttons)
{
	if (buttons && buttons->next)
		free_buttons(buttons->next);
	sfSprite_destroy(buttons->sprite);
	sfClock_destroy(buttons->button_clock);
	free(buttons);
}

void free_hover_text_button(text_hover_button_t *hover)
{
	sfRectangleShape_destroy(hover->rect);
	sfFont_destroy(hover->font);
	sfText_destroy(hover->text);
	free(hover);
}
