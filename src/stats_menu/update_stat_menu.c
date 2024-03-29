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
	sfText_setPosition(stats->sp, (sfVector2f) {260, 690});
	return true;
}

bool update_stat_menu(stats_menu_t *menu, player_t *player)
{
	sfText_setString(menu->stats->hp, int_to_str(player->hp->value));
	sfText_setString(menu->stats->hp_max,
			int_to_str(player->hp->max_value));
	sfText_setString(menu->stats->xp, int_to_str(player->xp->value));
	sfText_setString(menu->stats->xp_max,
			int_to_str(player->xp->max_value));
	sfText_setString(menu->stats->level, int_to_str(player->level));
	sfText_setString(menu->stats->sp, int_to_str(player->skill_point));
	set_text_pos(menu->stats);
	return true;
}
