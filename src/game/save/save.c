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
#include "save.h"
#include "popup.h"

bool save_exist(save_t *save)
{
	save->fd = open(SAVE_FILE, O_RDWR);

	if (save->fd == -1)
		return false;
	close(save->fd);
	return true;
}

static void fill_struct(win_t *win, save_elements_t *save_elements)
{
	item_t **item = win->game->player->inventory->item;
	quest_t *quest = win->game->npc->quest;

	save_elements->level = win->game->player->level;
	save_elements->skill_point = win->game->player->skill_point;
	save_elements->hp = win->game->player->hp->value;
	save_elements->xp = win->game->player->xp->value;
	save_elements->quest_id = win->game->npc->quest_id;
	save_elements->quest_kill = quest[save_elements->quest_id].kill;
	save_elements->quest_popup = quest[save_elements->quest_id].quest_popup;
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
			win->game->stats_menu->skill_tree->skill[i]->level;
}

void create_save(win_t *win, save_t *save)
{
	save->fd = open(SAVE_FILE, O_RDWR | O_TRUNC | O_CREAT, 0644);

	if (save->fd == -1) {
		create_popup(win->game->ui, CANT_WRITE, ERROR);
		return;
	}
	fill_struct(win, &save->save_elements);
	write(save->fd, &save->save_elements, sizeof(save_elements_t));
	close(save->fd);
}
