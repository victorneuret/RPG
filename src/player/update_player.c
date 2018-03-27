/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** update_player
*/

#include "player.h"

static void animate_sprite(player_t *player, uint16_t offset, uint8_t max_val)
{
	sfIntRect rect = sfSprite_getTextureRect(player->sprite);

	if (rect.left < max_val)
		rect.left += offset;
	else if (rect.left == max_val && rect.top == 0)
		rect.left = 0;
	else
		rect.left = 0;
	sfSprite_setTextureRect(player->sprite, rect);
}

static void update_player_direction_anim(player_t *player, win_t *win)
{
	static uint8_t anim_sprite_time = 0;

	sfIntRect rect = (sfIntRect) {0,
		sfSprite_getLocalBounds(player->sprite).height + 1,
		sfSprite_getLocalBounds(player->sprite).width,
		sfSprite_getLocalBounds(player->sprite).height};

	if (win->joystick->lx < 0
		&& sfSprite_getTextureRect(player->sprite).top == 0)
		sfSprite_setTextureRect(player->sprite, rect);
	rect.top = 0;
	if (win->joystick->lx > 0
		&& sfSprite_getTextureRect(player->sprite).top != 0)
		sfSprite_setTextureRect(player->sprite, rect);
	anim_sprite_time++;
	if (anim_sprite_time > 4) {
		animate_sprite(player,
			sfSprite_getGlobalBounds(player->sprite).width, 3);
		anim_sprite_time = 0;
	}
}

static void wall_on_player(player_t *player, sfVector2f *pos)
{
	if (pos->x < 0)
		pos->x = 0;
	if (pos->x + sfSprite_getGlobalBounds(player->sprite).width >
								WIN_MAX_W)
		pos->x = WIN_MAX_W -
			sfSprite_getGlobalBounds(player->sprite).width;
}

static void gravity_on_player(player_t *player, sfVector2f *pos)
{
	static double acceleration = 1.f;
	sfVector2f bottom_pos = (sfVector2f) {0,
		pos->y + sfSprite_getGlobalBounds(player->sprite).height};

	pos->y -= player->y_speed;
	if (bottom_pos.y >= WIN_MAX_H && player->y_speed <= 0) {
		pos->y = WIN_MAX_H -
			sfSprite_getGlobalBounds(player->sprite).height;
	} else if (bottom_pos.y < WIN_MAX_H) {
		pos->y += 9.81 * 2 * acceleration;
		acceleration += 0.05;
	}
	if (player->y_speed > 0)
		player->y_speed -= 9.81 / 2;
	if (player->y_speed < 0) {
		player->y_speed = 0;
		acceleration = 1;
	}
}

void update_player(win_t *win, player_t *player)
{
	sfVector2f pos = sfSprite_getPosition(player->sprite);

	// if (sfClock_getElapsedTime(player->clock).microseconds < 30000)
	// 	return;
	sfClock_restart(player->clock);
	pos.x += X_SPEED * (win->joystick->lx / 100.f) * win->dt;
	gravity_on_player(player, &pos);
	wall_on_player(player, &pos);
	if (win->joystick->lx != 0)
		update_player_direction_anim(player, win);
	sfSprite_setPosition(player->sprite, pos);
}
