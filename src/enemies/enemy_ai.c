/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** enemy_ai
*/

#include <SFML/Graphics.h>

#include "player.h"
#include "enemies.h"
#include "coord_utils.h"
#include "render_window.h"
#include "particle_explosion.h"

static void move_ai(float dt, enemy_t *enemy, player_t *player)
{
	sfVector2f dir;

	if (is_player_immune(player->immu))
		return;
	dir = get_direction(player->pos, enemy->pos);
	enemy->pos = (sfVector2f) {enemy->pos.x + dir.x * enemy->speed * dt,
				enemy->pos.y + dir.y * enemy->speed * dt};
	sfRectangleShape_setPosition(enemy->shape, enemy->pos);
}

static void check_impact(win_t *win, enemy_t *enemy, player_t *player)
{
	sfFloatRect enemy_rect;
	sfFloatRect player_rect;

	enemy_rect = sfRectangleShape_getGlobalBounds(enemy->shape);
	player_rect = sfSprite_getGlobalBounds(player->sprite);
	if (sfFloatRect_intersects(&enemy_rect, &player_rect, NULL)) {
		if (is_player_immune(player->immu))
			return;
		player->touched = true;
		play_sfx(win->game->sounds, PLAYER_HIT);
		player->hp->value -= enemy->attack;
		sfClock_restart(player->immu);
		create_explosion(win, 150, player->pos, sfRed);
	}
}

void update_enemy_ai(win_t *win, enemy_t *enemy, player_t *player)
{
	if (!enemy)
		return;
	move_ai(win->dt, enemy, player);
	check_impact(win, enemy, player);
}
