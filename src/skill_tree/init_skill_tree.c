/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** init_skill_tree
*/

#include "stats_menu.h"
#include "sprite_utils.h"
#include "texture.h"

static sfSprite *init_skill_sprite(uint16_t x_rect, uint8_t nb,
		textures_t *textures, size_t i)
{
	sfTexture *texture = get_texture(textures, "player_icon")->texture;
	sfIntRect rect = {x_rect, 1, 128, 128};
	sfSprite *sprite;

	switch (nb) {
	case 0: rect.top += 512; break;
	case 1: rect.top += 384; break;
	case 2: rect.top += 256; break;
	default: rect.top = 0;
	}
	if (i == 3 || i == 2) {
		rect.left += 1;
		rect.width -= 1;
	}else if (i == 1)
		rect.width -= 1;
	sprite = get_sprite_texture_rect(texture, &rect);
	if (!sprite)
		return NULL;
	return sprite;
}

static void set_pos_sprite(uint16_t x_pos, uint16_t nb,
		sfSprite *sprite, size_t i)
{
	sfVector2f pos = {x_pos, 0};

	switch (nb) {
	case 2: pos.y = 300; break;
	case 1: pos.y = 500; break;
	case 0: pos.y = 700; break;
	default: pos.y = 0;
	}
	if (i > 1)
		pos.x += 50;
	sfSprite_setPosition(sprite, pos);
}

static bool alloc_skill_tree(skill_tree_t *tree)
{
	static bool first = true;

	if (!first)
		return true;
	tree->skill = malloc(sizeof(skill_t *) * 4);
	if (!tree->skill)
		return false;
	for (size_t i = 0; i < 4; i++) {
		tree->skill[i] = malloc(sizeof(skill_t));
		if (!tree->skill[i])
			return false;
	}
	first = false;
	return true;
}

bool init_skill(skill_tree_t *tree, textures_t *textures)
{
	uint16_t x_rect = 0;
	uint16_t x_pos = 1000;
	uint16_t unlock = 2;

	if (!alloc_skill_tree(tree))
		return false;
	for (size_t i = 0; i < 4; i++) {
		tree->skill[i]->level = 0;
		for (size_t j = 0; j < 3; j++) {
			tree->skill[i]->unlock_level[j] = unlock;
			unlock = unlock * 2 + 1;
			tree->skill[i]->sprite[j] = init_skill_sprite(x_rect,
							j, textures, i);
			set_pos_sprite(x_pos, j, tree->skill[i]->sprite[j], i);
		}
		x_rect += 128;
		x_pos += 200;
		unlock = 2;
	}
	return true;
}

bool init_skill_tree(stats_menu_t *menu, game_t *game)
{
	skill_tree_t *skill_tree = malloc(sizeof(skill_tree_t));
	sfTexture *tex = get_texture(game->textures, "player_icon")->texture;
	sfFont *ft = sfFont_createFromFile("res/fonts/isaac_sans.ttf");

	if (!skill_tree || !ft || !tex)
		return false;
	skill_tree->sp = get_sprite_texture_rect(tex,
				&(sfIntRect){0, 0, 256, 256});
	if (!skill_tree->sp)
		return false;
	skill_tree->nb_sp = init_text(ft, "0", (sfVector2f) {800, 0}, 70);
	sfText_setStyle(skill_tree->nb_sp, sfTextBold);
	skill_tree->active = init_text(ft, "Passive",
				(sfVector2f) {1055, 180}, 70);
	skill_tree->passive = init_text(ft, "Active",
				(sfVector2f) {1535, 180}, 70);
	if (!init_skill(skill_tree, game->textures))
		return false;
	menu->skill_tree = skill_tree;
	return true;
}
