/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** title_page
*/

#include <stdbool.h>

#include "title_page.h"
#include "options.h"

static sfSprite *init_title_sprite(sfTexture *texture, int menu_rect,
	bool move)
{
	sfSprite *sprite;
	sfFloatRect rect;

	sprite = create_sprite(texture);
	sfSprite_setTextureRect(sprite, title_rect[menu_rect]);
	if (move) {
		rect = sfSprite_getGlobalBounds(sprite);
		sfSprite_setOrigin(sprite,
			(sfVector2f) {rect.width / 2, rect.height / 2});
		sfSprite_setPosition(sprite, (sfVector2f) {960, 540});
	}
	return sprite;
}

title_page_t *init_title_page(textures_t *texture)
{
	title_page_t *title_page = malloc(sizeof(title_page_t));
	textures_t *tmp = texture;

	if (!title_page)
		return NULL;
	for (; tmp && !str_eq(tmp->name, "menu"); tmp = tmp->next);
	title_page->overlay = init_title_sprite(tmp->texture, TITLE_OVERLAY,
		false);
	title_page->background = init_title_sprite(tmp->texture, TITLE_BG,
		true);
	title_page->options = init_title_sprite(tmp->texture, TITLE_OPTIONS,
		false);
	title_page->menu_paper = init_title_sprite(tmp->texture, TITLE_MAIN,
		true);
	sfSprite_setScale(title_page->background, (sfVector2f){1.05, 1.05});
	sfSprite_setScale(title_page->options, (sfVector2f){0, 0});
	sfSprite_setColor(title_page->options,
					sfColor_fromRGBA(255, 255, 255, 0));
	return title_page;
}

float get_paralax_speed(game_status state)
{
	switch (state) {
		case TITLE: return TITLE_SPEED;
		case OPTION: return OPTION_SPEED;
		default: return DEFAULT_SPEED;
	}
}

void buttons_paralax(win_t *win)
{
	sfVector2f mouse = get_mouse_pos(win);
	sfVector2f vect = {900, 420};
	int speed = get_paralax_speed(win->game_state);

	for (buttons_t *tmp = win->game->ui->buttons; tmp; tmp = tmp->next) {
		if (tmp->game_state == win->game_state) {
			sfSprite_setPosition(tmp->sprite,
				(sfVector2f) {mouse.x / speed * -1 + vect.x,
				mouse.y / speed * -1 + vect.y});
			vect.y += 80;
		}
	}
	vect = (sfVector2f){1000, 420};
	for (checkbox_t *tmp = win->game->ui->checkbox; tmp; tmp = tmp->next) {
		if (tmp->game_state == win->game_state) {
			sfSprite_setPosition(get_checkbox_sprite(tmp),
				(sfVector2f) {mouse.x / speed * -1 + vect.x,
				mouse.y / speed * -1 + vect.y});
			vect.y += 80;
		}
	}
}

void update_title_page(win_t *win)
{
	sfVector2f mouse = get_mouse_pos(win);

	options_animation(win->game->ui->title_page->options, win);
	sfSprite_setPosition(win->game->ui->title_page->menu_paper,
	(sfVector2f) {mouse.x / 75 * -1 + 960, mouse.y / 75 * -1 + 540});
	sfSprite_setPosition(win->game->ui->title_page->background,
	(sfVector2f) {mouse.x / 150 * -1 + 960, mouse.y / 150 * -1 + 540});
	buttons_paralax(win);
}
