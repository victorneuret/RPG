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
	uint8_t quest_id;
	weapon_quest_t weapon_quest;
	enemy_quest_t enemy_quest;
	int8_t kill;
	char **dialog;
	uint8_t diag_elem;
	bool state;
} quest_declaration_t;

#include "dialog_array.h"

static const quest_declaration_t quest_declaration[] = {
	{
		0,
		NONE_WEAPON_QUEST,
		NONE_ENEMY_QUEST,
		0,
		dialog_array[0],
		3,
		false
	},
	{
		1,
		KILL_WEAPON_QUEST,
		NONE_ENEMY_QUEST,
		5,
		dialog_array[1],
		3,
		false
	},
	{
		2,
		NONE_WEAPON_QUEST,
		NONE_ENEMY_QUEST,
		0,
		dialog_array[2],
		2,
		true
	},
	{
		3,
		UZI_WEAPON_QUEST,
		NONE_ENEMY_QUEST,
		10,
		dialog_array[3],
		2,
		false
	},
	{
		4,
		KILL_WEAPON_QUEST,
		HEAVY_ENEMY_QUEST,
		5,
		dialog_array[4],
		2,
		false

	},
	{
		5,
		KILL_WEAPON_QUEST,
		BALANCED_ENEMY_QUEST,
		15,
		dialog_array[5],
		2,
		false
	},
	{
		6,
		NONE_WEAPON_QUEST,
		NONE_ENEMY_QUEST,
		0,
		dialog_array[6],
		2,
		true
	},
	{
		7,
		SHOTGUN_WEAPON_QUEST,
		LIGHT_ENEMY_QUEST,
		25,
		dialog_array[7],
		2,
		false
	},
	{
		8,
		NONE_WEAPON_QUEST,
		NONE_ENEMY_QUEST,
		0,
		dialog_array[8],
		1,
		false
	},
	{
		9,
		NONE_WEAPON_QUEST,
		NONE_ENEMY_QUEST,
		0,
		NULL,
		0,
		false
	}
};

quest_t *init_quest(void);
