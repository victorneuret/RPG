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

static const char *FONT_PATH __attribute__((unused)) =
	"res/fonts/space_mono_regular.ttf";

typedef struct textbox textbox_t;

typedef struct quest {
	uint8_t quest_id;
	sfText *discuss;
	bool state;
} quest_t;

typedef struct npc {
	sfVector2f pos;
	sfRectangleShape *skin;
	sfText *talk;
	quest_t *quest;
	textbox_t *textbox;
} npc_t;

npc_t *init_npc(void);
void draw_npc(win_t *win, npc_t *npc);
void npc_interaction(win_t *win);
