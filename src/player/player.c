/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** player
*/

#include "render.h"
#include "player.h"
#include "render_window.h"
#include "stats_menu.h"
#include "my_calloc.h"
#include "inventory.h"
#include "xml.h"
#include "dash.h"

void animate_sprite(sfSprite *sprite, uint16_t offset, uint8_t max_val)
{
	sfIntRect rect = sfSprite_getTextureRect(sprite);

	if (rect.left < (max_val - 1) * offset)
		rect.left += offset;
	else
		rect.left = 0;
	sfSprite_setTextureRect(sprite, rect);
}

void draw_player(win_t *win, player_t *player)
{
	draw_dash(win, player);
	player_touched(player);
	render_object(win->sf_win, SPRITE, player->aim);
	render_object(win->sf_win, SPRITE, player->sprite);
	if (player->touched)
		render_object(win->sf_win, RECTANGLE, player->shade);
}

static bool init_player_aim(player_t *player, win_t *win)
{
	player->aim_angle = 45;
	player->aim = create_sprite(
		get_texture(win->game->textures, "aim")->texture);
	sfSprite_setOrigin(player->aim, (sfVector2f) {25, 25});
	sfSprite_setRotation(player->aim, 45.f);
	sfSprite_setPosition(player->aim, (sfVector2f) {200, 200});
	sfSprite_setScale(player->aim, (sfVector2f) {3, 3});
	player->touched = false;
	player->shade = sfRectangleShape_create();
	if (!player->shade)
		return false;
	sfRectangleShape_setFillColor(player->shade, hex_to_rgba(0xff000096));
	sfRectangleShape_setSize(player->shade, (sfVector2f){1920, 1080});
	return true;
}

player_t *init_player(win_t *win)
{
	player_t *player = my_calloc(1, sizeof(player_t));
	textures_t *text = win->game->textures;
	sfIntRect rect = (sfIntRect) {0, 0, 128, 132};

	if (!player)
		return NULL;
	for (; text && !str_eq(text->name, "player"); text = text->next);
	player->sprite = get_sprite_texture_rect(text->texture, &rect);
	player->timer = sfClock_create();
	player->immu = sfClock_create();
	if (!init_player_aim(player, win) || !player->sprite || !player->aim ||
			!player->timer || !player->immu || !player->shade)
		return NULL;
	sfSprite_setOrigin(player->sprite, (sfVector2f) {rect.width / 2.f,
							rect.height / 2.f});
	sfSprite_setPosition(player->sprite, (sfVector2f) {400, 400});
	player->level = 1;
	player->inventory = init_inventory(win);
	if (!xml_player(player) || !init_hud(player) || !player->inventory)
		return NULL;
	return player;
}

void destroy_player(player_t *player)
{
	sfSprite_destroy(player->sprite);
	sfClock_destroy(player->timer);
	free_inventory(player->inventory);
	free(player);
}
