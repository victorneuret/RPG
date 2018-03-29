/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** button_text_hover
*/

#include "render.h"
#include "buttons.h"

text_hover_button_t *init_text_button(void)
{
	text_hover_button_t *hover = malloc(sizeof(text_hover_button_t));

	if (!hover)
		return NULL;
	hover->rect = init_rectangle((sfVector2f) {0, 0},
					(sfVector2f) {150, 30},
					hex_to_rgba(0x2121216C));
	hover->font =
		sfFont_createFromFile("res/fonts/space_mono_regular.ttf");
	if (!hover->rect || !hover->font)
		return NULL;
	hover->text = init_text(hover->font, "BANANA Oh na nag6!",
				(sfVector2f) {5, 5}, 20);
	if (!hover->text)
		return NULL;
	sfText_setColor(hover->text, hex_to_rgba(0xFFFFFFCC));
	sfText_setOrigin(hover->text, (sfVector2f) {0, 10});
	return hover;
}

static bool is_over_button(buttons_t *buttons, win_t *win)
{
	for (buttons_t *tmp = buttons; tmp; tmp = tmp->next)
		if (tmp->hover && tmp->game_state == win->game_state)
			return true;
	return false;
}

static void update_text_hover_box_position(text_hover_button_t *hover,
	sfFloatRect rect, win_t *win)
{
	sfVector2f mouse = get_mouse_pos(win);

	if (mouse.x - 10 - rect.width <= 0
		&& mouse.y - 10 - rect.height > 0)
		sfRectangleShape_setPosition(hover->rect,
			(sfVector2f) {mouse.x - 5, mouse.y - 5 - rect.height});
	else if (mouse.y - 10 - rect.height <= 0
		&& mouse.x - 10 - rect.width > 0)
		sfRectangleShape_setPosition(hover->rect,
			(sfVector2f) {mouse.x - 5 - rect.width, mouse.y + 5});
	if (mouse.y - 10 - rect.height <= 0
		&& mouse.x - 10 - rect.width <= 0)
		sfRectangleShape_setPosition(hover->rect, (sfVector2f)
		{mouse.x + 5, mouse.y + 5});

}

void update_text_hover(text_hover_button_t *hover, win_t *win)
{
	sfFloatRect rect = sfRectangleShape_getGlobalBounds(hover->rect);
	sfVector2f size = sfRectangleShape_getSize(hover->rect);
	size_t text_size = my_strlen(sfText_getString(hover->text))
			* (sfText_getCharacterSize(hover->text) / 3 * 2);
	sfVector2f mouse = get_mouse_pos(win);

	sfRectangleShape_setPosition(hover->rect,
				(sfVector2f) {mouse.x - 5 - rect.width,
						mouse.y - 5 - rect.height});
	if (!is_over_button(win->game->ui->buttons, win)
		|| my_strlen(sfText_getString(hover->text)) == 0)
		return;
	if (size.x != text_size + 10) {
		size.x = text_size + 10;
		sfRectangleShape_setSize(hover->rect,
				(sfVector2f) {size.x, size.y});
	}
	update_text_hover_box_position(hover, rect, win);
	size = sfRectangleShape_getPosition(hover->rect);
	sfText_setPosition(hover->text,
			(sfVector2f) {size.x + 5, size.y + 10});
}

void draw_text_hover_button(text_hover_button_t *hover, win_t *win)
{
	if (my_strlen(sfText_getString(hover->text)) == 0)
		return;
	if (is_over_button(win->game->ui->buttons, win)) {
		update_text_hover(hover, win);
		render_object(win->sf_win, RECTANGLE, hover->rect);
		render_object(win->sf_win, TEXT, hover->text);
	}
}
