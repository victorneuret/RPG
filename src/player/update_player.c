/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** update_player
*/

#include "player.h"
#include "macros.h"

void animate_sprite(player_t *player, uint16_t offset, uint8_t max_val)
{
	sfIntRect rect = sfSprite_getTextureRect(player->sprite);

	if (rect.left < (max_val - 1) * offset)
		rect.left += offset;
	else
		rect.left = 0;
	sfSprite_setTextureRect(player->sprite, rect);
}

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

static void move_player(win_t *win, sfSprite *player)
{
	sfVector2f pos = sfSprite_getPosition(player);
	sfFloatRect rect = sfSprite_getGlobalBounds(player);

	pos.x += X_SPEED * (win->joystick->lx / 100.f) * win->dt;
	pos.y += X_SPEED * (win->joystick->ly / 100.f) * win->dt;
	if (pos.x + rect.width > WIN_MAX_W)
		pos.x = WIN_MAX_W - rect.width;
	if (pos.x < 0)
		pos.x = 0;
	if (pos.y + rect.height > WIN_MAX_H)
		pos.y = WIN_MAX_H - rect.height;
	if (pos.y < 0)
		pos.y = 0;
	sfSprite_setPosition(player, pos);
}

void update_player(win_t *win, player_t *player)
{
	static uint8_t dir = TOP;

	if ((win->joystick->lx != 0 || win->joystick->ly != 0) &&
		sfClock_getElapsedTime(player->clock).microseconds > 60000) {
		dir = get_direction(win->joystick->lx, win->joystick->ly);
		switch_direction(player->sprite, dir);
		animate_sprite(player,
			sfSprite_getGlobalBounds(player->sprite).width, 10);
		sfClock_restart(player->clock);
	} else if (sfClock_getElapsedTime(player->clock).microseconds
							> 300000) {
		update_idle(player, dir);
		sfClock_restart(player->clock);
	}
	move_player(win, player->sprite);
}
