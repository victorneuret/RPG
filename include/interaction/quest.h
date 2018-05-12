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
	LIGHT_ENEMY_QUEST,
	BALANCED_ENEMY_QUEST,
	HEAVY_ENEMY_QUEST,
	NONE_ENEMY_QUEST
} enemy_quest_t;

typedef enum {
	GUN_WEAPON_QUEST,
	SHOTGUN_WEAPON_QUEST,
	FLAMETHROWER_WEAPON_QUEST,
	UZI_WEAPON_QUEST,
	AK_WEAPON_QUEST,
	KILL_WEAPON_QUEST,
	NONE_WEAPON_QUEST
} weapon_quest_t;

typedef struct quest {
	weapon_quest_t weapon_quest;
	enemy_quest_t enemy_quest;
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
	weapon_quest_t weapon_quest;
	enemy_quest_t enemy_quest;
	int8_t kill;
	uint8_t quest_id;
	uint8_t diag_elem;
	char **dialog;
	bool state;
} quest_declaration_t;

#include "dialog_array.h"

static const quest_declaration_t quest_declaration[] = {
	{
		NONE_WEAPON_QUEST,
		NONE_ENEMY_QUEST,
		0,
		0,
		3,
		dialog_array[0],
		false
	},
	{
		KILL_WEAPON_QUEST,
		NONE_ENEMY_QUEST,
		5,
		1,
		3,
		dialog_array[1],
		false
	},
	{
		NONE_WEAPON_QUEST,
		NONE_ENEMY_QUEST,
		0,
		2,
		2,
		dialog_array[2],
		true
	},
	{
		UZI_WEAPON_QUEST,
		NONE_ENEMY_QUEST,
		10,
		3,
		2,
		dialog_array[3],
		false
	},
	{
		NONE_WEAPON_QUEST,
		NONE_ENEMY_QUEST,
		0,
		4,
		1,
		dialog_array[4],
		false
	},
	{
		NONE_WEAPON_QUEST,
		NONE_ENEMY_QUEST,
		0,
		3,
		0,
		NULL,
		false
	}
};

quest_t *init_quest(void);
