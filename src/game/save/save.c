/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** save
*/

#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include "inventory_list.h"
#include "render_window.h"
#include "stats_menu.h"
#include "inventory.h"
#include "quest.h"
#include "skills.h"

bool save_exist(save_t *save)
{
	save->fd = open("rpg.save", O_RDWR);

	if (save->fd == -1)
		return false;
	return true;
}

static int32_t reverse_bits(int32_t nb)
{
	return (((nb >> 24) & 0xff) | ((nb << 24) & 0xff000000) |
		((nb >> 8) & 0xff00) | ((nb << 8) & 0xff0000));
}

static uint8_t *read_bits(uint32_t hex)
{
	uint8_t *array = malloc(sizeof(uint8_t) * 4);

	hex = reverse_bits(hex);
	for (uint8_t i = 0; i < 4; i++) {
		array[i] = hex & 255;
		hex >>= 8;
	}
	return array;
}

static void insert_skill(win_t *win, uint8_t *array)
{
	hp_save(win, array[0]);
	weapon_save(win, array[1]);
	dash_save(win, array[2]);
	heal_save(win, array[3]);
}

static void fill_struct(win_t *win, save_elements_t *save_elements)
{
	item_t **item = win->game->player->inventory->item;
	skill_t **skill = win->game->stats_menu->skill_tree->skill;

	save_elements->level = win->game->player->level;
	save_elements->skill_point = win->game->player-> skill_point;
	save_elements->hp = win->game->player->hp->value;
	save_elements->xp = win->game->player->xp->value;
	save_elements->quest_id = win->game->npc->quest_id;
	save_elements->quest_kill =
			win->game->npc->quest[save_elements->quest_id].kill;
	save_elements->quest_popup =
		win->game->npc->quest[save_elements->quest_id].quest_popup;
	save_elements->inventory = 0;
	save_elements->skills = 0;
	for (uint8_t i = 0; i < INVENTORY_NB; i++) {
		if (item[i]) {
			save_elements->inventory += item[i]->type;
			save_elements->inventory <<= 8;
		}
	}
	for (uint8_t i = 0; i < 4; i++)
		save_elements->skills = (save_elements->skills << 8) +
								skill[i]->level;
}

static void insert_struct(win_t *win, save_elements_t *save_elements)
{
	uint8_t *items = read_bits(save_elements->inventory);
	uint8_t *skill_list = read_bits(save_elements->skills);
	inventory_t *inventory = win->game->player->inventory;
	skill_t **skill = win->game->stats_menu->skill_tree->skill;

	win->game->player->level = save_elements->level;
	win->game->player-> skill_point = save_elements->skill_point;
	win->game->player->hp->value = save_elements->hp;
	for (int64_t i = 0; i < win->game->player->level; i++)
		win->game->player->xp->max_value += win->game->player->xp->mult;
	win->game->player->xp->value = save_elements->xp;
	win->game->npc->quest_id = save_elements->quest_id;
	win->game->npc->quest[save_elements->quest_id].kill =
						save_elements->quest_kill;
	win->game->npc->quest[save_elements->quest_id].quest_popup =
						save_elements->quest_popup;
	for (uint8_t i = 0; i < INVENTORY_NB; i++) {
		if (items[i] != 0 || (items[i] == 0 && i == 0)) {
			inventory->item[i] = &inventory->item_list[items[i]];
			inventory->item[i]->droped = false;
		} else
			inventory->item[i] = NULL;
	}
	for (uint8_t i = 0; i < 4; i++)
		skill[i]->level = skill_list[i];
	insert_skill(win, skill_list);
	free(skill_list);
	free(items);
}

bool open_save(win_t *win, save_t *save)
{
	char *buffer;

	if (save->fd == -1)
		return false;
	if (read(save->fd, &save->save_elements, sizeof(save_elements_t)) !=
		SAVE_SIZE || read(save->fd, &buffer, 1) > 0)
		return false;
	insert_struct(win, &save->save_elements);
	close(save->fd);
	return true;
}

bool create_save(win_t *win, save_t *save)
{
	save->fd = open("rpg.save", O_RDWR | O_TRUNC | O_CREAT, 0644);

	if (save->fd == -1)
		return false;
	fill_struct(win, &save->save_elements);
	write(save->fd, &save->save_elements, sizeof(save_elements_t));
	close(save->fd);
	return true;
}
