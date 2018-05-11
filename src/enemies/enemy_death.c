/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** enemies_death
*/

#include <SFML/Graphics.h>
#include <stdint.h>
#include <stdlib.h>

#include "game.h"
#include "quest.h"
#include "popup.h"
#include "enemies.h"
#include "particle_xp.h"
#include "render_window.h"

static bool is_dungeon_cleared(game_t const *game)
{
	for (int8_t room = 0; room < game->dungeon->nb_rooms; room++)
		if (!game->rooms[room]->cleared)
			return false;
	return true;
}

void enemy_killed(win_t *win, enemy_list_t *enemy_list, enemy_list_t *node)
{
	const game_t *game = win->game;

	particle_xp(win, node->enemy->hp_max, node->enemy->pos);
	enemy_drop_item(node->enemy->pos, win);
	game->npc->quest[game->npc->quest_id].kill--;
	rm_enemy_from_list(&enemy_list, node->enemy);
	if (!enemy_list->enemy) {
		game->rooms[game->dungeon->act_room]->cleared = true;
		if (is_dungeon_cleared(game)) {
			game->dungeon->cleared = true;
			particle_xp(win, 1000, (sfVector2f) {100, 100});
			create_popup(win->game->ui,
				"Dungeon cleared!", SUCCESS);
		}
	}
}
