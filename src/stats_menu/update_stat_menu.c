/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** update_stat_menu
*/

#include <SFML/Graphics.h>

#include <stdbool.h>

#include "stats_menu.h"
#include "player.h"

static bool init_sprite(stats_t *stats, player_t *player)
{
	stats->player = sfSprite_copy(player->sprite);

	if (!stats->player)
		return false;
	sfSprite_setPosition(stats->player, (sfVector2f){150, 150});
	return true;
}

static bool set_text_pos(stats_t *stats)
{
	sfFloatRect rect;

	sfText_setPosition(stats->hp, (sfVector2f) {260, 300});
	rect = sfText_getGlobalBounds(stats->hp);
	sfText_setPosition(stats->hp_max, (sfVector2f)
					{rect.left + rect.width + 50, 300});
	sfText_setPosition(stats->xp, (sfVector2f) {260, 500});
	rect = sfText_getGlobalBounds(stats->xp);
	sfText_setPosition(stats->xp_max, (sfVector2f)
					{rect.left + rect.width + 50, 500});
	sfText_setPosition(stats->level_text, (sfVector2f) {250, 100});
	rect = sfText_getGlobalBounds(stats->level_text);
	sfText_setPosition(stats->level, (sfVector2f)
					{rect.left + rect.width, 100});
	return true;
}

bool update_stat_menu(stats_menu_t *menu, player_t *player)
{
	static bool first = true;

	if (first)
		if (!init_sprite(menu->stats, player))
			return false;
	sfText_setString(menu->stats->hp, int_to_str(player->hp->value));
	sfText_setString(menu->stats->hp_max,
			int_to_str(player->hp->max_value));
	sfText_setString(menu->stats->xp, int_to_str(player->xp->value));
	sfText_setString(menu->stats->xp_max,
			int_to_str(player->xp->max_value));
	sfText_setString(menu->stats->level, int_to_str(player->level));
	// sfText_setString(menu->stats->sp, int_to_str(player->xp->value));
	set_text_pos(menu->stats);
	first = false;
	return true;
}
