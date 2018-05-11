/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** texture
*/

#pragma once

#include "render_window.h"

static const int ITEM_SIZE = 112;

typedef struct textures_path {
	char *name;
	char *path;
} textures_path_t;

static const textures_path_t textures_path[] = {
	{
		"ui",
		"res/textures/ui.png"
	},
	{
		"player",
		"res/textures/new_player.png"
	},
	{
		"aim",
		"res/textures/aim.png"
	},
	{
		"menu",
		"res/textures/menu.png"
	},
	{
		"door",
		"res/textures/doors.png"
	},
	{
		"rock",
		"res/textures/rock.png"
	},
	{
		"gun",
		"res/textures/items/gun.png"
	},
	{
		"shotgun",
		"res/textures/items/shotgun.png"
	},
	{
		"flamethrower",
		"res/textures/items/flamethrower.png"
	},
	{
		"uzi",
		"res/textures/items/uzi.png"
	},
	{
		"ak47",
		"res/textures/items/ak47.png"
	},
	{
		"player_icon",
		"res/textures/skills.png"
	},
	{
		"npc",
		"res/textures/npc.png"
	},
	{
		"howtoplay",
		"res/textures/howtoplay.png"
	},
	{
		"portal",
		"res/textures/portal.png"
	},
	{NULL, NULL}
};

typedef struct textures {
	char *name;
	sfTexture *texture;
	struct textures *next;
} textures_t;

textures_t *load_textures(void);
void free_textures(textures_t *textures);
textures_t *get_texture(textures_t *textures, char const *name);
