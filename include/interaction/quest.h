/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** quest
*/

#pragma once

#include <SFML/Graphics.h>

#include <stdbool.h>
#include <stdint.h>

typedef enum {
	NONE,
	KILL_QUEST,
	GUN_QUEST,
	SHOTGUN_QUEST,
	UZI_QUEST,
	AK_QUEST,
	FLAMETHROWER_QUEST
} quest_type_t;

typedef struct quest {
	quest_type_t quest_type;
	int8_t kill;
	uint8_t quest_id;
	uint8_t diag_elem;
	char **dialog;
	sfText *text;
	bool state;
	bool last_quest;
	bool quest_popup;
} quest_t;

typedef struct {
	quest_type_t quest_type;
	int8_t kill;
	uint8_t quest_id;
	uint8_t diag_elem;
	char **dialog;
	bool state;
} quest_declaration_t;

#include "dialog_array.h"

static const quest_declaration_t quest_declaration[] = {
	{
		NONE,
		0,
		0,
		3,
		dialog_array[0],
		true
	},
	{
		KILL_QUEST,
		10,
		1,
		3,
		dialog_array[1],
		false
	},
	{
		NONE,
		0,
		2,
		2,
		dialog_array[2],
		true
	},
	{
		GUN_QUEST,
		10,
		3,
		3,
		dialog_array[3],
		false
	},
	{
		NONE,
		0,
		4,
		2,
		dialog_array[4],
		false
	},
	{
		NONE,
		0,
		3,
		0,
		NULL,
		false
	}
};

quest_t *init_quest(void);
