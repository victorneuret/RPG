/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** texture
*/

#pragma once

#include "render_window.h"

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
		"title_page",
		"res/textures/title.png"
	},
	{
		"player",
		"res/textures/new_player.png"
	},
	{
		"aim",
		"res/textures/aim.png"
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
