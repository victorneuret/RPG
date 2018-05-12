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
#include "macros.h"

static void set_direction(sfSprite *sprite, sfVector2f *dir)
{
	float x = ABS(dir->x);
	float y = ABS(dir->y);
	sfIntRect rect = sfSprite_getTextureRect(sprite);

	if (x > y) {
		if (dir->x > 0)
			rect.top = 200;
		else if (dir->x < 0)
			rect.top = 300;
	} else if (x < y) {
		if (dir->y < 0)
			rect.top = 100;
		else if (dir->y > 0)
			rect.top = 0;
	}
	sfSprite_setTextureRect(sprite, rect);
}

static void move_ai(float dt, enemy_t *enemy, player_t *player)
{
	sfVector2f dir;

	if (is_player_immune(player->immu))
		return;
	dir = get_direction(player->pos, enemy->pos);
	enemy->pos = (sfVector2f) {enemy->pos.x + dir.x * enemy->speed * dt,
				enemy->pos.y + dir.y * enemy->speed * dt};
	sfSprite_setPosition(enemy->sprite, enemy->pos);
	set_direction(enemy->sprite, &dir);
}

static void check_impact(win_t *win, enemy_t *enemy, player_t *player)
{
	sfFloatRect enemy_rect;
	sfFloatRect player_rect;

	enemy_rect = sfSprite_getGlobalBounds(enemy->sprite);
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
