/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** update_player
*/

#include <math.h>

#include "player.h"
#include "macros.h"
#include "angle_utils.h"

static void switch_direction(sfSprite *player, uint8_t dir)
{
	static uint8_t prev_dir = 0;
	sfIntRect rect = sfSprite_getTextureRect(player);

	switch (dir) {
	case LEFT:
		rect.top = 132;
		break;
	case RIGHT:
		rect.top = 0;
		break;
	case TOP:
		rect.top = 264;
		break;
	case BOTTOM:
		rect.top = 396;
		break;
	}
	if (dir != prev_dir)
		rect.left = 0;
	prev_dir = dir;
	sfSprite_setTextureRect(player, rect);
}

static uint8_t get_direction(float lx, float ly)
{
	uint8_t x = ABS(lx);
	uint8_t y = ABS(ly);

	if (x > y)
		return (lx < 0) ? LEFT : RIGHT;
	else if (x < y)
		return (ly < 0) ? BOTTOM : TOP;
	return 0;
}

static void update_aim_orientation(win_t *win, player_t *player)
{
	const float rx = win->joystick->rx / 100.f;
	const float ry = win->joystick->ry / 100.f;
	const float rad = acos(rx);
	const float deg = rad * 180.f / (float) M_PI;
	const int8_t neg = ry < 0 ? -1 : 1;
	const float new_angle = (deg * neg) + 45;

	if (rx != 0 || ry != 0) {
		sfSprite_setRotation(player->aim, new_angle);
		player->aim_angle = new_angle;
	}
}

static void move_player(win_t *win, player_t *player)
{
	const float nerf = player->shooting ? 0.25f : 1.f;
	sfVector2f pos = sfSprite_getPosition(player->sprite);
	sfFloatRect rect = sfSprite_getGlobalBounds(player->sprite);

	pos.x += X_SPEED * (win->joystick->lx / 100.f) * nerf * win->dt;
	pos.y += X_SPEED * (win->joystick->ly / 100.f) * nerf * win->dt;
	player_door(win, &pos, win->game->rooms[win->game->dungeon->act_room]);
	if (pos.x - PLAYER_W / 2.f + rect.width > WIN_MAX_W - WALL_SIZE)
		pos.x = WIN_MAX_W - rect.width - WALL_SIZE + PLAYER_H / 2.f;
	if (pos.x - PLAYER_W / 2.f < WALL_SIZE)
		pos.x = WALL_SIZE + PLAYER_H / 2.f;
	if (pos.y - PLAYER_H / 2.f + rect.height > WIN_MAX_H - WALL_SIZE - 16)
		pos.y = WIN_MAX_H - rect.height - WALL_SIZE - 16
						+ PLAYER_H / 2.f;
	if (pos.y - PLAYER_H / 2.f < WALL_SIZE)
		pos.y = WALL_SIZE + PLAYER_H / 2.f;
	check_obstacle(&pos, win);
	player->pos = pos;
	sfSprite_setPosition(player->sprite, pos);
	sfSprite_setPosition(player->aim, pos);
}

void update_player(win_t *win, player_t *player)
{
	static uint8_t dir = TOP;
	const float shooting = player->shooting ? 1.25f : 1.f;

	if (!player->alive)
		return;
	if ((win->joystick->lx != 0 || win->joystick->ly != 0) &&
		sfClock_getElapsedTime(player->timer).microseconds > 60000
					* shooting) {
		dir = get_direction(win->joystick->lx, win->joystick->ly);
		switch_direction(player->sprite, dir);
		animate_sprite(player->sprite,
			sfSprite_getGlobalBounds(player->sprite).width, 10);
		sfClock_restart(player->timer);
	} else if (sfClock_getElapsedTime(player->timer).microseconds
							> 300000) {
		update_idle(player, dir);
		sfClock_restart(player->timer);
	}
	get_item(win, win->game->player->inventory, player->sprite, false);
	move_player(win, player);
	update_aim_orientation(win, player);
}
