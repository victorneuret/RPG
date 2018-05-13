/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** player
*/

#pragma once

#include <SFML/Graphics.h>
#include <stdint.h>
#include <stdbool.h>

#include "inventory.h"
#include "player.h"
#include "hud.h"

typedef struct inventory inventory_t;
typedef struct bar bar_t;

static const float X_SPEED = 900.f;
static const uint8_t WALL_SIZE = 140;

static const uint8_t PLAYER_W = 128;
static const uint8_t PLAYER_H = 138;

typedef enum {
	LEFT,
	RIGHT,
	TOP,
	BOTTOM
} direction_t;

typedef struct player {
	sfVector2f pos;
	sfClock *timer;
	sfClock *immu;
	sfSprite *sprite;
	sfText *loose_text;
	sfRectangleShape *loose_shape;
	float speed;
	uint8_t level;
	uint16_t skill_point;
	bar_t *hp;
	bar_t *xp;
	uint16_t dmg;
	sfSprite *aim;
	bool touched;
	bool shooting;
	bool alive;
	sfRectangleShape *shade;
	float aim_angle;
	inventory_t *inventory;
} player_t;

#include "render_window.h"
#include "dungeon.h"

typedef struct room room_t;

player_t *init_player(win_t *win);
void update_player(win_t *win, player_t *player);
void update_idle(player_t *player, uint8_t dir);
void animate_sprite(sfSprite *sprite, uint16_t offset, uint8_t max_val);
void draw_player(win_t *win, player_t *player);
void destroy_player(player_t *player);
void check_obstacle(sfVector2f *pos, win_t *win);

void player_shoot(win_t *win, player_t *player);
void player_door(win_t *win, sfVector2f *pos, room_t *room);
void door_action(win_t *win, sfVector2f *pos, room_t *room);

bool is_player_immune(sfClock *timer);
void player_dash(win_t *win, player_t *player, bool press, bool pressed);
void player_touched(player_t *player);

sfText *init_game_over_text(void);
sfRectangleShape *init_game_over_shape(void);
void player_is_alive(win_t *win, bar_t *hp);
