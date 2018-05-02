/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** title_page
*/

#include <stdbool.h>

#include "title_page.h"

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
	title_page->pause = init_title_sprite(tmp->texture, TITLE_PAUSE,
		false);
	title_page->menu_paper = init_title_sprite(tmp->texture, TITLE_MAIN,
		true);
	sfSprite_setScale(title_page->background, (sfVector2f){1.05, 1.05});
	return title_page;
}

void update_title_page(win_t *win)
{
	sfVector2f mouse = get_mouse_pos(win);
	sfVector2f vect = {900, 420};

	sfSprite_setPosition(win->game->ui->title_page->menu_paper,
	(sfVector2f) {mouse.x / 75 * -1 + 960, mouse.y / 75 * -1 + 540});
	sfSprite_setPosition(win->game->ui->title_page->background,
	(sfVector2f) {mouse.x / 150 * -1 + 960, mouse.y / 150 * -1 + 540});
	for (buttons_t *tmp = win->game->ui->buttons; tmp; tmp = tmp->next) {
		if (tmp->game_state == TITLE) {
			sfSprite_setPosition(tmp->sprite,
				(sfVector2f) {mouse.x / 75 * -1 + vect.x,
				mouse.y / 75 * -1 + vect.y});
			vect.y += 80;
		}
	}
}
