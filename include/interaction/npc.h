/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** npc
*/

#pragma once

#include <SFML/Graphics.h>

#include <stdint.h>
#include <stdbool.h>

#include "render_window.h"

#include "textbox.h"
#include "quest.h"
#include "texture.h"

typedef struct textbox textbox_t;
typedef struct quest quest_t;

typedef struct npc {
	uint8_t quest_id;
	uint8_t elem;
	sfVector2f pos;
	sfSprite *help;
	sfSprite *skin;
	sfClock *timer;
	sfText *talk;
	quest_t *quest;
	textbox_t *textbox;
} npc_t;

npc_t *init_npc(textures_t *textures);
void draw_npc(win_t *win, npc_t *npc);
void npc_interaction(win_t *win);
