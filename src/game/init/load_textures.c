/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** load_textures
*/

#include "texture.h"

static textures_t *init_textures_list(textures_t *textures)
{
	textures_t *tmp = textures;

	if (!tmp) {
		textures = malloc(sizeof(textures_t));
		if (!textures)
			return NULL;
		textures->next = NULL;
	} else {
		for (; tmp->next; tmp = tmp->next);
		tmp->next = malloc(sizeof(textures_t));
		if (!tmp->next)
			return NULL;
		tmp->next->next = NULL;
	}
	return textures;
}

static bool fill_textures_list(const textures_path_t textures_path,
	textures_t *texture)
{
	textures_t *tmp = texture;

	for (; tmp->next; tmp = tmp->next);
	tmp->name = textures_path.name;
	tmp->texture = sfTexture_createFromFile(textures_path.path, NULL);
	if (!tmp->texture)
		return false;
	sfTexture_setSmooth(tmp->texture, sfTrue);
	return true;
}

textures_t *load_textures(void)
{
	textures_t *textures = NULL;

	for (size_t i = 0; textures_path[i].name; i++) {
		textures = init_textures_list(textures);
		if (!textures)
			return NULL;
		if (!fill_textures_list(textures_path[i], textures))
			return NULL;
	}
	return textures;
}

void free_textures(textures_t *textures)
{
	if (textures && textures->next)
		free_textures(textures->next);
	sfTexture_destroy(textures->texture);
	free(textures);
}
