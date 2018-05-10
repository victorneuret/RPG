/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** init_skill_tree
*/

#include "stats_menu.h"
#include "sprite_utils.h"
#include "texture.h"

bool init_skill_tree(stats_menu_t *menu, game_t *game)
{
	skill_tree_t *skill_tree = malloc(sizeof(skill_tree_t));
	sfTexture *texture = get_texture(game->textures, "player_icon")->texture;
	sfFont *ft = sfFont_createFromFile("res/fonts/space_mono_regular.ttf");

	if (!skill_tree || !ft || !texture)
		return false;
	skill_tree->sp = get_sprite_texture_rect(texture,
				&(sfIntRect){512, 0, 128, 128});
	if (!skill_tree->sp)
		return false;
	skill_tree->nb_sp = init_text(ft, "0", (sfVector2f) {700, 0}, 70);
	sfText_setStyle(skill_tree->nb_sp, sfTextBold);
	skill_tree->active = init_text(ft, "Passive", (sfVector2f) {800, 0}, 70);
	skill_tree->active = init_text(ft, "Active", (sfVector2f) {1200, 0}, 70);
	menu->skill_tree = skill_tree;
	sfFont_destroy(ft);
	return true;
}
