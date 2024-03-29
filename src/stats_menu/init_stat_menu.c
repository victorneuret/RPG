/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** init_stat_menu
*/

#include <SFML/Graphics.h>

#include <stdbool.h>

#include "stats_menu.h"
#include "text_utils.h"
#include "sprite_utils.h"
#include "texture.h"
#include "hud.h"

static bool init_stats_sprite(stats_t *stats, textures_t *textures)
{
	sfTexture *texture = get_texture(textures, "player_icon")->texture;
	sfTexture *tx_player = get_texture(textures, "player")->texture;

	if (!texture || !tx_player)
		return false;
	stats->player = get_sprite_texture_rect(tx_player,
				&(sfIntRect){0, 530, 128, 130});
	stats->xp_sprite = get_sprite_texture_rect(texture,
				&(sfIntRect){256, 0, 128, 128});
	stats->hp_sprite = get_sprite_texture_rect(texture,
				&(sfIntRect){0, 640, 128, 128});
	stats->sp_sprite = get_sprite_texture_rect(texture,
				&(sfIntRect){0, 0, 255, 256});
	if (!stats->xp_sprite || !stats->hp_sprite || !stats->sp_sprite)
		return false;
	sfSprite_setColor(stats->xp_sprite, XP_COLOR);
	sfSprite_setColor(stats->hp_sprite, HP_COLOR);
	sfSprite_setPosition(stats->hp_sprite, (sfVector2f) {80, 300});
	sfSprite_setPosition(stats->xp_sprite, (sfVector2f) {80, 500});
	sfSprite_setPosition(stats->sp_sprite, (sfVector2f) {16, 636});
	return true;
}

static bool init_stats(stats_menu_t *menu, textures_t *textures)
{
	stats_t *stats = malloc(sizeof(stats_t));
	sfFont *ft = sfFont_createFromFile("res/fonts/isaac_sans.ttf");

	if (!stats || !ft)
		return false;
	stats->slash = init_text(ft, "/", (sfVector2f) {0, 0}, 100);
	stats->hp = init_text(ft, "0", (sfVector2f) {0, 0}, 100);
	stats->hp_max = init_text(ft, "0", (sfVector2f) {0, 0}, 100);
	stats->xp = init_text(ft, "0", (sfVector2f) {0, 0}, 100);
	stats->xp_max = init_text(ft, "0", (sfVector2f) {0, 0}, 100);
	stats->level_text = init_text(ft, "Level ", (sfVector2f) {0, 0}, 100);
	stats->level = init_text(ft, "0", (sfVector2f) {0, 0}, 100);
	stats->sp = init_text(ft, "0", (sfVector2f) {0, 0}, 100);
	if (!stats->slash || !stats->hp || !stats->hp_max || !stats->xp
		|| !stats->xp_max || !stats->level || !stats->level_text
		|| !stats->sp || !init_stats_sprite(stats, textures))
		return false;
	sfSprite_setPosition(stats->player, (sfVector2f){90, 90});
	menu->stats = stats;
	return true;
}

static bool init_rectangle_stats(stats_menu_t *menu)
{
	sfRectangleShape_setSize(menu->background,
				(sfVector2f){WIN_MAX_W, WIN_MAX_H});
	sfRectangleShape_setFillColor(menu->background, hex_to_rgb(0x455A64));
	sfRectangleShape_setSize(menu->separator, (sfVector2f){1, 880});
	sfRectangleShape_setPosition(menu->separator, (sfVector2f){700, 100});
	sfRectangleShape_setFillColor(menu->separator, hex_to_rgb(0xFFFFFF));
	return true;
}

bool init_stat_menu(win_t *win)
{
	win->game->stats_menu = malloc(sizeof(stats_menu_t));
	if (!win->game->stats_menu)
		return false;
	win->game->stats_menu->stats = malloc(sizeof(stats_t));
	if (!win->game->stats_menu->stats)
		return false;
	win->game->stats_menu->background = sfRectangleShape_create();
	win->game->stats_menu->separator = sfRectangleShape_create();
	if (!win->game->stats_menu->background
		|| !win->game->stats_menu->separator)
		return false;
	if (!init_stats(win->game->stats_menu, win->game->textures))
		return false;
	if (!init_rectangle_stats(win->game->stats_menu))
		return false;
	return true;
}
