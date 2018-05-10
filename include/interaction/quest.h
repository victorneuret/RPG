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

typedef struct quest {
	uint8_t quest_id;
	uint8_t diag_elem;
	char **dialog;
	sfText *text;
	bool state;
} quest_t;

typedef struct {
	uint8_t quest_id;
	uint8_t diag_elem;
	char **dialog;
	bool state;
} quest_declaration_t;

#include "dialog_array.h"

static const quest_declaration_t quest_declaration[] = {
	{
		0,
		3,
		dialog_array[0],
		false
	},
	{
		1,
		3,
		dialog_array[1],
		false
	},
	{
		2,
		0,
		NULL,
		false
	}
};

quest_t *init_quest(void);
